#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <set>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/non-decreasing-array/
 *Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.
We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
https://leetcode.com/problems/non-decreasing-array/discuss/1190689/Easiest-C%2B%2B-Solution-using-Count-Variable
 */
bool checkPossibilityNonDecreasing(vector<int>& nums) {
	if(nums.empty()) return 0;

	int count = 1;
	int min_value= INT_MIN;
	for(int i = 0; i < nums.size() - 1; i++) {
		if(nums[i] <= nums[i+1])
			min_value = nums[i];
		else{
			if(nums[i+1] < min_value)
				nums[i+1] = nums[i];//replace with ith value cuz of future iterations
			count--;
		}
	}
	return count >= 0;
}
/*
int main() {
	vector<int> nums; nums.push_back(4);nums.push_back(2);nums.push_back(3);
	cout << checkPossibilityNonDecreasing(nums) << endl;
	return 0;
}*/
