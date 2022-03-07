#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/maximum-product-of-three-numbers/
 * Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
Example 1:
Input: nums = [1,2,3]
Output: 6
https://leetcode.com/problems/maximum-product-of-three-numbers/discuss/202503/C%2B%2B-O(n)-solution-98
 */

int maxProduct(vector<int>& nums) {
	if(nums.size() == 0) return 0;
	if(nums.size() < 3) return 0;

	int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
	int min1 = INT_MAX, min2 = INT_MAX;

	for(int n : nums) {
		if(n > max1) {
			max3 = max2;
			max2 = max1;
			max1 = n;
		} else if(n > max2) {
			max1 = max2;
			max2 = n;
		} else if (n > max3) {
			max3 = n;
		}

		if(n < min1) {
			min1 = min2;
			min1 = n;
		} else if(n < min2) {
			min2 = n;
		}
	}

    cout << "max1 : " << max1 << endl;    cout << "max2 : " << max2 << endl;     cout << "max3 : " << max3 << endl;
    cout << "min1 : " << min1 << endl;    cout << "min2 : " << min2 << endl;

    return  max(max1 * max2 * max3, min1 * min2 * max1);
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);
	cout << maxProduct(nums) << endl;
	return 0;
}
*/
