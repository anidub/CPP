#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/product-of-array-except-self/
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
 */
class ProductArray {
public:
	//TC:O(N), SC:O(1)
	vector<int> productExceptSelf(vector<int>& nums) {
		if(nums.empty()) return {};
		vector<int> result(nums.begin(), nums.end());
		int zeroCount = 0, firstZeroIndex = 0;
		long totalProduct = 1;

		for(int i = 0; i < nums.size(); i++) {
			if(nums[i] == 0) {
				zeroCount++;
				if(zeroCount > 1) return vector<int>();
				firstZeroIndex = i;
			} else
				totalProduct *= result[i];
		}

		for(int i = 0; i < nums.size(); i++) {
			if(zeroCount == 1) {
				if(i == firstZeroIndex) {
					result[i] = totalProduct;
				} else
					result[i] = 0;
			} else {
				result[i] = totalProduct / result[i];
			}
		}
		return result;
	}

	vector<int> productExceptSelfNoDivision(vector<int>& nums) {
		vector<int> result(nums.size(), 1);
		int n = nums.size(), product = 1;
		for(int i = 1; i < n; i++){
			result[i] = result[i - 1] * nums[i - 1];
		}
		for(int i = nums.size() - 1; i >= 1; i--) {
			product = product * nums[1];
			result[i - 1] = result[ i - 1] * product;
		}
		return result;
	}
};

/*
int main() {
	ProductArray ts;
	vector<int> nums = {1,2,3,4};
	ts.productExceptSelf(nums);
	return 0;
}*/
