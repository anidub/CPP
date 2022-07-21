#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
 * Given an integer array nums and an integer k, return the maximum length of a subarray that sums to k. If there is not one, return 0 instead.
 * Input: nums = [1,-1,5,-2,3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/discuss/77793/O(n)-C%2B%2B-solution-using-unordered_map
 */
//TC: O(N), SC: O(N)
int maxSubarraySumEqualsK(vector<int> &nums, int k) {
	if(nums.empty()) return -1;

	unordered_map<int, int> mp;
	int cur = 0, max_len = 0;

	for(int i = 0; i < nums.size(); i++) {
		cur += nums[i];
		if(cur == k)
			max_len = i + 1;
		if(mp.find(cur - k) != mp.end())
			max_len = max(max_len, i - mp[cur - k]);

		if(mp.find(cur) == mp.end())
			mp[cur] = i;
	}
	return max_len;
}
/*
int main() {
	vector<int> nums = {1, -1, 5, -2, 3};
	cout << maxSubarraySumEqualsK(nums, 3) << endl;

	return 0;
}*/
