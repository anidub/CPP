#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/jump-game-ii/
 * Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.

our goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
https://leetcode.com/problems/jump-game-ii/discuss/18207/Sharing-my-straightforward-C%2B%2B-solution

The variable maxReachPos indicates the farthest reachable position and the variable curMaxReachPos indicates the current farthest reachable position.

At the very beginning, both maxReachPos and curMaxReachPos are equal to A[0].
In the For loop, we keep updating curMaxReachPos while i <= maxReachPos. However, if( i == n - 1),
we return curStep, which is the minimum step. If i reaches the maxReachPos, we update maxReachPos with curMaxReachPos and increment curStep by one.
Finally, if we can't reach the end point, just return 0.
 */
//O(N)
int lineJumpMinSteps(vector<int>& nums) {
	int n = nums.size();
	if(nums.empty() || n == 1) return 0;

	int curMaxReachPos = nums[0];
	int maxReachPos = nums[0];
	int currentStep = 1;

	for(int i = 1; i <= min(n, maxReachPos); i++) {
		curMaxReachPos = max(curMaxReachPos, i + nums[i]);
		if(i == n-1)
			return currentStep;
		if(i == maxReachPos){
			maxReachPos = curMaxReachPos;
			currentStep++;
		}
	}
	return 0;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(3);nums.push_back(1);nums.push_back(1);nums.push_back(4);
	cout << lineJumpMinSteps(nums) << endl;

	return 0;
}*/
