#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/move-zeroes/
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
https://leetcode.com/problems/move-zeroes/discuss/72428/C%2B%2B-short-solution.
 */
void moveZeros(vector<int>& nums) {
	if(nums.size() == 0) return;
	int tail = 0;
	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] != 0) {
			nums[tail] = nums[i];
			tail++;
		}
	}

	for(int i = tail; i < nums.size(); i++) {
		nums[i] = 0;
	}
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(1);nums.push_back(0);nums.push_back(3);nums.push_back(12);
	moveZeros(nums);
}*/
