#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/
 * Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.
An array A is a zigzag array if either:
Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
Return the minimum number of moves to transform the given array nums into a zigzag array.
Example 1:
Input: nums = [1,2,3]
Output: 2
Explanation: We can decrease 2 to 0 or 3 to 1.
https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/discuss/351306/C%2B%2B-O(n)-Brute-force-Easy-to-understand-and-detailed-explanation
O(N)
 */
int movesToMakeZigZagDecrease(vector<int>& nums) {
	if(nums.size() <= 1) return 0;
	int cnt1 = 0, cnt2 = 0;

	//make odd indices smaller
	for(int i = 1; i < nums.size(); i+=2) {
		if(i == nums.size()-1){
			if(nums[i] >= nums[i-1]) cnt1 += nums[i] - nums[i-1] + 1;
		} else {
			if(nums[i] >= nums[i-1] || nums[i] >= nums[i+1]) cnt1 += nums[i] - min(nums[i-1], nums[i+1]) + 1;
		}
	}

	//make even indices smaller
	for(int i = 0; i < nums.size(); i+=2) {
		if(i == 0) {
			if(nums[i] >= nums[i+1]) cnt2 += nums[i] - nums[i+1] + 1;
		} else if(i == nums.size() - 1) {
			if(nums[i] >= nums[i-1]) cnt2 += nums[i] - nums[i-1] + 1;
		} else {
			if(nums[i] >= nums[i-1] || nums[i] >= nums[i+1]) cnt2 += nums[i] - min(nums[i-1], nums[i+1]) + 1;
		}
	}
	return min(cnt1, cnt2);
}
/*
int main() {
	vector<int> nums;
	nums.push_back(9);nums.push_back(6);nums.push_back(1);nums.push_back(6);nums.push_back(2);
	cout << movesToMakeZigZagDecrease(nums) << endl;
	return 0;
}*/
