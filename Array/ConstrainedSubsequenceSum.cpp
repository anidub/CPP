#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/constrained-subsequence-sum/
 * Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.
A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.
Example 1:
Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].
https://leetcode.com/problems/constrained-subsequence-sum/discuss/1402185/C%2B%2B-4-ways-(TLE-greaterTLE-greaterAccepted-greaterAccepted)
 */
//TC: O(N) S: O(N)
int contrainedSubsetSum(vector<int>& nums, int k) {
	if(nums.empty()) return 0;
	int n = nums.size();
	deque<int> dq;
	vector<int> t(nums);
	int maxR = t[0];

	for(int i = 0; i < n; i++) {

		while(!dq.empty() && dq.front() < i-k)
			dq.pop_front();

		if(!dq.empty())
			t[i] = max(t[i], nums[i] + t[dq.front()]);

		while(!dq.empty() && t[i] >= t[dq.back()])
			dq.pop_back();

		dq.push_back(i);
		maxR = max(maxR, t[i]);
	}
	return maxR;
}
/*
int main() {
	vector<int> nums; nums.push_back(10);nums.push_back(2);nums.push_back(-10);nums.push_back(5);nums.push_back(20);
	cout << contrainedSubsetSum(nums, 2) << endl;

	return 0;
}*/
