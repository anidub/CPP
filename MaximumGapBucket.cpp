#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/maximum-gap/
 * Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.
Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
https://leetcode.com/problems/maximum-gap/discuss/50667/Solutions-in-C%2B%2B-with-explanation-read-it-and-then-you-get-it
https://www.youtube.com/watch?v=VT-6zwGKYwA : to understand
 */

int maximumGapBucket(vector<int>& nums) {
	if(nums.empty()) return 0;
	int size = nums.size();
	if(size == 1) return 0;
	if(size == 2) return abs(nums[1] - nums[0]);

	int minNum = INT_MAX, maxNum = INT_MIN;
	for(int& n : nums) {
		minNum = min(minNum, n);
		maxNum = max(maxNum, n);
	}

	int interval = (maxNum - minNum)/(size - 1) + 1;
	vector<int> bucketsMin(size, INT_MAX);
	vector<int> bucketsMax(size, INT_MIN);

	for(int i = 0; i < size; i++) {
		if(nums[i] == minNum || nums[i] == maxNum) continue;
		int index = (nums[i] - minNum)/interval;
		bucketsMin[index] = min(bucketsMin[index], nums[i]);
		bucketsMax[index] = max(bucketsMax[index], nums[i]);
	}
	int prev = minNum;
	int maxGap = 0;
	for(int i = 0; i < bucketsMin.size(); i++) {
		if(bucketsMax[i] == INT_MIN) continue;
		maxGap = max(maxGap, bucketsMin[i] - prev);
		prev = bucketsMax[i];
	}
	maxGap = max(maxGap, maxNum - prev);
	return maxGap;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(3);nums.push_back(6);nums.push_back(9);nums.push_back(1);
	cout << maximumGapBucket(nums) << endl;

	return 0;
}*/
