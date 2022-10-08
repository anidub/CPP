#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/q2LA7G0ANX0
 * Find the First K Missing Positive Numbers (hard)#
Given an unsorted array containing numbers and a number ‘k’, find the first ‘k’ missing positive numbers in the array.
Input: [3, -1, 4, 5, 5], k=3
Output: [1, 2, 6]
Explanation: The smallest missing positive numbers are 1, 2 and 6.
 */

void swapFirstKMissing(vector<int> &nums, int i, int j);

//TC: O(N + K), SC: O(K) for storing k extraNumbers
vector<int> findFirstKMissingPositiveNumbers(vector<int> &nums, int k) {
	if(nums.empty()) return {};
	vector<int> missingNumbers;

	int i = 0;
	while(i < nums.size()) {
		if(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
			swapFirstKMissing(nums, i, nums[i] - 1);
		} else
			i++;
	}

	unordered_set<int> extraNumbers;

	for(int i = 0; i < nums.size() && missingNumbers.size() < k; i++) {
		if(nums[i] != i + 1) {
			missingNumbers.push_back(i + 1);
			extraNumbers.insert(nums[i]);
		}
	}
	i = 1;
	// add the remaining missing numbers
	while(missingNumbers.size() < k) {
		int candidateNumber = i + nums.size();
		// ignore if the array contains the candidate number
		if(extraNumbers.find(candidateNumber) == extraNumbers.end()) { // not found
			missingNumbers.push_back(candidateNumber);
		}
		i++;
	}
	return missingNumbers;
}

void swapFirstKMissing(vector<int> &nums, int i, int j){
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

/*
int main() {
	vector<int> nums = {3, -1, 4, 5, 5};
	findFirstKMissingPositiveNumbers(nums, 3);

	return 0;
}*/
