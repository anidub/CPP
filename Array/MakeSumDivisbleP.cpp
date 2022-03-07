#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 *https://leetcode.com/problems/make-sum-divisible-by-p/
 *Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.



Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4],
and the sum of the remaining elements is 6, which is divisible by 6.
https://leetcode.com/problems/make-sum-divisible-by-p/discuss/854197/JavaC%2B%2BPython-Prefix-Sum
 */
//Time O(N) Space O(N)
int minSubArrayMakeDivisibleByP(vector<int>& nums, int p) {
	if(nums.empty()) return 0;
	const int n = nums.size();
	int total = 0;
	for(int i = 0; i < n; i++)
		total = (total + nums[i]) % p;

	if(total == 0) return 0;
	unordered_map<int, int> mp;
	mp[0] = -1;
	int result = INT_MAX;
	int prefixSum = 0;

	for(int i = 0; i < n; i++) {
		prefixSum = (prefixSum + nums[i]) % p;
		mp[prefixSum] = i;
		int key = (prefixSum + p - total) % p;
		if(mp.count(key) > 0)
			result = min(result, i - mp[key]);
	}
	return result == n ? -1 : result;
}
/*
int main() {
	vector<int> nums; nums.push_back(3);nums.push_back(1);nums.push_back(4);nums.push_back(2);
	cout << minSubArrayMakeDivisibleByP(nums, 6) << endl;
	return 0;
}
*/
