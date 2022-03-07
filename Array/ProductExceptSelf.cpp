#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/product-of-array-except-self/
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

https://leetcode.com/problems/product-of-array-except-self/discuss/776664/C%2B%2B-oror-3-Approaches-oror-Easy-to-understand
 */
vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> result(nums.size(), 1);
	int product = 1;

	for(int i = 1; i < nums.size(); i++) {
		result[i] = result[i-1] * nums[i-1];
	}

	for(int i = nums.size() - 1; i >= 1; i--) {
		product = product * nums[i];
		result[i-1] = result[i-1] * product;
	}
	return result;
}

vector<int> productExceptSelfEasy(vector<int>& nums) {
	int totalProduct = 1;
	int zeroCount = 0;
	int firstZeroIndex = 0;

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] == 0) {
			zeroCount++;
			if(zeroCount > 1)
				return vector<int> (nums.size(), 0);
			firstZeroIndex = i;
		} else
			totalProduct = totalProduct * nums[i];
	}

	for(int i = 0; i < nums.size(); i++) {
		if(zeroCount == 1) {
			if(i == firstZeroIndex) {
				nums[i] = totalProduct;
			} else
				nums[i] = 0;
		} else {
			nums[i] = totalProduct/nums[i];
		}
	}
	return nums;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);nums.push_back(4);

	vector<int> r1 = productExceptSelf(nums);

	vector<int> r2 = productExceptSelfEasy(nums);

	return 0;
}
*/
