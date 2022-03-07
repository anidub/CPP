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

using namespace std;
/*https://leetcode.com/problems/design-hashmap/
 * Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]


https://leetcode.com/problems/design-hashmap/discuss/638205/C%2B%2B-Standard-HashMap-Implementation-with-Chaining-and-Rehashing : concept
https://leetcode.com/problems/design-hashmap/discuss/462414/C%2B%2B-Elegant-solution-with-collision-handling : implementation


https://leetcode.com/problems/design-hashmap/discuss/1097755/JS-Python-Java-C%2B%2B-or-(Updated)-Hash-and-Array-Solutions-w-Explanation : using custom linkedlist
https://leetcode.com/problems/design-hashmap/discuss/326081/cpp-solution-with-Linked-List : custom linkeded list

https://leetcode.com/problems/design-hashmap/discuss/415635/C%2B%2B-Cuckoo-Hashing : cuckoo hashing
 */

class HashMap{
vector<list<pair<int, int>>> buckets;
int numElements;
public:
	HashMap() {
		numElements = 0;
		buckets.resize(20);
	}

	void put(int key, int value) {
		if((double)numElements / buckets.size() > 0.5) grow();

		int index = key % buckets.size();
		list<pair<int, int>> &row = buckets[index];
		for(auto iter = row.begin(); iter != row.end(); iter++) {
			if(iter->first == key){
				iter->second = value;
				return;
			}
		}
		++numElements;
		row.push_back(make_pair(key, value));
	}

	int get(int key) {
		int index = key % buckets.size();
		list<pair<int, int>> &row = buckets[index];
		for(auto iter = row.begin(); iter != row.end(); iter++) {
			if(iter->first == key)
				return iter->second;
		}
		return -1;
	}

	void remove(int key) {
		int index = key % buckets.size();
		list<pair<int, int>> &row = buckets[index];
		for(auto iter = row.begin(); iter != row.end(); iter++) {
			if(iter->first == key) {
				row.erase(iter);
				--numElements;
				return;
			}
		}
	}

	void grow() {
		vector<list<pair<int, int>>> temp;
		temp.resize(buckets.size());
		buckets.swap(temp);
		buckets.resize(temp.size() * 2);
		numElements = 0;
		for(auto entries : temp) {
			auto it = entries.begin();
			while(it != entries.end()) {
				put(it->first, it->second);
				it++;
			}
		}
	}
};
/*
int main() {
	HashMap *myHashMap = new HashMap();
	myHashMap->put(1, 1); // The map is now [[1,1]]
	myHashMap->put(2, 2); // The map is now [[1,1], [2,2]]
	myHashMap->get(1);    // return 1, The map is now [[1,1], [2,2]]
	myHashMap->get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
	myHashMap->put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
	myHashMap->get(2);    // return 1, The map is now [[1,1], [2,1]]
	myHashMap->remove(2); // remove the mapping for 2, The map is now [[1,1]]
	cout << myHashMap->get(2) << endl;    // return -1 (i.e., not found), The map is now [[1,1]]
	delete myHashMap;

	return 0;
}*/
