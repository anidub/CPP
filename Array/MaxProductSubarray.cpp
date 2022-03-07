#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/maximum-product-subarray/
 * Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
It is guaranteed that the answer will fit in a 32-bit integer.
A subarray is a contiguous subsequence of the array.
Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
https://leetcode.com/problems/maximum-product-subarray/discuss/453236/C%2B%2B-Solution-O(N)-Time-O(1)-Space
 */
//O(N)
int maxProductSubArray(vector<int>& nums) {
	if(nums.empty()) return 0;
	int curMaxProduct = nums[0];
	int curMinProduct = nums[0];
	int prevMaxProduct = nums[0];
	int prevMinProduct = nums[0];
	int result = nums[0];

	for(int i = 1; i < nums.size(); i++) {
		curMaxProduct = max(prevMaxProduct * nums[i], max(prevMinProduct * nums[i], nums[i]));
		curMinProduct = min(prevMaxProduct * nums[i], min(prevMinProduct * nums[i], nums[i]));

		result = max(result, curMaxProduct);
		prevMaxProduct = curMaxProduct;
		prevMinProduct = curMinProduct;
	}
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(3);nums.push_back(-2);nums.push_back(4);
	cout << maxProductSubArray(nums) << endl;
	return 0;
}*/
