#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 */

class BuySellStock {
public:
	//TC:O(N). SC:O(1)
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		if(prices.empty()) return profit;

		int min_buy = prices[0];

		for(int i = 1; i < prices.size(); i++) {
			if(prices[i] < min_buy)
				min_buy = prices[i];
			int cur_profit = prices[i] - min_buy;
			if(cur_profit > profit)
				profit = cur_profit;
		}
		return profit;
	}
};

/*
int main() {
	BuySellStock bss;
	vector<int> prices = {7,1,5,3,6,4};
	cout << bss.maxProfit(prices) << endl;
}*/
