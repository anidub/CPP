#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/3w5ZMYAOLMA
 * Given a set of positive numbers, find the total number of subsets whose sum is equal to a given number ‘S’.
 * Input: {1, 1, 2, 3}, S=4
Output: 3
The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
Note that we have two similar sets {1, 3}, because we have two '1' in our input.

 */
class SubsetSum {
public:
	int countSubsetsRecursive(vector<int> &nums, int sum) {
		return this->countSubsetsRecursive(nums, sum, 0);
	}

	int countSubsetsMemo(vector<int> &nums, int sum) {
		vector<vector<int>> memo(nums.size(), vector<int>(sum + 1, -1));
		return this->countSubsetsMemo(memo, nums, sum, 0);
	}

	int countSubsetsDP(vector<int> &nums, int sum) {
		int n = nums.size();
		vector<vector<int>> DP(n, vector<int>(sum + 1, 0));

		for(int i = 0; i < n; i++)// populate the sum=0 columns, as we will always have an empty set for zero sum
			DP[i][0] = 1;

		 // with only one number, we can form a subset only when the required sum is equal to its value
		for(int s = 0; s <= sum; s++) {
			if(nums[0] == s){
				DP[0][s] = 1;
			}
		}

		for(int i = 1; i < n; i++) {
			for(int s = 1; s <= sum; s++) {
				DP[i][s] = DP[i - 1][s];// exclude the number
				if(nums[i] <= s)// include the number, if it does not exceed the sum
					DP[i][s] += DP[i - 1][s - nums[i]];
			}
		}

		return DP[n - 1][sum];
	}

	int countSubsetsDPSpaceOptimal(vector<int> &nums, int sum) {
		int n = nums.size();
		vector<int> dp(sum + 1);
		dp[0] = 1;

	    // with only one number, we can form a subset only when the required sum is equal to its value
		for(int s = 0; s <= sum; s++)
			dp[s] = (nums[0] == s ? 1 : 0);

		// process all subsets for all sums
		for(int i = 1; i < n; i++) {
			for(int s = 1; s <= sum; s++){
				if(nums[i] <= s) {
					dp[s] += dp[s - nums[i]];
				}
			}
		}

		return dp[sum];
	}

private:
	int countSubsetsRecursive(vector<int> &nums, int sum, int currentIndex) {
		if(sum == 0) return 1;

		if(currentIndex >= nums.size() || nums.empty())
			return 0;

		int sum1 = 0;
		if(nums[currentIndex] <= sum)
			sum1 = countSubsetsRecursive(nums, sum - nums[currentIndex], currentIndex + 1);

		int sum2 = countSubsetsRecursive(nums, sum, currentIndex + 1);

		return sum1 + sum2;
	}

	int countSubsetsMemo(vector<vector<int>> &memo, vector<int> &nums, int sum, int currentIndex) {
		if(sum == 0) return 1;

		if(nums.empty() || currentIndex >= nums.size())
			return 0;

		if(memo[currentIndex][sum] == -1) {
			int sum1 = 0;
			if(nums[currentIndex] <= sum)
				sum1 = countSubsetsMemo(memo, nums, sum - nums[currentIndex], currentIndex + 1);

			int sum2 = countSubsetsMemo(memo, nums, sum, currentIndex + 1);

			memo[currentIndex][sum] = sum1 + sum2;
		}
		return memo[currentIndex][sum];
	}
};

/*
int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 1, 2, 3};
  cout << "countSubsetsRecursive: " <<ss.countSubsetsRecursive(num, 4) << endl;
  cout << "countSubsetsMemo: " << ss.countSubsetsMemo(num, 4) << endl;
  cout << "countSubsetsDP: " << ss.countSubsetsDP(num, 4) << endl;
  cout << "countSubsetsDPSpaceOptimal: " << ss.countSubsetsDP(num, 4) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << "countSubsetsRecursive: "<< ss.countSubsetsRecursive(num, 9) << endl;
  cout << "countSubsetMemo: " << ss.countSubsetsMemo(num, 9) << endl;
  cout << "countSubsetDP: " << ss.countSubsetsDP(num, 9) << endl;
  cout << "countSubsetsDPSpaceOptimal: " << ss.countSubsetsDP(num, 9) << endl;
}
*/
