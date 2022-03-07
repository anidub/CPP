#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 *https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/
We have an array of integers, nums, and an array of requests where requests[i] = [starti, endi]. The ith request asks for the sum
of nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi]. Both starti and endi are 0-indexed.
Return the maximum total sum of all requests among all permutations of nums.
Since the answer may be too large, return it modulo 109 + 7.

Example 1:

Input: nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
Output: 19
Explanation: One permutation of nums is [2,1,3,4,5] with the following result:
requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
Total sum: 8 + 3 = 11.
A permutation with a higher total sum is [3,5,4,2,1] with the following result:
requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
Total sum: 11 + 8 = 19, which is the best that you can do.
https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/discuss/854206/JavaC%2B%2BPython-Sweep-Line
 */
//Time O(NlogN) for sorting,Space O(N)
int maxSumAnyPermutation(vector<int>& nums, vector<vector<int>>& r) {
	int n = nums.size();
	if(nums.empty()) return 0;
	vector<int> count(n, 0);
	int mod = 1e9+7; long sum = 0;

	for(int i = 0; i < r.size(); i++) {
		count[r[i][0]]++;
		if(r[i][1] + 1 < n)
			count[r[i][1] + 1]--;
	}

	for(int i = 1; i < n; i++) {
		count[i] += count[i-1];
	}

	sort(nums.begin(), nums.end());
	sort(count.begin(), count.end());

	for(int i = 0; i < n; i++) {
		sum += (long) count[i] * nums[i];
	}

	return sum % mod;
}
/*
int main() {
	vector<int> nums; nums.push_back(1);nums.push_back(2);nums.push_back(3);
	nums.push_back(4);nums.push_back(5);

	vector<vector<int>> requests;
	vector<int> r1; r1.push_back(1);r1.push_back(3);
	vector<int> r2; r2.push_back(0);r2.push_back(1);
	requests.push_back(r1); requests.push_back(r2);
	cout << maxSumAnyPermutation(nums, requests) << endl;

	return 0;
}*/
