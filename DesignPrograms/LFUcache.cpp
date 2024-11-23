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
/*https://leetcode.com/problems/lfu-cache/
 *Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present.
When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item.
For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache.
The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation).
The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

 Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

https://leetcode.com/problems/lfu-cache/discuss/94516/Concise-C%2B%2B-O(1)-solution-using-3-hash-maps-with-explanation comments: sandeepwww
 *
 *also check: https://leetcode.com/problems/lfu-cache/discuss/1697168/Using-priority_queue-c%2B%2B-clean-solution
 *also https://leetcode.com/problems/lfu-cache/discuss/919055/C%2B%2B-short-Solution-using-priority-queue
 *
 *C++ is not Java. new returns a pointer.
 */

class LFUcache {

public:
	size_t capacity;
	unordered_map<int, pair<int, int>> keyToValueFreq;// map of key, {val, freq}
	unordered_map<int, list<int>::iterator> keyToIter; //map of key -> iterator in freq list
	unordered_map<int, list<int>> freqToList; //map of frequency -> to list of keys
	int minFreq = 0;

public:
	LFUcache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if(!keyToValueFreq.count(key)) return -1;
		updateFrequency(key);
		return keyToValueFreq[key].first;
	}

	void put(int key, int value) {
		if(this->capacity <= 0) return;
		if(keyToValueFreq.count(key)) {
			updateFrequency(key);
			keyToValueFreq[key].first = value;
		} else {
			if(keyToValueFreq.size() == capacity) {
				int leastFreqElement = freqToList[minFreq].back();

				keyToValueFreq.erase(leastFreqElement);
				keyToIter.erase(leastFreqElement);

				freqToList[minFreq].pop_back();
				minFreq = 0;
			}

			keyToValueFreq[key] = {value, 0};
			freqToList[0].push_front(key);
			keyToIter[key] = freqToList[0].begin();
		}
	}
private:
	void updateFrequency(int key) {
		int freq = keyToValueFreq[key].second;
		keyToValueFreq[key].second++;

		freqToList[freq].erase(keyToIter[key]);
		freqToList[freq+1].push_front(key);

		keyToIter[key] = freqToList[freq+1].begin();

		if(freqToList[minFreq].empty()) {
			freqToList.erase(minFreq);
			minFreq++;
		}
	}
};

/*
int main() {
	LFUcache lRUCache(2);
	lRUCache.put(1, 1); // cache is {1=1}
	lRUCache.put(2, 2); // cache is {1=1, 2=2}
	cout << lRUCache.get(1) << endl;    // return 1
	lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
	lRUCache.get(2);    // returns -1 (not found)
	lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
	lRUCache.get(1);    // return -1 (not found)
	cout << lRUCache.get(3) << endl;    // return 3
	lRUCache.get(4);    // return 4  */
//-----------------------using new---------------------------------//
/*	LFUcache *lfu = new LFUcache(2);
	lfu->put(1, 1);   // cache=[1,_], cnt(1)=1
	lfu->put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
	lfu->get(1);      // return 1
	                 // cache=[1,2], cnt(2)=1, cnt(1)=2
	lfu->put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
	                 // cache=[3,1], cnt(3)=1, cnt(1)=2
	lfu->get(2);      // return -1 (not found)
	lfu->get(3);      // return 3
	                 // cache=[3,1], cnt(3)=2, cnt(1)=2
	lfu->put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
	                 // cache=[4,3], cnt(4)=1, cnt(3)=2
	lfu->get(1);      // return -1 (not found)
	cout << lfu->get(3) << endl;      // return 3
	                 // cache=[3,4], cnt(4)=1, cnt(3)=3
	lfu->get(4);      // return 4
	                 // cache=[4,3], cnt(4)=2, cnt(3)=3

	delete lfu;
	return 0;*/
//}
