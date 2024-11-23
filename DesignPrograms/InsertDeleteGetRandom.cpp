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
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
 * RandomizedCollection is a data structure that contains a collection of numbers, possibly duplicates (i.e., a multiset). It should support inserting and removing specific elements and also removing a random element.

Implement the RandomizedCollection class:

RandomizedCollection() Initializes the empty RandomizedCollection object.
bool insert(int val) Inserts an item val into the multiset, even if the item is already present. Returns true if the item is not present, false otherwise.
bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
int getRandom() Returns a random element from the current multiset of elements. The probability of each element being returned is linearly related to the number of same values the multiset contains.
You must implement the functions of the class such that each function works on average O(1) time complexity.
Input
["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
[[], [1], [1], [2], [], [1], []]
Output
[null, true, false, true, 2, true, 1]

Explanation
RandomizedCollection randomizedCollection = new RandomizedCollection();
randomizedCollection.insert(1);   // return true since the collection does not contain 1.
                                  // Inserts 1 into the collection.
randomizedCollection.insert(1);   // return false since the collection contains 1.
                                  // Inserts another 1 into the collection. Collection now contains [1,1].
randomizedCollection.insert(2);   // return true since the collection does not contain 2.
                                  // Inserts 2 into the collection. Collection now contains [1,1,2].
randomizedCollection.getRandom(); // getRandom should:
                                  // - return 1 with probability 2/3, or
                                  // - return 2 with probability 1/3.
randomizedCollection.remove(1);   // return true since the collection contains 1.
                                  // Removes 1 from the collection. Collection now contains [1,2].
randomizedCollection.getRandom(); // getRandom should return 1 or 2, both equally likely.

https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/discuss/85541/C%2B%2B-128ms-Solution-Real-O(1)-Solution
https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/discuss/1708946/C%2B%2B-solution-using-Vector-and-Unordered-map! : well explained
 */
//TC: O(1), SC:O(N)

class RandomizedCollection {
unordered_map<int, vector<int>> mp; //store indices // value, {indices}
vector<pair<int, int>> nums; // store elements // value, index of mp[value]

public:
    RandomizedCollection() {

    }

    bool insert(int val) {
    	auto result = mp.find(val) == mp.end();

    	mp[val].push_back(nums.size());
    	nums.push_back({val, mp[val].size() - 1});
    	return result;
    }

    bool remove(int val) {
    	auto result = mp.find(val) != mp.end();
    	if(result) {
    		auto last = nums.back();
    		mp[last.first][last.second] = mp[val].back();
    		nums[mp[val].back()] = last;
    		mp[val].pop_back();
    		if(mp[val].empty()) mp.erase(val);
    		nums.pop_back();
    	}
    	return result;
    }

    int getRandom() {
    	return nums[rand() % nums.size()].first;
    }
};
/*
int main() {
	RandomizedCollection* obj = new RandomizedCollection();
	cout << obj->insert(1) << endl;
	cout << obj->insert(1) << endl ;
	cout << obj->insert(2) << endl ;
	cout << obj->getRandom() << endl ;
	cout << obj->remove(1) << endl;
	cout << obj->getRandom() << endl ;

	delete obj;
	return 0;
}
*/
