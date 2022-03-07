#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_set>

using namespace std;
/*
 *Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
Example 1:
Input: [1,2,3,1]
Output: true
 * https://leetcode.com/problems/contains-duplicate/discuss/619056/C%2B%2B-or-Easy
 * https://leetcode.com/problems/contains-duplicate/discuss/61129/C%2B%2B-using-unordered_set-and-C-using-HashSet
 */

bool containsDup(vector<int>& nums) {
	if(nums.size() == 0) return false;
	unordered_set<int> set(nums.begin() != nums.end());
	return set.size() != nums.size();
}

bool contailsDupSetIterator(vector<int>& nums) {
	if(nums.size() == 0) return false;
	unordered_set<int> set;
	pair<unordered_set<int>::iterator, bool> result;
	for(int i : nums) {
		result = set.insert(i);
		if(result.second == false)
			return true;
	}
	return false;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(3);nums.push_back(1);
	cout << containsDup(nums) << endl;
	cout << contailsDupSetIterator(nums) << endl;

	return 0;
}*/
