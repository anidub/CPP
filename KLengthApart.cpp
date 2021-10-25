#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
 * Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise return False.
 Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.

 */

bool klengthApart(vector<int>& nums, int k) {
	if(nums.size() == 0) return false;
	int index = -1;

	for(int i = 0; i < nums.size(); i++) {
		if(index == -1 && nums[i] == 1)
			index = i;
		else if(nums[i] == 1){
			if(i - index < k+1) return false;
			index = i;
		}
	}
	return true;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(0);nums.push_back(0);;nums.push_back(1);nums.push_back(0);nums.push_back(1);
	cout << klengthApart(nums, 2);
	return 0;
}*/
