#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <stack>
#include <utility>
#include <list>
#include <iterator>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/lru-cache/
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

https://leetcode.com/problems/lru-cache/discuss/792449/Simple-C%2B%2B-Solution-with-Detailed-Explanation-%3A-

https://www.geeksforgeeks.org/list-splice-function-in-c-stl/
https://www.cplusplus.com/reference/list/list/splice/

splice TC : constant in our case, if passing range then o(n) or linear

If you want it on the stack
LRUcache n(10, 10); : The object will be made on the stack. It goes out of scope at the end of the function, or even before it (for instance if it was declared in a loop).

If you want it on the heap
LRUcache *n = new LRUcache(10, 10); :The object is allocated on the heap, and a pointer to it is on the stack. It behaves more you'd expect it with Java's "references". The object will not be deleted when the pointer goes out of scope. Instead, delete has to be called at some point or else the memory will be leaked (unlike with Java's "references", which are garbage collected).


Better yet, use a smart pointer and never call new and delete.
https://leetcode.com/problems/lru-cache/discuss/1461942/C%2B%2Boror-Detailed-Solution-ororwith-DRY-RUN USED
 */
/*
class LRUcache {

	size_t size;
	list<pair<int, int>> m_list;
	unordered_map<int, list<pair<int, int>>::iterator> m_map;

public:
	LRUcache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		if(m_map.find(key) == m_map.end()) return -1;
		m_list.splice(m_list.begin(), m_list, m_map[key]);
		return m_map[key]->second;
	}

	void put(int key, int value) {
		if(m_map.find(key) != m_map.end()) {
			m_list.splice(m_list.begin(), m_list, m_map[key]);
			m_map[key]->second = value;
			return;
		}
		if(m_list.size() == size) {
			int first = m_list.back().first;
			m_list.pop_back();
			m_map.erase(first);
		}
		m_list.push_front({key, value});
		m_map[key] = m_list.begin();
	}
}; */

//Time complexity : O(1) both for put and get.
//space complexity:O(capacity) since the space is used only for a hashmap and double linked list with at most capacity + 1 elements.
class LRUCache {
public:
	class Node {
	public:
		int key;
		int value;
		Node* next;
		Node* prev;
		Node(int key, int value) {
			this->key = key;
			this->value = value;
			this->next = nullptr, this->prev = nullptr;
		}
	};

	Node* head = new Node(0, 0);
	Node* tail = new Node(0, 0);
	unordered_map<int, Node*> mp;
	int capacity;

	LRUCache(int capacity) {
		this->capacity = capacity;
		head->next = tail;
		tail->prev = head;
	}

	void insert(Node* curNode) {
		curNode->next = head->next;
		head->next->prev = curNode;
		head->next = curNode;
		curNode->prev = head;
		mp[curNode->key] = curNode;
	}

	void remove(Node* curNode){
		mp.erase(curNode->key);
		curNode->next->prev = curNode->prev;
		curNode->prev->next = curNode->next;
	}

	int get(int key) {
		if(mp.find(key) == mp.end())
			return -1;
		Node* curNode = mp[key];
		remove(curNode);
		insert(curNode);
		return curNode->value;
	}

	void put(int key, int value) {
		if(mp.find(key) != mp.end())
			remove(mp[key]);
		if(mp.size() == capacity)
			remove(tail->prev);

		insert(new Node(key, value));
	}
};


int main() {
	LRUCache lRUCache(2);
	lRUCache.put(1, 1); // cache is {1=1}
	lRUCache.put(2, 2); // cache is {1=1, 2=2}
	cout << lRUCache.get(1) << endl;    // return 1
	lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
	lRUCache.get(2);    // returns -1 (not found)
	lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
	lRUCache.get(1);    // return -1 (not found)
	cout << lRUCache.get(3) << endl;    // return 3
	cout << lRUCache.get(4) << endl;;    // return 4

	return 0;
}

