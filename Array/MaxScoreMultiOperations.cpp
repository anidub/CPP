#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <cstring>

using namespace std;
/*
 * https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
 * You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.
You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:
Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.
Example 1:

Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/discuss/1078881/C%2B%2B-DP-(SIMPLEST-TO-UNDERSTAND)-greater-Recursive-to-Memorisation-greater-Complete-EXPLANATION
 */

//Time Complexity : O(2 * m^2) -> in this question O( sizeof(multiplier vector)^2 ) as thats the limiting constraint.
//Space Complexity : O(m^2)
int dp[1000][1000];

int answer_dp(vector<int>& nums, vector<int>& multi, int i, int l, int r) {
	if(i == multi.size()) return 0;

	if(dp[l][i] != -1)
		return dp[l][i];

	int first = nums[l] * multi[i] + answer_dp(nums, multi, i+1, l+1, r);
	int last = nums[r] * multi[i] + answer_dp(nums, multi, i+1, l, r-1);

	dp[l][i] = max(first, last);

	return dp[l][i];
}


int maximumScoreMultipliers(vector<int>& nums, vector<int>& multi) {
	if(nums.empty()) return 0;
	memset(dp, -1, sizeof(dp));
	return answer_dp(nums, multi, 0, 0, nums.size() - 1);
}
/*
int main() {
	vector<int> nums; nums.push_back(1);nums.push_back(2);nums.push_back(3);
	vector<int> multi; multi.push_back(3);multi.push_back(2);multi.push_back(1);
	cout << maximumScoreMultipliers(nums, multi) << endl;

	return 0;
}*/
