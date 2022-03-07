#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
 * Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's in the resulting array.
Return 0 if there is no such subarray.
Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/discuss/708300/C%2B%2B-or-Classic-sliding-window
https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/discuss/708112/JavaC%2B%2BPython-Sliding-Window-at-most-one-0

All sliding window problems:https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/discuss/708112/JavaC%2B%2BPython-Sliding-Window-at-most-one-0
 *
 */
int longestSubarrayAfterDelete(vector<int>& nums) {
	if(nums.empty()) return 0;

	int j = 0; int count = 0;
	int result = INT_MIN;

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] == 0)
			count++;

		while(j < nums.size() && count > 1){
			if(nums[j] == 0)
				count--;
			j++;
		}

		result = max(result, i-j+1);
	}
	return result == INT_MIN ? 0 : result - 1;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(0);nums.push_back(1);nums.push_back(1);nums.push_back(1);
	nums.push_back(0);nums.push_back(1);nums.push_back(1);nums.push_back(0);nums.push_back(1);

	cout << longestSubarrayAfterDelete(nums) << endl;
	return 0;
}*/
