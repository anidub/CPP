#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/405038/Easy-to-understand-C%2B%2B-Solution-0ms-beats-100
 */
// O(LogN)
vector<int> searchRangeFirstLastPosition(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int start = -1, end = -1;

    while(low <= high) {
    	int mid = low + (high - low)/2;
    	if(nums[mid] == target) {
    		if(mid == 0 || nums[mid-1] < nums[mid]) {
				start = mid;
				break;
			} else
				high = mid-1;
    	} else if(target > nums[mid])
    		low = mid+1;
    	else
    		high = mid-1;
    }

    low = 0;
    high = nums.size()-1;

    while(low <= high) {
    	int mid = low + (high-low)/2;
    	if(nums[mid] == target) {
    		if(mid == nums.size()-1 || nums[mid+1] > nums[mid]) {
    			end = mid;
    			break;
    		} else
    			low = mid+1;
    	} else if(target > nums[mid])
    		low = mid+1;
    	else
    		high = mid-1;
    }
    return {start, end};
}

//using stl
vector<int> searchRangeUsingSTL(vector<int>& nums, int target) {
	vector<int> result(2, -1);
	if(nums.empty()) return result;

	if(find(nums.begin(), nums.end(), target) != nums.end()) {
		auto it = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
		auto it1 = upper_bound(nums.begin(), nums.end(), target) - nums.end();
		it -= 1;

		result[0] = it;
		result[1] = it1;
	}
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(5);nums.push_back(7);nums.push_back(7);
	nums.push_back(8);nums.push_back(8);nums.push_back(10);
	searchRangeFirstLastPosition(nums, 8);

	return 0;
}*/
