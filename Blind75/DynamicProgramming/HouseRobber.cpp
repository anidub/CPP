#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/house-robber/
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
 * the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and
 *  it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can
 rob tonight without alerting the police.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

 * https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems. : VERY GOOD
 */
class HouseRobber {
public:
    int robRecursion(vector<int>& nums) {
        return robRecursion(nums, nums.size() - 1);
    }

    //TC:O(N), SC:O(N)
    int robMemo(vector<int> &nums) {
    	int n = nums.size();
    	vector<int> memo(n, -1);

    	return robMemo(nums, memo, n - 1);
    }

    //TC:O(N), SC:O(N)
    int robDP(vector<int> &nums) {
    	int n = nums.size();
    	int dp[n + 1];
    	dp[0] = 0;
    	dp[1] = nums[0];

    	for(int i = 1; i < nums.size(); i++) {
    		int val = nums[i];
    		dp[i + 1] = max(dp[i], dp[i - 1] + val);
    	}
    	return dp[n];
    }

    //TC:O(N), SC:O(1)
    int rob(vector<int> &nums) {
    	if(nums.size() == 0) return 0;
    	int prev1 = 0, prev2 = 0;

    	for(int num : nums) {
    		int tmp = prev1;
    		prev1 = max(prev1, prev2 + num);
    		prev2 = tmp;
    	}
    	return prev1;
    }

private:
    int robMemo(vector<int> &nums, vector<int> &memo, int i) {
    	if(i < 0) return 0;
    	if(memo[i] >= 0) return memo[i];

    	int result = max(robMemo(nums, memo, i - 2) + nums[i], robMemo(nums, memo, i - 1));

    	memo[i] = result;
    	return result;
    }

    int robRecursion(vector<int> &nums, int i) {
    	if(i < 0) return 0;

    	return max(robRecursion(nums, i - 2) + nums[i], robRecursion(nums, i - 1));
    }
};

/*
int main() {
	HouseRobber hr;
	vector<int> nums = {1,2,3,1};
	cout << hr.robRecursion(nums) << endl;
	cout << hr.robMemo(nums) << endl;
	cout << hr.robDP(nums) << endl;
	cout << hr.rob(nums) << endl;
}*/
