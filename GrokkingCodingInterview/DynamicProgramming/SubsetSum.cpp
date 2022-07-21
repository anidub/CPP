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
 * Input: {1, 2, 3, 7}, S=6
Output: True
The given set has a subset whose sum is '6': {1, 2, 3}

 */
class SubsetSum {
 public:
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
};

/*
int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 2, 3, 7};
  cout << ss.canPartition(num, 6) << endl;
  cout << ss.canPartitionSpaceOptimal(num, 6) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.canPartition(num, 10) << endl;
  cout << ss.canPartitionSpaceOptimal(num, 10) << endl;
  num = vector<int>{1, 3, 4, 8};
  cout << ss.canPartition(num, 6) << endl;
  cout << ss.canPartitionSpaceOptimal(num, 6) << endl;
}
*/
