#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.
 */

int missingNumber(vector<int>& nums) {
	if(nums.size() == 0) return 0;
	int sum = 0; int n = nums.size();
	for(int i : nums) {
		sum += i;
	}

	int totalsum = n * (n+1)/2;
	return totalsum - sum;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(3);nums.push_back(0);nums.push_back(1);
	cout << missingNumber(nums);
	return 0;
}*/
