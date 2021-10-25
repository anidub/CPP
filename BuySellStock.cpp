#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * IMP:
 * If you just replace Java code "prices.length-1" with C++ code "prices.size()-1",
 * you will fail in the empty testcase. That's because the return type of container.size() is unsigned.
 *  So, 0-1 will not be interpreted as -1 but 2^32-1.
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 Example 1:
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
             https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/528582/C%2B%2B-Easy-Solution
             https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/39541/C%2B%2B-simple-solution.

             https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/39558/8ms-Easy-C%2B%2B-Solution
 */

int maxProfit(vector<int>& prices) {
	if(prices.size() == 0) return 0;
	int profit = 0;

	for(unsigned int i = 0; i < prices.size() - 1; i++) {
		if(prices[i+1] > prices[i]) {
			profit += prices[i+1] - prices[i];
		}
	}
	return profit;
}
/*
int main() {
	vector<int> prices;
	prices.push_back(7);prices.push_back(1);prices.push_back(5);prices.push_back(3);prices.push_back(6);
	prices.push_back(4);

	cout << maxProfit(prices) << endl;
}*/
