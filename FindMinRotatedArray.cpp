#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/1011003/C%2B%2B-binary-search
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/48493/Compact-and-clean-C%2B%2B-solution used
when do you use while (start<end) , when do you use while (start<=end)?
when you want to find an specific target element you use lo <= hi.
When you want to find an element which is not specific element you use lo <hi. for example when you want to find a smallest element or a lower_bound etc.
In other words, reduce search space by every step.And the remaining last element is your answer.
 */

// O(logn)
int findMinRotatedArray(vector<int>& nums) {
	if(nums.empty()) return -1;

	int left = 0, right = nums.size()-1;
	while(left < right) {
		if(nums[left] < nums[right])
			return nums[left];
		int mid = left + (right - left)/2;
		if(nums[left] <= nums[mid])
			left = mid+1;
		else
			right = mid;
	}
	return nums[left];
}
/*
int main() {
	vector<int> nums;
	nums.push_back(3);nums.push_back(4);nums.push_back(5);nums.push_back(1);nums.push_back(2);
	cout << findMinRotatedArray(nums) << endl;

	return 0;
}
*/
