#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>

using namespace std;
/* *Leetcode 1121. divide the array into several increasing sequences
 *Given a non-decreasing array of positive integers nums and an integer K, find out if this array can be divided into one or more disjoint increasing subsequences of length at least K.

Example 1:
Input: nums = [1,2,2,3,3,4,4], K = 3
Output: true
Explanation:
The array can be divided into the two subsequences [1,2,3,4] and [2,3,4] with lengths at least 3 each.
Example 2:

Input: nums = [5,6,6,7,8], K = 3
Output: false
Explanation: There is no way to divide the array using the conditions required.

Note:
1 <= nums.length <= 10^5
1 <= K <= nums.length
1 <= nums[i] <= 10^5
https://www.programmersought.com/article/60548066661/
https://www.youtube.com/watch?v=hQfGfvPFyqo : used
The idea is that get the max occuring variable. The cout of this variable will tell us how many groups it will go into. If the num of groups
multiply by k is less than nums.size() return true;
 */
//Time: O(n)
bool canDivideIntoIncreasingSubsequences(vector<int>& nums, int k) {
	if(nums.empty()) return false;
	int groups = 0, localCount = 0, pre = -1;
	for(int& i : nums) {
		localCount =  i == pre ? localCount + 1 : 1;
		pre = i;
		groups = max(groups, localCount);
	}
	return nums.size() >= groups * k;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(2);
	nums.push_back(3);nums.push_back(3);nums.push_back(4);nums.push_back(4);
	cout << canDivideIntoIncreasingSubsequences(nums, 3) << endl;

	return 0;
}*/
