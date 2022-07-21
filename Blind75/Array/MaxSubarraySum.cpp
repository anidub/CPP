#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/maximum-subarray/
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
 */
class MaxSubarraySum {
public:
	int maxSubarraySum(vector<int> &nums) {
		if(nums.empty()) return 0;
		int result = INT_MIN;
		int current = 0;

		for(int num : nums) {
			current = max(num, current + num);
			result = max(result, current);
		}
		return result;
	}
};
/*
int main() {
	MaxSubarraySum mss;
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	cout << mss.maxSubarraySum(nums) << endl;
	return 0;
}*/
