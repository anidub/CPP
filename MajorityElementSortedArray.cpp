#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * Given an array nums sorted in non-decreasing order, and a number target, return True if and only if target is a majority element.

A majority element is an element that appears more than N/2 times in an array of length N.

Example 1:

Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true
https://www.cnblogs.com/Dylan-Java-NYC/p/12076239.html
https://blog.csdn.net/fuxuemingzhu/article/details/100975902
https://www.geeksforgeeks.org/check-for-majority-element-in-a-sorted-array/
 */

bool majorityElementSorted(vector<int>& nums, int target) {
	if(nums.size() == 0) return false;
	int n = nums.size();
	int left = 0;
	int right = n - 1;

	while(left < right) {
		int mid = left + (right-left)/2;
		if(nums[mid] < target){
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	if(left + n/2 < nums.size() && nums[left + n/2] == target)
		return true;
	return false;
}
//Since a majority element occurs more than n/2 times in an array, it will always be the middle element.
bool majorityElementSortedOptimized(vector<int>& nums, int target) {
	if(nums.size() == 0) return false;
	int n = nums.size();
	if(nums[n/2] == target)
		return true;
	return false;
}

bool majorityElementSortedFunctions(vector<int>& nums, int target) {
	if(nums.size() == 0) return false;
	int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	int right = upper_bound(nums.begin(), nums.end(), target) - nums.end();

	if(left >= nums.size() || nums[left] != target) return false;
	return right - left > nums.size()/2;
}

/*
int main () {
	vector<int> nums;
	nums.push_back(2);nums.push_back(4);nums.push_back(5);nums.push_back(5);nums.push_back(5);
	nums.push_back(5);nums.push_back(5);nums.push_back(6);nums.push_back(6);

	cout << majorityElementSorted(nums, 5) << endl;
	cout << majorityElementSortedOptimized(nums, 5) << endl;
	cout << majorityElementSortedFunctions(nums, 5) << endl;


	return 0;
}*/
