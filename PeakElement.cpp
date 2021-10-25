#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/find-peak-element/
 * A peak element is an element that is strictly greater than its neighbors.
Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -infinity.
You must write an algorithm that runs in O(log n) time.
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
https://leetcode.com/problems/find-peak-element/discuss/50376/Simple-8-ms-C%2B%2B-Solution-Using-Binary-Search
 */

//O(NLOGN)
int findPeakElement(vector<int>& nums) {
	if(nums.empty()) return -1;

	int left = 0, right = nums.size()-1;
	while(left < right) {
		int mid = (left + right)/2;
		if(nums[mid] < nums[mid+1])
			left = mid + 1;
		else
			right = mid;
	}
	return right;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);nums.push_back(1);
	cout << findPeakElement(nums) << endl;
	return 0;
}*/
