#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * SLIDING WINDOW
 * https://leetcode.com/problems/maximum-average-subarray-i/
 * Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
https://leetcode.com/problems/maximum-average-subarray-i/discuss/105440/A-general-CC%2B%2B-solution
 *
 */

double findMaxAvgSubarray(vector<int>& nums, int k) {
	if(nums.size() == 0) return 0.0;
	double max_value = -numeric_limits<double>::max();
	double avg;
	int last = 0; double sum = 0;
	for(int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if(i < k-1)
			continue;
		avg = sum/k;
		max_value = max(max_value, avg);
		sum -= nums[last++];
	}
	return max_value;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(12);nums.push_back(-5);nums.push_back(-6);nums.push_back(50);nums.push_back(3);

	cout << findMaxAvgSubarray(nums, 4) << endl;

	return 0;
}*/
