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

};
