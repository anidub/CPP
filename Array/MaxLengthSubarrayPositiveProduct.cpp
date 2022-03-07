#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
 * Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.
Input: nums = [0,1,-2,-3,-4]
Output: 3
Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.

https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/discuss/824426/Fully-Explained-Solution-oror-Using-simple-concept-of-odd-and-even-oror-O(n)-Solution

Soln:
We shouldn't include 0 in the subarray. So we just handle each of the subarrays surrounded by 0s.
If there are even number of negative numbers in the subarray, the entire subarray has a positive product.
If there are odd number of negative numbers in the subarray, we have two candidates:
From the first element of the subarray to the element before the last negative element
From the next element of first negative element to the last element of the subarray.
 */

//TC: O(n), SC: O(1)
int getMaxLengthSubarrayPositiveProduct(vector<int>& nums) {
	int mx = 0;
	for(int i = 0; i < nums.size(); i++) {
		int negativeCount = 0, positiveCount = 0, firstNegative = -1, lastNegative = -1, j;

		for(j = i; j < nums.size(); j++) {
			if(nums[j] < 0)
				negativeCount++;
			else if(nums[j] > 0)
				positiveCount++;
			else
				break;

			if(nums[j] < 0 && firstNegative == -1)
				firstNegative = j;
			if(nums[j] < 0)
				lastNegative = j;
		}
		if(negativeCount % 2 == 0)
			mx = max(mx, negativeCount + positiveCount);
		else
			mx = max(mx, max(j - firstNegative - 1, lastNegative = i));
		i = j;
	}
	return mx;
}
/*
int main() {
	vector<int> nums = {0, 1, -2, 3, -4};
	cout << getMaxLengthSubarrayPositiveProduct(nums) << endl;
	return 0;
}*/
