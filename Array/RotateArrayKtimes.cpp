#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/rotate-array/
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
 * Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
https://leetcode.com/problems/rotate-array/discuss/54503/C%2B%2BJava-easy-to-understand-solution.
https://leetcode.com/problems/rotate-array/discuss/723103/C%2B%2B-oror-Easy-to-understand-oror-Multiple-Approaches
https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C%2B%2B-solutions
 */
void reverse(vector<int>& nums, int start, int end) {
	while(start <= end) {
		int temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++; end--;
	}
}

void rotateArrayKTimes(vector<int>& nums, int k) {
	if(nums.empty()) return;
	k = k % nums.size();

	reverse(nums, 0, nums.size() - 1);

	reverse(nums, 0, k-1);

	reverse(nums, k, nums.size() - 1);
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);nums.push_back(4);nums.push_back(5);nums.push_back(6);nums.push_back(7);
	rotateArrayKTimes(nums, 3);

	for(int& i : nums) {
		cout << " " << i;
	}
	return 0;
}*/
