#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
* Given an array nums, you are allowed to choose one element of nums and change it by any value in one move.
Return the minimum difference between the largest and smallest value of nums after perfoming at most 3 moves.
Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: Change the array [5,3,2,4] to [2,2,2,2].
The difference between the maximum and minimum is 2-2 = 0.
https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/discuss/730567/JavaC%2B%2BPython-Straight-Forward
https://www.youtube.com/watch?v=Ht6hc3UsvY0
 */
int minDifference3moves(vector<int>& nums) {
	if(nums.empty() || nums.size() < 5) return 0;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	return min({nums[n-1] - nums[3], nums[n-2] - nums[2], nums[n-3] - nums[1], nums[n-4] - nums[0]});
}
/*
int main() {
	vector<int> nums;//1,5,6,13,14,15,16,17
	nums.push_back(1);nums.push_back(5);nums.push_back(6);
	nums.push_back(13);nums.push_back(14);nums.push_back(15);
	nums.push_back(16);nums.push_back(17);
	cout << minDifference3moves(nums);
	return 0;
}*/
