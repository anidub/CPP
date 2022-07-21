#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/3wEkKy6Pr9A
 * We are given an unsorted array containing ‘n+1’ numbers taken from the range 1 to ‘n’.
 * The array has only one duplicate but it can be repeated multiple times.
 * Find that duplicate number without using any extra space. You are, however, allowed to modify the input array.
 * Input: [1, 4, 4, 3, 2]
Output: 4
 */
void swapD(vector<int> &nums, int i, int j);

//TC:O(N), SC:O(1)
int findDuplicateNumber(vector<int> &nums) {
	if(nums.empty()) return -1;
	int i = 0;

	while(i < nums.size()) {
		if(nums[i] != i + 1) {
			if(nums[i] != nums[nums[i] - 1])
				swapD(nums, i, nums[i] - 1);
			else
				return nums[i];
		} else// we have found the duplicate
			i++;
	}
	return -1;
}

void swapD(vector<int> &nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
//https://leetcode.com/problems/find-the-duplicate-number/
/*How can we prove that at least one duplicate number must exist in nums?
 * https://www.geeksforgeeks.org/discrete-mathematics-the-pigeonhole-principle/
 */
//TC:O(1), SC:O(1)
int findDuplicateNumberOptimal(vector<int> &nums) {
	if(nums.empty()) return -1;
	int slow = 0, fast = 0;

	while(true) {
		slow = nums[slow];
		fast = nums[nums[fast]];
		if(slow == fast) break;
	}
	fast  = 0;
	while(slow != fast) {
		slow = nums[slow];
		fast = nums[fast];
	}
	return slow;
}
/*
int main() {
	vector<int> nums = {1,4,4,3,2};
	cout << findDuplicateNumberOptimal(nums) << endl;

	return 0;
}*/
