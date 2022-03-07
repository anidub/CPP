#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/search-insert-position/
 * Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
 * https://leetcode.com/problems/search-insert-position/discuss/15332/C%2B%2B-concise-solution.
 */
int searchInsert(vector<int>& nums, int target) {
	if(nums.size() == 0) return -1;

	int low = 0, high = nums.size() - 1;

	while(low <= high) {
		int mid = low + (high - low)/2;
		if(nums[mid] == target)
			return mid;
		else if(nums[mid] < target)
			low = mid+1;
		else
			high = mid-1;
	}
	return low;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(3);nums.push_back(5);nums.push_back(6);

	cout << searchInsert(nums, 2) << endl;
	return 0;
}
*/
