#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <deque>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/subsets/
 *Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation

 */

void subsetUtil(vector<int>& nums, int i, vector<int> sub, vector<vector<int>>& result) {
	result.push_back(sub);
	for(int j = i; j < nums.size(); j++) {
		sub.push_back(nums[j]);
		subsetUtil(nums, j+1, sub, result);
		sub.pop_back();
	}
}
// O(n*2^n)
vector<vector<int>> subsets(vector<int>& nums) {
	if(nums.empty()) return {};
	vector<vector<int>> result;
	vector<int> sub;
	subsetUtil(nums, 0, sub, result);
	return result;
}

// O(n*2^n)
vector<vector<int>> subsetIterative(vector<int>& nums) {
	vector<vector<int>> result {{}};
	if(nums.empty()) return result;
	for(int num : nums) {
		int n = result.size();
		for(int i = 0; i < n; i++) {
			result.push_back(result[i]);
			result.back().push_back(num);
		}
	}
	return result;
}

/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);
	subsetIterative(nums);
	subsets(nums);

	return 0;
}
*/
