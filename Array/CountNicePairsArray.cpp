#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/count-nice-pairs-in-an-array/
 * You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:
0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.
Example 1:
Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
 https://leetcode.com/problems/count-nice-pairs-in-an-array/discuss/1140639/JavaC%2B%2BPython-Straight-Forward
 Time O(nloga) : loga for reverse a number a, n = size of array
Space O(n)
 */
int rev(int a) {
	int b = 0;
	while(a > 0) {
		b = b * 10 + a%10;
		a = a/10;
	}
	return b;
}

int countNicePairs(vector<int>& nums) {
	if(nums.empty()) return 0;
	unordered_map<int, int> count;
	int result = 0, mod = 1e9 + 7;

	for(int& n : nums) {
		result = (result + count[n - rev(n)]++) % mod;
	}
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(42);nums.push_back(11);nums.push_back(1);nums.push_back(97);
	cout << countNicePairs(nums) << endl;

	return 0;
}
*/
