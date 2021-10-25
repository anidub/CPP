#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/jump-game/
 * Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
https://leetcode.com/problems/jump-game/discuss/21096/C%2B%2B-O(n)-solution-with-comments.
 */
bool canJump(vector<int>& nums) {
	if(nums.empty()) return false;
	int maxReach = 0;
	for(int i = 0; i < nums.size(); i++) {
		if(maxReach < i)
			return false;
		if(maxReach >= nums.size() - 1)
			return true;
		maxReach = max(maxReach, i + nums[i]);
		cout <<"maxReach:" <<  maxReach << endl;
	}
	return true;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(3);nums.push_back(1);nums.push_back(1);nums.push_back(4);
	cout << canJump(nums) << endl;

	return 0;
}*/
