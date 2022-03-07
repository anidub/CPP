#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 * You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108884/JavaC%2B%2B-Clean-Code-(DPGreedy)
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/858347/C%2B%2B-State-Machine-DP-Solution-O(N)
 */

int buySellMultiple(vector<int>& prices, int fee) {
	if(prices.empty()) return 0;
	int* low = nullptr, *high = nullptr;
	int n = prices.size(); int profit = 0;

	for(int i = 0; i < n; i++) {
		if(low && !high && prices[i] - *low > fee) high = &prices[i];

		if(high && prices[i] > *high) high = &prices[i];
		if(high && (*high - prices[i] > fee || i == n-1)){
			profit += *high - *low - fee;
			high = nullptr;
			low = nullptr;
		}
		if(!low || prices[i] < *low) low = &prices[i];
	}
	return profit;
}
/*
int main() {

	vector<int> prices;
	prices.push_back(1);prices.push_back(3);prices.push_back(2);
	prices.push_back(8);prices.push_back(4);prices.push_back(9);

	cout << buySellMultiple(prices, 2) << endl;

	return 0;
}
*/
