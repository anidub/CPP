#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/target-sum/
 * You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

https://www.youtube.com/watch?v=QihB4bI6BJw
https://www.youtube.com/watch?v=34l1kTIQCIA  :subset

https://leetcode.com/problems/target-sum/discuss/97369/Evolve-from-brute-force-to-dp : used
Aditya verma youtube
https://leetcode.com/problems/target-sum/discuss/1174595/99-faster-oror-Using-DP-oror-Formula-explain
 */
int findTargetSumSubset(vector<int> &nums, int target) {
	if(nums.empty()) return 0;
	int n = nums.size();
	vector<unordered_map<int, int>> dp(n + 1);
	dp[0][0] = 1;

	for(int i = 0; i < n; i++) {
		for(auto &p : dp[i]) {
			dp[i + 1][p.first + nums[i]] += p.second;
			dp[i + 1][p.first - nums[i]] += p.second;
		}
	}
	return dp[n][target];
}

/* brute force recursion O(2^n)
     int findTargetSumWays(vector<int>& nums, int S) {
        return find(0,nums,S);
    }
    int find(int p, vector<int>& nums, int sum) {
        if(p==nums.size()) return sum==0;
        return find(p+1,nums,sum+nums[p])+find(p+1,nums,sum-nums[p]);
    }
 */

/* Memoization : O(NTarget)
     int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int,int>> mem(nums.size());
        return find(0,nums,S,mem);
    }
    int find(int p, vector<int>& nums, int sum, vector<unordered_map<int,int>>& mem) {
        if(p==nums.size()) return sum==0;
        auto it = mem[p].find(sum);
        if(it != mem[p].end()) return it->second;
        return mem[p][sum]=find(p+1,nums,sum+nums[p],mem)+find(p+1,nums,sum-nums[p],mem);
    }
 */
/*
int main() {
	vector<int> nums = {1, 1, 1, 1, 1};
	cout << findTargetSumSubset(nums, 3) << endl;

	return 0;
}
*/
