#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
 * Given an array of positive integers arr,  find a pattern of length m that is repeated k or more times.
 * A pattern is a subarray (consecutive sub-sequence) that consists of one or more values, repeated multiple times consecutively without overlapping. A pattern is defined by its length and the number of repetitions.
Return true if there exists a pattern of length m that is repeated k or more times, otherwise return false.
Example 1:
Input: arr = [1,2,4,4,4,4], m = 1, k = 3
Output: true
Explanation: The pattern (4) of length 1 is repeated 4 consecutive times. Notice that pattern can be repeated k or more times but not less.
Example 2:

Input: arr = [1,2,1,2,1,1,1,3], m = 2, k = 2
Output: true
Explanation: The pattern (1,2) of length 2 is repeated 2 consecutive times. Another valid pattern (2,1) is also repeated 2 times.

https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/discuss/840289/C%2B%2B-oror-2-Solutions-oror-4-ms-Solution-oror-Easy-to-undestand
https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/discuss/930844/C%2B%2B
 */

bool detectPattern(vector<int>& nums, int m, int k) {
	int matchdigits = 0;
	for(int i = 0; i < nums.size()-m; i++) {
		matchdigits = nums[i] != nums[i+m] ? 0 : matchdigits + 1;
		if(matchdigits == (k-1)*m)
			return true;
	}
	return false;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(1);nums.push_back(2);
	nums.push_back(1);nums.push_back(1);nums.push_back(1);nums.push_back(3);
	cout << detectPattern(nums, 2, 2) << endl;

	return 0;
}*/
