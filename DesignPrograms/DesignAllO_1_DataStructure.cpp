#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <list>
#include <iterator>

using namespace std;
/*https://leetcode.com/problems/all-oone-data-structure/
 * Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".

https://leetcode.com/problems/all-oone-data-structure/discuss/616577/Simple-C%2B%2B-solution
https://leetcode.com/problems/all-oone-data-structure/discuss/91398/C%2B%2B-solution-with-comments

https://leetcode.com/problems/all-oone-data-structure/discuss/91400/All-in-O(1)-with-detailed-explantation
 *
 */
class Node {
public:
    int freq;
    Node* prev;
    Node* next;
    unordered_set<string> keys;

    Node(int freq) : freq(freq), prev(nullptr), next(nullptr) {}
};

class AllOne {
private:
    Node* head;                        // Dummy head
    Node* tail;                        // Dummy tail
    unordered_map<string, Node*> map;  // Mapping from key to its node

public:
    // Initialize your data structure here.
    AllOne() {
        head = new Node(0);  // Create dummy head
        tail = new Node(0);  // Create dummy tail
        head->next = tail;   // Link dummy head to dummy tail
        tail->prev = head;   // Link dummy tail to dummy head
    }

    // Inserts a new key <Key> with value 1. Or increments an existing key by 1.
    void inc(string key) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            int freq = node->freq;
            node->keys.erase(key);  // Remove key from current node

            Node* nextNode = node->next;
            if (nextNode == tail || nextNode->freq != freq + 1) {
                // Create a new node if next node does not exist or freq is not freq + 1
                Node* newNode = new Node(freq + 1);
                newNode->keys.insert(key);
                newNode->prev = node;
                newNode->next = nextNode;
                node->next = newNode;
                nextNode->prev = newNode;
                map[key] = newNode;
            } else {
                // Increment the existing next node
                nextNode->keys.insert(key);
                map[key] = nextNode;
            }

            // Remove the current node if it has no keys left
            if (node->keys.empty()) {
                removeNode(node);
            }
        } else {  // Key does not exist
            Node* firstNode = head->next;
            if (firstNode == tail || firstNode->freq > 1) {
                // Create a new node
                Node* newNode = new Node(1);
                newNode->keys.insert(key);
                newNode->prev = head;
                newNode->next = firstNode;
                head->next = newNode;
                firstNode->prev = newNode;
                map[key] = newNode;
            } else {
                firstNode->keys.insert(key);
                map[key] = firstNode;
            }
        }
    }

    // Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
    void dec(string key) {
        if (map.find(key) == map.end()) {
            return;  // Key does not exist
        }

        Node* node = map[key];
        node->keys.erase(key);
        int freq = node->freq;

        if (freq == 1) {
            // Remove the key from the map if freq is 1
            map.erase(key);
        } else {
            Node* prevNode = node->prev;
            if (prevNode == head || prevNode->freq != freq - 1) {
                // Create a new node if the previous node does not exist or freq is not freq - 1
                Node* newNode = new Node(freq - 1);
                newNode->keys.insert(key);
                newNode->prev = prevNode;
                newNode->next = node;
                prevNode->next = newNode;
                node->prev = newNode;
                map[key] = newNode;
            } else {
                // Decrement the existing previous node
                prevNode->keys.insert(key);
                map[key] = prevNode;
            }
        }

        // Remove the node if it has no keys left
        if (node->keys.empty()) {
            removeNode(node);
        }
    }

    // Returns one of the keys with maximal value.
    string getMaxKey() {
        if (tail->prev == head) {
            return "";  // No keys exist
        }
        return *(tail->prev->keys.begin());  // Return one of the keys from the tail's previous node
    }

    // Returns one of the keys with minimal value.
    string getMinKey() {
        if (head->next == tail) {
            return "";  // No keys exist
        }
        return *(
            head->next->keys.begin());  // Return one of the keys from the head's next node
    }

private:
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;  // Link previous node to next node
        nextNode->prev = prevNode;  // Link next node to previous node

        delete node;  // Free the memory of the removed node
    }
};

/*
class AllOOne{
private:
	struct Bucket {
		int value;
		unordered_set<string> keys;
	};

	list<Bucket> buckets; //// double linked list for pair of (value, unordered_set of keys), sorted
	unordered_map<string, list<Bucket>::iterator> bucketOfKey;// hash map for mapping key to list iterator
public:
	void increment(string key) {
		if(!bucketOfKey.count(key))
			bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}}); // if key doesn't exist, insert one with value=0 into list, and update map

		auto itr = bucketOfKey[key];// get the iterator of list for the key
		auto itrNext = next(itr);// get the next iterator of itr

		if(itrNext == buckets.end() || itrNext->value > itr->value + 1) // here check if key is between two entries on update, it yes then update
			itrNext = buckets.insert(itrNext, {itr->value + 1, {}}); //update next with value + 1

		itrNext->keys.insert(key); //add key to that entry
		bucketOfKey[key] = itrNext; //point it to new key

		itr->keys.erase(key); // remove old entry
		if(itr->keys.empty())//if empty remove from buckets
			buckets.erase(itr);
	}

	void decrement(string key) {
		if(!bucketOfKey.count(key)) return;// if key doesn't exist, return

		auto itr = bucketOfKey[key];// get the iterator of the list for the key
		auto itrPrev = prev(itr);// get the previous iterator of itr
		bucketOfKey.erase(key);// remove key from hash map first

		if(itr->value > 1) {// here check if value on decrement if still more than 1
			if(itr == buckets.begin() || itr->value - 1 > itrPrev->value) // check if on update will be between two entries, it yes update
				itrPrev = buckets.insert(itr, {itr->value - 1});

			itrPrev->keys.insert(key);//add key to updated entry
			bucketOfKey[key] = itrPrev;// point to new entry
		}

		itr->keys.erase(key);// remove old entry
		if(itr->keys.empty())// if empty remove  fro, bucket
			buckets.erase(itr);

	}

	string getMaxKey() {
		return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin()); // return the last element of the list
	}

	string getMinKey() {
		return buckets.empty() ? "" : *(buckets.begin()->keys.begin());// return the first element of the list
	}

}; */
