#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:
[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
You must decrease the overall operation steps as much as possible.

Input: nums = [2,2,2,0,1]
Output: 0
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/48883/C%2B%2B-binary-%2B-linear-search
 */
//TC: LOGN
int findMinRotatedSortedArray(vector<int>& nums) {
	if(nums.empty()) return -1;

	int left = 0, right = nums.size() - 1;
	while(left < right) {
		int mid = left + (right - left)/2;
		if(nums[mid] > nums[right])
			left = mid+1;
		else if(nums[mid] < nums[right])
			right = mid;
		else
			right--;
	}

	return nums[left];
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(2);nums.push_back(2); nums.push_back(0);nums.push_back(1);
	cout << findMinRotatedSortedArray(nums) << endl;

	return 0;
}*/
