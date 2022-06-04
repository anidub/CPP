#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/RLw1Pjk1GQ0
 * We are given an unsorted array containing n numbers taken from the range 1 to n.
 *  The array has some numbers appearing twice, find all these duplicate numbers using constant space.
 Input: [3, 4, 4, 5, 5]
Output: [4, 5]

 */

void swapAD(vector<int> &nums, int i, int j);
//TC:O(N), SC:O(1)
vector<int> findAllDuplicateNumbers(vector<int> &nums) {
	if(nums.empty()) return {};
	vector<int> duplicateNumbers;

	int i = 0;
	while(i < nums.size()) {
		if(nums[i] != nums[nums[i] - 1]) {
			swapAD(nums, i, nums[i] - 1);
		} else
			i++;
	}

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] != i + 1)
			duplicateNumbers.push_back(nums[i]);
	}
	return duplicateNumbers;
}

void swapAD(vector<int> &nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

/*
int main() {
	vector<int> nums = {3,4,4,5,5};
	findAllDuplicateNumbers(nums);
}*/
