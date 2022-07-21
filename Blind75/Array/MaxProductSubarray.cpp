#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/maximum-product-subarray/
 * Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
 * Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
 */
class MaxProductSubarray {
public:
	//TC:O(N), SC:O(1)
	int maxProduct(vector<int> &nums) {
		if(nums.empty()) return 0;

		int result = nums[0];
		int curMaxProduct = nums[0];
		int curMinProduct = nums[0];
		int prevMaxProduct = nums[0];
		int prevMinProduct = nums[0];

		for(int i = 1; i < nums.size(); i++) {
			curMaxProduct = max(prevMaxProduct * nums[i], max(prevMinProduct * nums[i], nums[i]));
			curMinProduct = min(prevMinProduct * nums[i], min(prevMinProduct * nums[i], nums[i]));
			result = max(result, curMaxProduct);

			prevMaxProduct = curMaxProduct;
			prevMinProduct = curMinProduct;
		}
		return result;
	}
};
/*
int main() {
	MaxProductSubarray mps;

	vector<int> nums = {2, 3, -2, 4};
	cout << mps.maxProduct(nums) << endl;
}
*/
