#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/minimum-size-subarray-sum/
 * Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
https://leetcode.com/problems/minimum-size-subarray-sum/discuss/619044/C%2B%2B-or-Sliding-window : used
https://leetcode.com/problems/minimum-size-subarray-sum/discuss/433123/JavaC%2B%2BPython-Sliding-Window
 */
//Time O(N) Space O(1)
int minSubarrayLen(int target, vector<int>& nums) {
	if(nums.empty()) return 0;
	int n = nums.size(), j = 0;
	int result = INT_MAX, sum = 0;

	for(int i = 0l; i < n; i++) {
		sum += nums[i];
		while(j < n && sum >= target) {
			result = min(result, i - j + 1);
			sum = sum - nums[j];
			j++;
		}
	}
	return result == INT_MAX ? 0 : result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(3);nums.push_back(1);
	nums.push_back(2);nums.push_back(4);nums.push_back(3);

	cout << minSubarrayLen(7, nums) << endl;

	return 0;
}
*/
