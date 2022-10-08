#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/gxrnL0GQGqk
 * Given a set of positive numbers, determine if a subset exists whose sum is equal to a given number ‘S’.
 * Input: {1, 2, 3, 7}, S = 6
Output: True
The given set has a subset whose sum is '6': {1, 2, 3}

Input: {1, 2, 7, 1, 5}, S=10
Output: True
The given set has a subset whose sum is '10': {1, 2, 7}

 */
class SubsetSum {
 public:

	//O(2^N), SC:O(N)
  bool canParitionRecursive(const vector<int> &nums, int sum) {
	  return this->canParitionRecursive(nums, sum, 0);
  }

  //TC:O(N * S), SC:O(N * S)
  bool canParitionMemo(const vector<int> &nums, int sum) {
	  if(nums.empty()) return 0;
	  int n = nums.size();

	  vector<vector<int>> memo(n, vector<int>(sum + 1, -1));

	  return this->canParitionMemo(nums, memo, sum,0);
  }

	//TC:O(N * S), SC:O(N * S)
  bool canPartition(const vector<int> &nums, int sum) {
	  if(nums.empty()) return false;
	  int n = nums.size();

	  vector<vector<bool>> dp(n, vector<bool>(sum + 1));

	  for(int i = 0; i < n; i++)
		  dp[i][0] = true;

	  for(int s = 1; s <= sum; s++)
		  dp[0][s] = nums[0] == s ? true : false;

	  for(int i = 1; i < n; i++) {
		  for(int s = 1; s <= sum; s++) {
			  if(dp[i - 1][s])
				  dp[i][s] = dp[i - 1][s];
			  else if(nums[i] <= s)
				  dp[i][s] = dp[i - 1][s - nums[i]];
		  }
	  }
	  return dp[n - 1][sum];
  }

  //TC:O(N * S), SC:O(S)
  bool canPartitionSpaceOptimal(const vector<int> &nums, int sum) {
	  if(nums.empty()) return false;
	  int n = nums.size();

	  vector<bool> dp(sum + 1);

	  dp[0] = true;

	  for(int s = 0; s <= sum; s++)
		  dp[s] = nums[0] == s ? true : false;

	  for(int i = 1; i < n; i++) {
		  for(int s = sum; s >= 0; s--) {
			  if(!dp[s] && nums[i] <= s)
				  dp[s] = dp[s - nums[i]];
		  }
	  }
	  return dp[sum];
  }

 private:
  bool canParitionRecursive(const vector<int> &nums, int sum, int currentIndex) {
	  if(sum == 0) return true;

	  if(currentIndex >= nums.size()) return false;

	  if(nums[currentIndex] <= sum)
		  return canParitionRecursive(nums, sum - nums[currentIndex], currentIndex + 1);

	  return canParitionRecursive(nums, sum, currentIndex + 1);
  }

  bool canParitionMemo(const vector<int> &nums, vector<vector<int>> &memo, int sum, int currentIndex) {
	  if(sum == 0) return true;
	  if(currentIndex >= nums.size()) return false;

	  if(memo[currentIndex][sum] == -1) {
		  if(nums[currentIndex] <= sum)
			  if(canParitionMemo(nums, memo, sum - nums[currentIndex], currentIndex + 1)) {
				  memo[currentIndex][sum] = true;
				  return true;
			  }
		  memo[currentIndex][sum] = canParitionRecursive(nums, sum, currentIndex + 1);
	  }
	  return memo[currentIndex][sum];
  }
};

/*
int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 2, 3, 7};
  cout << "recursive:" << ss.canParitionRecursive(num, 6) << endl;
  cout << "memo:" << ss.canParitionMemo(num, 6) << endl;
  cout << "dp:" << ss.canPartition(num, 6) << endl;
  cout << "space optimal dp:" << ss.canPartitionSpaceOptimal(num, 6) << endl;
  cout << "-------------------" << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << "recursive:" << ss.canParitionRecursive(num, 10) << endl;
  cout << "memo:" << ss.canParitionMemo(num, 10) << endl;
  cout << "dp:" << ss.canPartition(num, 10) << endl;
  cout << "space optimal dp:" << ss.canPartitionSpaceOptimal(num, 10) << endl;
  cout << "-------------------" << endl;
  num = vector<int>{1, 3, 4, 8};
  cout << "recursive:" << ss.canParitionRecursive(num, 6) << endl;
  cout << "memo:" << ss.canPartition(num, 6) << endl;
  cout << "dp:" << ss.canPartition(num, 6) << endl;
  cout << "space optimal dp:" << ss.canPartitionSpaceOptimal(num, 6) << endl;
}

*/
