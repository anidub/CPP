#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/max-consecutive-ones-iii/
 * Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
 *
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Translation:
Find the longest subarray with at most K zeros.

https://leetcode.com/problems/max-consecutive-ones-iii/discuss/692111/Simple-C%2B%2B-explanation-for-easy-understanding-%3A-O(n)-time-and-O(1)-space
 */
//TC: O(N), SC : O(1)
int longestOnesSeries(vector<int> &nums, int k) {
	if(nums.empty()) return 0;
	int start = 0, maxWin = 0, zerocounter = 0;

	for(int end = 0; end < nums.size(); end++) {
		if(nums[end] == 0) zerocounter++;

		while(zerocounter > k) {
			if(nums[start] == 0)
				zerocounter--;
			start++;
		}
		maxWin = max(maxWin, end - start + 1);
	}
	return maxWin;
}
/*
int main() {
	vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
	cout << longestOnesSeries(nums, 2) << endl;

	return 0;
}*/
