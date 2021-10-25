#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/maximum-score-of-a-good-subarray/submissions/
 * You are given an array of integers nums (0-indexed) and an integer k.
The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.
Return the maximum possible score of a good subarray.
Example 1:

Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15.
https://leetcode.com/problems/maximum-score-of-a-good-subarray/discuss/1108333/JavaC%2B%2BPython-Two-Pointers
 */
//Time O(n) Space O(1)
int maxScoreGoodSubarray(vector<int>& nums, int k)  {
	int n = nums.size(), i = k, j = k, mini = nums[k], res = nums[k];

	while(i > 0 || j < n-1) {
		if( (i > 0 ? nums[i-1] : 0) < (j < n-1 ? nums[j+1] : 0)){
			j++;
			mini = min(mini, nums[j]);
		} else {
			i--;
			mini = min(mini, nums[i]);
		}
		res = max(res, mini * (j-i+1));
	}
	return res;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(4);nums.push_back(3);
	nums.push_back(7);nums.push_back(4);nums.push_back(5);
	cout << maxScoreGoodSubarray(nums, 3) << endl;

	return 0;
}*/
