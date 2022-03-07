#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/192322/C%2B%2B-2-DP-Solutions
 */

/*
 *Throughout the trading days, our balance changes as follows:

Drops after we buy stock first time (- p1)
Rises after we sell it (+ p2)
Dips after we buy stock second time (- p3)
Hikes after we sell it (+ p4)
In the solution below, we just track the maximum balance after we perform each of the four operations:
 */
//Runtime: O(n), Space: O(1)
int bestTimeBuySell3Optimal(vector<int>& prices) {
	if(prices.empty()) return 0;
	int buy1 = INT_MIN, buy2 = INT_MIN, sell1 = 0, sell2 = 0;
	for(auto& p : prices) {
		buy1 = max(buy1, -p);
		sell1 = max(sell1, buy1 + p);
		buy2 = max(buy2, sell1 - p);
		sell2 = max(sell2, buy2 + p);
	}
	return sell2;
}


//Runtime: O(n), Space: O(n)
int bestTimeBuySell3(vector<int>& prices) {
	int n = prices.size();
	vector<int> left(n+1); vector<int> right (n+1);
	int min_l = INT_MAX, max_r = 0, res = 0;

	for(int i = 0; i < n; i++) {
		int price_l = prices[i], price_r = prices[n-i-1];
		min_l = min(min_l, price_l);
		max_r = max(max_r, price_r);
		left[i+1] = max(left[i], price_l - min_l);
		right[n-i-1] = max(right[n-i], max_r - price_r);
	}

	for(int i = 0; i <= n; i++)
		res = max(res, left[i] + right[i]);
	return res;
}
/*
int main() {
	vector<int> prices; prices.push_back(3);prices.push_back(3);prices.push_back(5);
	prices.push_back(0);prices.push_back(0);prices.push_back(3);
	prices.push_back(1);prices.push_back(4);
	cout << bestTimeBuySell3(prices) << endl;
	cout << bestTimeBuySell3Optimal(prices) << endl;
	return 0;
}
*/
