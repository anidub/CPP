#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.
Return the shortest such subarray and output its length.
Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/discuss/103081/C%2B%2B-O(n)-solution
 */
//O(n)
int findUnsortedArray(vector<int>& nums) {
	if(nums.empty()) return 0;
	int left = 0, right = nums.size() - 1;
	int shortest = 0;

	while(left < right && nums[left] <= nums[left+1]) left++;
	if(left == nums.size() - 1) return 0;

	while(right > left && nums[right] >= nums[right-1]) right--;

	if(left < right) {
		int vmax = INT_MIN, vmin = INT_MAX;
		for(int i = left; i <= right; i++) {
			vmax = max(vmax, nums[i]);
			vmin = min(vmin, nums[i]);
		}
		while(left >= 0 && nums[left] > vmin) left--;
		while(right < nums.size() && nums[right] < vmax) right++;
		shortest = right - left - 1;
	}
	return shortest;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(6);nums.push_back(4);nums.push_back(8);
	nums.push_back(10);nums.push_back(9);nums.push_back(15);
	cout << findUnsortedArray(nums) << endl;
	return 0;
}*/
