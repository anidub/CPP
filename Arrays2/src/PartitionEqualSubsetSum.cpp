#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;
/*https://leetcode.com/problems/partition-equal-subset-sum/
 * Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
 *
 * Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
https://leetcode.com/problems/partition-equal-subset-sum/discuss/1624390/C%2B%2B-Brute-Force-To-Optimized-SolutionO(N)-Time-or-W-Explanation
 */

//Time Complexity : O(n (sum/2)))
//Space Complexity : O(sum/2)

bool solveCanPartitionEqualSubsetSum(vector<int> &nums, int sum);

bool canPartitionEqualSubsetSum(vector<int> &nums) {
	int sum = 0;
	sum = accumulate(nums.begin(), nums.end(), sum);

	return (sum % 2 == 0 && solveCanPartitionEqualSubsetSum(nums, sum / 2));
}

bool solveCanPartitionEqualSubsetSum(vector<int> &nums, int sum) {
	int n = nums.size();
	vector<bool> dp(sum + 1, false);

	dp[0] = true;
	for(int num : nums) {
		for(int j = sum; j >= num; j--) {
			if(dp[j - num] || j == num) dp[j] = true;
		}
	}
	return dp[sum];
}
/*
int main() {
	vector<int> nums = {1 , 5 , 11, 5};
	cout << canPartitionEqualSubsetSum(nums) << endl;

	return 0;
}*/
