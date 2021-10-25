#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/find-pivot-index/
 * Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.
Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
https://leetcode.com/problems/find-pivot-index/discuss/759381/C%2B%2B-oror-89.13-oror-Easy-to-understand
https://leetcode.com/problems/find-pivot-index/discuss/109274/JavaC%2B%2B-Clean-Code
 */
int pivotIndex(vector<int>& nums) {
	if(nums.size() == 0) return -1;
	if(nums.size() == 1) return 0;

	int leftSum = 0;
	int rightSum = accumulate(nums.begin(), nums.end(), 0);

	for(int i = 0; i < nums.size(); i++) {
		rightSum -= nums[i]; //27 20 17 11
		if(leftSum == rightSum)
			return i;
		leftSum += nums[i];//1 8 11
	}
	return -1;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(7);nums.push_back(3);
	nums.push_back(6);nums.push_back(5);nums.push_back(6);
	cout << pivotIndex(nums) << endl;
	return 0;
}*/
