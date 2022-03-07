#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/sort-colors/
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
https://leetcode.com/problems/sort-colors/discuss/26474/Sharing-C%2B%2B-solution-with-Good-Explanation
 */
void DutchFlag(vector<int>& nums) {
	if(nums.empty()) return;
	int tmp = 0, low = 0, mid = 0, high = nums.size()-1;

	while(mid <= high) {
		if(nums[mid] == 0) {
			tmp = nums[mid];
			nums[mid] = nums[low];
			nums[low] = tmp;
			low++;
			mid++;
		} else if(nums[mid] == 1)
			mid++;
		else if(nums[mid] == 2) {
			tmp = nums[mid];
			nums[mid] = nums[high];
			nums[high] = tmp;
			high--;
		}
	}
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(0);nums.push_back(2);nums.push_back(1);nums.push_back(1);nums.push_back(0);
	DutchFlag(nums);
	return 0;
}*/
