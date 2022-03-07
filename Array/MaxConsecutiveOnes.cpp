#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;

/*
 * https://leetcode.com/problems/max-consecutive-ones/
 * Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
 */

int findMaxConsecutiveOnes(vector<int>& nums) {
	int result = 0;
	int count = 0;

	for(int i = 0; i < nums.size(); i++) {
		while(i < nums.size() && nums[i] == 1) {
			count++;
			i++;
		}
		result = max(result, count);
		count = 0;
	}
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(1);nums.push_back(0);nums.push_back(1);
	cout << findMaxConsecutiveOnes(nums);

	return 0;
}*/
