#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
 * Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
Example 1:

Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
 *
 * https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/discuss/108231/C%2B%2BJava-DP-with-explanation-O(n)
 * https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/discuss/108258/O(n)-C%2B%2B-Solution
 */
//O(N)
vector<int> maxSumThreeSuarrays(vector<int>& nums, int k) {
	if(nums.empty()) return {};
	int n = nums.size(), maxsum = 0;
	vector<int> sum = {0}, posLeft(n, 0), posRight(n, n-k), ans(3, 0);

	for(int& i : nums)
		sum.push_back(sum.back() + i);

	for(int i = k, tot = sum[k] - sum[0]; i < n; i++) {
		if(sum[i+1] - sum[i+1-k] > tot) {
			posLeft[i] = i+1-k;
			tot = sum[i+1] - sum[i+1-k];
		} else
			posLeft[i] = posLeft[i-1];
	}

	for(int i = n-k-1, tot = sum[n] - sum[n-k]; i >= 0; i--) {
		if(sum[i+k] - sum[i] >= tot) {
			tot = sum[i+k] - sum[i];
			posRight[i] = i;
		} else
			posRight[i] = posRight[i+1];
	}

	for(int i = k; i <= n-2*k; i++) {
		int l = posLeft[i-1], r = posRight[i+k];
		int tot = (sum[i+k] - sum[i]) + (sum[l+k] - sum[l]) + (sum[r+k] - sum[r]);
		if(tot > maxsum) {
			maxsum = tot;
			ans = {l, i, r};
		}
	}
	return ans;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(1);nums.push_back(2);nums.push_back(1);
	nums.push_back(2);nums.push_back(1);nums.push_back(2);nums.push_back(1);
	maxSumThreeSuarrays(nums, 2);

	return 0;
}*/
