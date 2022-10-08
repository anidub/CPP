#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/B8qXVqVwDKY
 * We are given an array containing n objects. Each object, when created, was assigned a unique number from the range 1 to n based
 *  on their creation sequence. This means that the object with sequence number 3 was
 *  created just before the object with sequence number 4.
 * Write a function to sort the objects in-place on their creation sequence number in O(n)
O(n)
 and without using any extra space. For simplicity, let’s assume we are passed an integer array
 containing only the sequence numbers, though each number is actually an object.

Input: [3, 1, 5, 4, 2]
Output: [1, 2, 3, 4, 5]


Input: [2, 6, 4, 3, 1, 5]
Output: [1, 2, 3, 4, 5, 6]
 */
void swapNum(vector<int> &nums, int i, int j);
//TC:O(N), SC:O(1)
void cyclicSort(vector<int> &nums) {
	if(nums.empty()) return;
	int i = 0;

	while(i < nums.size()) {
		int j = nums[i] - 1;
		if(nums[i] != nums[j])
			swapNum(nums, i, j);
		else
			i++;
	}
}

void swapNum(vector<int> &nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
/*
int main() {
	vector<int> nums = {3, 5, 4, 1, 2};
	cyclicSort(nums);
	for(int i : nums)
		cout << i << "--";

	return 0;
} */
