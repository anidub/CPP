#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * you are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/39339/Simple-C%2B%2B
 */

int buySellStockProfit(vector<int>& prices) {
	if(prices.size() == 0) return 0;
	int low = prices[0]; int diff;
	int profit = 0;
	for(int i = 0; i < prices.size(); i++) {
		low = min(low, prices[i]);
		diff = prices[i] - low;
		profit = max(profit, diff);
	}
	return profit;
}

int buySellKanadeAlgo(vector<int>& prices) {
	if(prices.size() == 0) return 0;
	int cur = 0, result = 0, n = prices.size();
	for(int i = 1; i < prices.size(); i++) {
		cur += prices[i] - prices[i-1];
		cur = max(cur, 0);
		result = max(result, cur);
	}
	return result;
}
/*
int main() {
	vector<int> prices;
	prices.push_back(7);prices.push_back(1);prices.push_back(5);
	prices.push_back(3);prices.push_back(6);prices.push_back(4);

	cout << buySellStockProfit(prices) << endl;
	cout << buySellKanadeAlgo(prices) << endl;

	return 0;
}
*/
