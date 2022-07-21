#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/JE0BWB8DgAJ
 * You are given a set of positive numbers and a target sum ‘S’. Each number should be assigned either a ‘+’ or ‘-’ sign.
 *  We need to find the total ways to assign symbols to make the sum of the numbers equal to the target ‘S’.
 * Input: {1, 1, 2, 3}, S=1
Output: 3
Explanation: The given set has '3' ways to make a sum of '1': {+1-1-2+3} & {-1+1-2+3} & {+1+1+2-3}

 */
class TargetSum {
public:
	//TC: O(N * S), SC: O(N * S)
	int findTargetSum(vector<int> &nums, int s) {
		if(nums.empty()) return -1;

		int totalSum = 0;
		for(int &i : nums)
			totalSum += i;

		if(totalSum < s || (s + totalSum) % 2 == 1)
			return 0;

		return countSubsets(nums, (s + totalSum) / 2);
	}

	//TC: O(N * S), SC: O(N)
	int findTargetSumSpaceOptimal(vector<int> &nums, int s) {
		int totalSum = 0;
		for(int &i : nums) totalSum += i;

		if(totalSum == 0 || (s + totalSum) % 2 == 1)
			return 0;

		return countSubsetsSpaceOptimal(nums, (s + totalSum) / 2);
	}

private:
	int countSubsets(vector<int> &nums, int sum) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

		for(int i = 0; i < n; i++)
			dp[i][0] = 1;

		for(int s = 1; s <= sum; s++)
			dp[0][s] = (nums[0] == s ? 1 : 0);


		for(int i = 1; i < n; i++) {
			for(int s = 0; s <= sum; s++) {
				dp[i][s] = dp[i - 1][s];

				if(nums[i] <= s) {
					dp[i][s] += dp[i - 1][s - nums[i]];
				}
			}
		}
		return dp[n - 1][sum];
	}


	int countSubsetsSpaceOptimal(vector<int> &nums, int sum) {
		vector<int> dp(sum + 1);
		dp[0] = 1;

		for(int s = 0; s <= sum; s++)
			dp[s] = (nums[0] == s ? 1 : 0);

		for(int i = 0; i < nums.size(); i++) {
			for(int s = sum; s >= 0; s--) {
				if(nums[i] <= s) {
					dp[s] += dp[s - nums[i]];
				}
			}
		}
		return dp[sum];
	}
};

/*
int main(int argc, char *argv[]) {
  TargetSum ts;
  vector<int> num = {1, 1, 2, 3};
  cout << "DP:" <<ts.findTargetSum(num, 1) << endl;
  cout << "Space optimal Dp:" <<ts.findTargetSumSpaceOptimal(num, 1) << endl;
  num = vector<int>{1, 2, 7, 1};
  cout << "DP:" << ts.findTargetSum(num, 9) << endl;
  cout << "Space optimal DP:" << ts.findTargetSumSpaceOptimal(num, 9) << endl;
}
*/
