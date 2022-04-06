#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/contiguous-array/
 * Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1
 * Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
https://leetcode.com/problems/contiguous-array/discuss/1743637/C%2B%2B-with-Explanation-oror-Easy-to-Understand-oror-Unordered_Map
 */
//Time Complexity O(n) Space: O(n) : used
int findMaxLengthLongestSubarrayOptimal(vector<int> &nums) {
	if(nums.empty()) return 0;
	unordered_map<int, int> mp; mp[0] = -1;
	int longest_subarray = 0, sum = 0;

	for(int i = 0; i < nums.size(); i++) {
		sum += nums[i] == 0 ? -1 : 1;
		if(mp.find(sum) != mp.end()) {
			if(longest_subarray < i - mp[sum])
				longest_subarray = i - mp[sum];
		} else
			mp[sum] = i;
	}
	return longest_subarray;
}
//https://leetcode.com/problems/contiguous-array/discuss/1743431/A-highly-detailed-EXPLANATION-ever-exists-JavaC%2B%2B
//TC: O(N^2), SC: O(1)
int findMaxLength(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        int zeros = 0, ones = 0;
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] == 0) {
                zeros++;
            } else {
                ones++;
            }
            if (zeros == ones) {
                count = max(count, j - i + 1);
            }
        }
    }
    return count;
}
/*
int main() {
	vector<int> nums = {0,1,0};
	cout << findMaxLength(nums) << endl;
	cout << findMaxLengthLongestSubarrayOptimal(nums) << endl;

	return 0;
}
*/
