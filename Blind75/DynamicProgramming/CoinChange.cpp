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
/*https://leetcode.com/problems/coin-change/
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

https://leetcode.com/problems/coin-change/discuss/77360/C%2B%2B-O(n*amount)-time-O(amount)-space-DP-solution
 */
class CoinChange {
public:
	//TC:O(amount * N) SC:O(amount)
	int coinChange(vector<int>& coins, int amount) {
		if(coins.empty()) return -1;
		int max = amount + 1;

		vector<int> dp(amount + 1, max);

		for(int i = 1; i <= amount; i++) {
			for(int j = 0; j < coins.size(); j++) {
				if(coins[j] <= i)
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}

		return dp[amount] > amount ? -1 : dp[amount];
	}
	
	
	
	    //Recursion:Time: O(2^n) Space: O(n)
    int coinChangeBrute(vector<int>& coins, int amount) { 
        int res = findLowestCoinsBrute(coins, 0, amount);        
        return (res == INT_MAX - 1)? -1 : res;
    }
    
    int findLowestCoinsBrute(vector<int>& coins, int cur, int amount) {
        if(cur >= coins.size() || amount <= 0) {
            return (amount == 0) ? 0 : INT_MAX - 1;
        }
        int res = -1;
        if(coins[cur] > amount) {
            int doNotTakeCoin = 0 + findLowestCoinsBrute(coins, cur + 1, amount - 0);
            res = doNotTakeCoin;
        } else {
            int takeCoin = 1 + findLowestCoinsBrute(coins, cur + 0, amount - coins[cur]);
            int doNotTakeCoin = 0 + findLowestCoinsBrute(coins, cur + 1, amount - 0);
            res = min(takeCoin, doNotTakeCoin);
        }
        return res;
    }
    
    
    //Memoization Time: O(n.m) Space: O(n.m)
    int memo[12 + 1][10000 + 1];
    int coinChangeMemo(vector<int>& coins, int amount) {
        memset(memo, -1, sizeof(memo));
        int res = findLowestCoinsMemo(coins, 0, amount);
        return (res == INT_MAX - 1) ? -1 : res;
    }
    
    int findLowestCoinsMemo(vector<int>& coins, int cur, int amount) {
        if(cur >= coins.size() || amount <= 0) {
            return amount == 0 ? 0 : INT_MAX - 1;
        }
        if(memo[cur][amount] != -1) return memo[cur][amount];
        int res = -1;
        if(coins[cur] > amount) {
            int doNotTakeCoin = 0 + findLowestCoinsMemo(coins, cur + 1, amount - 0);
            memo[cur][amount] = res = doNotTakeCoin;
        } else {
            int takeCoin = 1 + findLowestCoinsMemo(coins, cur + 0, amount - coins[cur]);
            int doNotTakeCoin = 0 + findLowestCoinsMemo(coins, cur + 1, amount - 0);
            res = min(takeCoin, doNotTakeCoin);
            memo[cur][amount] = res;
        }
        return memo[cur][amount];
    }
};

/*
int main() {
	CoinChange cc;
	vector<int> coins = {1, 2, 5};
	cout << cc.coinChange(coins, 11) << endl;

	return 0;
}
*/
