#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/missing-element-in-sorted-array/
 * Given an integer array nums which is sorted in ascending order and all of its elements are unique and given also an integer k, return the kth missing number starting from the leftmost number of the array.
 * Input: nums = [4,7,9,10], k = 3
Output: 8
Explanation: The missing numbers are [5,6,8,...], hence the third missing number is 8.
https://leetcode.com/problems/missing-element-in-sorted-array/discuss/340931/c%2B%2B-O(log(n))-binary-search-with-explanation
 */

//TC: O(LogN), SC; O(1)
int missingElementSortedArray(vector<int>& nums, int k) {
	if(nums.empty()) return -1;

	int left = 0, right = nums.size();

	while(left < right){
		int mid = left + (right - left) / 2;
		int diff = (nums[mid] - mid) - nums[0];
		if(diff < k)
			left = mid + 1;
		else
			right = mid;
	}
	return right + nums[0] + k - 1;
}
/*
int main() {
	vector<int> nums = {4, 7, 9, 10};
	cout << missingElementSortedArray(nums,  3) << endl;

	return 0;
}
*/
