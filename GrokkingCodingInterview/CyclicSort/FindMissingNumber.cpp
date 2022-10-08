#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/first-missing-positive/
 * Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.
Input: nums = [1,2,0]
Output: 3
https://leetcode.com/problems/first-missing-positive/discuss/767105/Short-C%2B%2B-O(n)-time-O(1)-space-oror-Steps-explained
 */
//TC:O(N), SC: O(1)
int firstMissingPositive(vector<int>& nums) {
	if(nums.empty()) return 1;
	int n = nums.size();

	for(int i = 0; i < n; i++) {
		while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
			swap(nums[i], nums[nums[i] - 1]);
	}

	for(int i = 0; i < n; i++) {
		if(nums[i] != i+1) return i+1;
	}
	return n + 1;
}

void swapp(vector<int> & nums, int i, int j);
//IF ZERO INDEXED
int findMissingZeroIndexed(vector<int> & nums) {
	if(nums.empty()) return 0;
	int i = 0;
	while(i < nums.size()) {
		if(nums[i] < nums.size() && nums[i] != nums[nums[i]])
			swapp(nums, i, nums[i]); //WORKS
		else
			i++;
	}

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] != i)
			return i;
		return nums.size();
	}
}

void swapp(vector<int> & nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

/*
int main() {
	vector<int> nums = {1, 2, 0};
	cout << firstMissingPositive(nums) << endl;

	return 0;
}*/
