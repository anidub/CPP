#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/global-and-local-inversions/
 * You are given an integer array nums of length n which represents a permutation of all the integers in the range [0, n - 1].

The number of global inversions is the number of the different pairs (i, j) where:

0 <= i < j < n
nums[i] > nums[j]
The number of local inversions is the number of indices i where:

0 <= i < n - 1
nums[i] > nums[i + 1]
Return true if the number of global inversions is equal to the number of local inversions.
Example 1:
Input: nums = [1,0,2]
Output: true
Explanation: There is 1 global inversion and 1 local inversion.
https://www.youtube.com/watch?v=vFH3zrUbvD4 : used
 */
//O(N)
bool isIdealGlobalLocalInversion(vector<int>& nums) {
	if(nums.empty()) return false;
	if(nums.size() == 1) return true;
	int max_ele = -1;
	for(int i = 0; i < nums.size() - 2; i++) {
		max_ele = max(max_ele, nums[i]);
		if(max_ele > nums[i+2]) return false;
	}
	return true;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(0);
	nums.push_back(5);nums.push_back(3);nums.push_back(4);
	cout << isIdealGlobalLocalInversion(nums) << endl;

	return 0;
}*/
