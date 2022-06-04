#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/Y52qNM0ljWK
 * We are given an unsorted array containing numbers taken from the range 1 to ‘n’. The array can have duplicates, which means some numbers will be missing. Find all those missing numbers.
 * Input: [2, 3, 1, 8, 2, 3, 5, 1]
Output: 4, 6, 7
Explanation: The array should have all numbers from 1 to 8, due to duplicates 4, 6, and 7 are missing.
 */
void swapNums(vector<int> &nums, int i, int j);

//TC:O(N), SC:O(1)
vector<int> findAllMissingNumbers(vector<int> &nums) {
	if(nums.empty()) return {};
	vector<int> missingNumbers;
	int i = 0;

	while(i < nums.size()) {
		if(nums[i] != nums[nums[i] - 1])
			swapNums(nums, i, nums[i] - 1);
		else
			i++;
	}

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] != i + 1)
			missingNumbers.push_back(i + 1);
	}
	return missingNumbers;
}

void swapNums(vector<int> &nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
/*
int main() {
	vector<int> nums = {2,3,1,8,2,3,5,1};
	findAllMissingNumbers(nums);

	return 0;
}
*/
