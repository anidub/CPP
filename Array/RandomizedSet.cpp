#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/insert-delete-getrandom-o1/
 *
 * Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.


Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
 * https://leetcode.com/problems/insert-delete-getrandom-o1/discuss/410249/Easy-to-understand-C%2B%2B-Solution
 */
class RandomizedSet {
public:
	unordered_map<int, int> valToIndex;
	vector<int> values;
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if(valToIndex.find(val) != valToIndex.end())
			return false;
		int index = values.size();
		valToIndex[val] = index;
		values.push_back(val);
		return true;
	}

	 /** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		auto itr = valToIndex.find(val);
		if(itr == valToIndex.end())
			return false;
		int index = itr->second;
		int lastIndex = values.size()-1;

		if(index != lastIndex) {
			values[index] = values.back();
			valToIndex[values.back()] = index;
		}
		values.pop_back();
		valToIndex.erase(itr);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return values[rand() % values.size()];
	}

};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
