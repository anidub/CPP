#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/g7QYlD8RwRr
 * Given a set of positive numbers, find if we can partition it into two subsets such that the sum of elements in both subsets is equal.
 * Input: {1, 2, 3, 4}
Output: True
Explanation: The given set can be partitioned into two subsets with equal sum: {1, 4} & {2, 3}

 */
class PartitionSet {
 public:
	//O(2^N), SC:O(N)
  bool canPartitionRecursive(const vector<int> &nums) {
	  int sum = 0;
	  for(int i : nums)
		  sum += i;

	  if(sum % 2 != 0) return false;// if 'sum' is a an odd number, we can't have two subsets with equal sum

	  return this->canPartitionRecursive(nums, sum / 2, 0);
  }

  //TC:O(N * S), SC:O(N * S)
  bool canPartitionMemo(const vector<int> &nums) {
	  int sum = 0;
	  for(int i : nums)
		  sum += i;

	   if(sum % 2 != 0) return false;// if 'sum' is a an odd number, we can't have two subsets with equal sum

	   vector<vector<int>> memo(nums.size(), vector<int>(sum / 2 + 1, -1));

	   return this->canPartitionMemo(memo, nums, sum / 2, 0);
  }

  //TC:O(N * S), SC:O(N * S)
bool canPartitionBottomUp(const vector<int> &nums) {
	int sum = 0;
	for(int i : nums)
		sum += i;

	if(sum % 2 != 0) return false;// if 'sum' is a an odd number, we can't have two subsets with equal sum

	sum /= 2;

	int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(sum + 1));

	for(int i = 0; i < n; i++)// populate the sum=0 columns, as we can always for '0' sum with an empty set
		dp[i][0] = true;

	for(int s = 0; s <= sum; s++) // with only one number, we can form a subset only when the required sum is equal to its value
		dp[0][s] = nums[0] == s ? 1 : 0;

	for(int i = 1; i < n; i++) {
		for(int s = 1; s <= sum; s++) {
			if(dp[i - 1][s])// if we can get the sum 's' without the number at index 'i': exclude
				dp[i][s] = dp[i - 1][s];
			else if(nums[i] <= s)// else if we can find a subset to get the remaining sum : include
				dp[i][s] = dp[i - 1][s - nums[i]];
		}
	}
	return dp[n - 1][sum];// the bottom-right corner will have our answer.

}

private:
  bool canPartitionRecursive(const vector<int> &nums, int sum, int currentIndex) {
	  if(sum == 0) return true;

	  if(nums.empty() || currentIndex >= nums.size()) return false;

	  if(nums[currentIndex] <= sum)// recursive call after choosing the number at the currentIndex
		  if(canPartitionRecursive(nums, sum - nums[currentIndex], currentIndex + 1))
			  return true;

	  return canPartitionRecursive(nums, sum, currentIndex + 1); // recursive call after excluding the number at the currentIndex
  }

  bool canPartitionMemo( vector<vector<int>> &memo, const vector<int> &nums, int sum, int currentIndex) {
	  if(sum == 0) return true;

	  if(currentIndex >= nums.size() || nums.empty()) return false;

	  if(memo[currentIndex][sum] == -1) {// if we have not already processed a similar problem
		  if (nums[currentIndex] <= sum) {// recursive call after choosing the number at the currentIndex
			  if(canPartitionMemo(memo, nums, sum - nums[currentIndex], currentIndex + 1)){
				  memo[currentIndex][sum] = 1;
				  return true;
			  }
		  }
		  memo[currentIndex][sum] = canPartitionMemo(memo, nums, sum, currentIndex + 1);// recursive call after excluding the number at the currentIndex
	  }

	  return memo[currentIndex][sum] == 1 ? true : false;
  }
};

/*
int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 4};
  cout << ps.canPartitionRecursive(num) << endl;
  cout << ps.canPartitionMemo(num) << endl;
  cout << ps.canPartitionBottomUp(num) << endl;
  num = vector<int>{1, 1, 3, 4, 7};
  cout << ps.canPartitionRecursive(num) << endl;
  cout << ps.canPartitionMemo(num) << endl;
  cout << ps.canPartitionBottomUp(num) << endl;
  num = vector<int>{2, 3, 4, 6};
  cout << ps.canPartitionRecursive(num) << endl;
  cout << ps.canPartitionMemo(num) << endl;
  cout << ps.canPartitionBottomUp(num) << endl;
}*/
