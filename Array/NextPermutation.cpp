#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/next-permutation/
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
The replacement must be in place and use only constant extra memory.
Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
https://leetcode.com/problems/next-permutation/discuss/13867/C%2B%2B-from-Wikipedia
 */
// O(N)
void nextPermutation(vector<int>& nums) {
	if(nums.empty()) return;
	int n = nums.size(), k, l;

	for(k = n-2; k >= 0; k--) {
		if(nums[k] < nums[k+1])
			break;
	}
	if(k < 0) {
		reverse(nums.begin(), nums.end());
		return;
	} else {
		for(l = n-1; l > k; l--) {
			if(nums[l] > nums[k])
				break;
		}
		//swap(nums[l], nums[k]); //works
		reverse(nums.begin() + k + 1, nums.end());
	}
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);
	nextPermutation(nums);

	return 0;
}
*/
