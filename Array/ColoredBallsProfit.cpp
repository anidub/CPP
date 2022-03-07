#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
 * You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color that you initially own. You are also given an integer orders, which represents the total number of balls that the customer wants. You can sell the balls in any order.

Return the maximum total value that you can attain after selling orders colored balls. As the answer may be too large, return it modulo 109 + 7.
Input: inventory = [2,5], orders = 4
Output: 14
Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 times (5 + 4 + 3).
The maximum total value is 2 + 5 + 4 + 3 = 14.
https://leetcode.com/problems/sell-diminishing-valued-colored-balls/discuss/927509/Java-O(NlogN)-or-Detailed-Explanation-or-Runtime-Beats-100
https://www.youtube.com/watch?v=vl915tFlhJM

 */
int sumFromNtoX(long n, long x) {
	return (n * (n+1))/2 - (x * (x+1))/2;
}
//O(NlogN)
int maxProfitColoredBalls(vector<int>& inv, int orders) {
	if(inv.empty()) return 0;
	sort(inv.begin(), inv.end());
	long result = 0, n = inv.size() - 1; long count = 1;
	int mod = 1e9 + 7;

	while(orders > 0) {
		if(n > 0 && inv[n] - inv[n-1] > 0 && orders >= count * (inv[n] - inv[n-1])) {
			orders = orders -  count * (inv[n] -  inv[n-1]);
			result += count * sumFromNtoX(inv[n], inv[n-1]);
		} else if (n == 0 || inv[n] - inv[n-1] > 0) {
			long q = orders/count;
			result += count * sumFromNtoX(inv[n], (inv[n]-q));
			long r = orders % count;
			result += r * (inv[n] - q);
			orders = 0;
		}
		result %= mod;
		n--;
		count++;
	}
	return (int)result;

}
/*
int main() {
	vector<int> balls; balls.push_back(2);balls.push_back(8);balls.push_back(4);balls.push_back(10);balls.push_back(6);
	cout << maxProfitColoredBalls(balls, 20) << endl;
	return 0;
}*/
