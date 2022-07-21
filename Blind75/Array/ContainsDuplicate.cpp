#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/contains-duplicate/
 *Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 *Given Input: nums = [1,2,3,1]
Output: true
 */
class ContainsDuplicate {
public:
	//TC:O(N), SC:O(N)
	bool containsDuplicate(vector<int> &nums) {
		if(nums.empty()) return false;
		unordered_set<int> st(nums.begin(), nums.end());
		return st.size() != nums.size();
	}

};
/*
int main() {
	ContainsDuplicate ts;

	vector<int> nums = {2, 7 , 11, 2};
	cout << ts.containsDuplicate(nums);
	return 0;
}
*/
