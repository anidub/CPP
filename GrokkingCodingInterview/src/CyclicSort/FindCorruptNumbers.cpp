#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/mE2LVDE3wp0
 * Find the Corrupt Pair (easy)#
We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array originally
contained all the numbers from 1 to ‘n’, but due to a data error,
one of the numbers got duplicated which also resulted in one number going missing. Find both these numbers.
Input: [3, 1, 2, 5, 2]
Output: [2, 4]
Explanation: '2' is duplicated and '4' is missing.
 */
void swapCN(vector<int> &nums, int i, int j);

//TC:O(N), SC:O(1)
vector<int> findCorruptNumbers(vector<int> &nums) {
	if(nums.empty()) return {};
	int i = 0;

	while(i < nums.size()) {
		if(nums[i] != nums[nums[i] - 1]) {
			swapCN(nums, i, nums[i] - 1);
		} else
			i++;
	}

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] != i + 1)
			return vector<int>{nums[i], i + 1};
	}
	return vector<int>{-1, -1};
}

void swapCN(vector<int> &nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
/*
int main() {
	vector<int> nums = {3,1,2,5,2};
	findCorruptNumbers(nums);
}*/
