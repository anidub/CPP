#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/3jEXWgB5ZmM
 * Given an unsorted array containing numbers, find the smallest missing positive number in it.

Note: Positive numbers start from ‘1’.

Example 1:
Input: [-3, 1, 5, 4, 2]
Output: 3
Explanation: The smallest missing positive number is '3'

 */
void swapSMPN(vector<int> &nums, int i, int j);

//TC:O(N), SC:O(1)
int findSmallestMissingPositiveNumber(vector<int> &nums) {
	if(nums.empty()) return -1;

	int i = 0;

	while(i < nums.size()) {
		if(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
			swapSMPN(nums, i, nums[i] - 1);
		} else
			i++;
	}

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] != i + 1)
			return i + 1;
	}
	return nums.size() +  1;
}

void swapSMPN(vector<int> &nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

/*
int main() {
	vector<int> nums = {-3, 1, 5, 4, 2};
	cout << findSmallestMissingPositiveNumber(nums) << endl;

	return 0;
}*/

