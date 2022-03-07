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
 * https://leetcode.com/problems/continuous-subarray-sum/
 * Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
Example 1:
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
https://leetcode.com/problems/continuous-subarray-sum/discuss/797279/C%2B%2B-Solution-oror-O(n)-oror-unordered_map
 */
//Time: O(n), Space : O(n)
bool checkSubarraySum(vector<int>& nums, int k) {
	if(nums.empty() || nums.size() < 2) return false;
	unordered_map<int, int> mp; int sum = 0;
	k = k == 0 ? INT_MAX : k;
	mp[0] = -1;

	for(int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if(mp.find(sum % k) != mp.end()) {
			if(i - mp[sum % k] > 1)
				return true;
		} else {
			mp[sum % k] = i;
		}
	}
	return false;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(23);nums.push_back(2);nums.push_back(4);nums.push_back(6);nums.push_back(7);
	cout << checkSubarraySum(nums, 6) << endl;
}*/
