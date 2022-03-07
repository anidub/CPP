#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/largest-number-at-least-twice-of-others/
 * In a given integer array nums, there is always exactly one largest element.
Find whether the largest element in the array is at least twice as much as every other number in the array.
If it is, return the index of the largest element, otherwise return -1.
Example 1:
Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 */
int dominantIndex(vector<int>& nums) {
	if(nums.size() == 0) return -1;
	int max_value = INT_MIN, max_index = 0;

	for(int i = 0; i < nums.size(); i++) {
		if(max_value < nums[i]) {
			max_value = nums[i];
			max_index = i;
		}
	}

	for(int& i : nums) {
		if(i != max_value && 2*i > max_value)
			return -1;
	}
	return max_index;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(3);nums.push_back(6);nums.push_back(1);nums.push_back(0);
	cout << dominantIndex(nums) << endl;
	return 0;
}*/
