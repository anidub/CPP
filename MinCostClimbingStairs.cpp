#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*https://leetcode.com/problems/min-cost-climbing-stairs/
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
https://leetcode.com/problems/min-cost-climbing-stairs/discuss/723040/C%2B%2B-oror-DP-oror-Easy-to-understand-oror-2-variants
 */

int minCostClimbingStairs(vector<int>& cost) {
	if(cost.size() == 0) return 0;
	if(cost.size() == 1) return cost[0];
	int first = cost[0]; int second = cost[1];

	for(int i = 2; i < cost.size(); i++) {
		int current = cost[i] + min(first, second);
		first = second;
		second = current;
	}
	return min(first, second);
}

int minCostClimbingStairsOther(vector<int>& cost) {
	if(cost.size() == 0) return 0;
	if(cost.size() == 1) return cost[0];
	int n = cost.size();
	for(int i = 2; i < n; i++) {
		cost[i] += min(cost[i-1], cost[i-2]);
	}
	return min(cost[n-1], cost[n-2]);
}

/*
int main() {
	vector<int> cost;
	cost.push_back(1);cost.push_back(100);cost.push_back(1);cost.push_back(1);
	cost.push_back(1);cost.push_back(100);cost.push_back(1);cost.push_back(1);
	cost.push_back(100); cost.push_back(1);

	cout << minCostClimbingStairs(cost) << endl;
	cout << minCostClimbingStairsOther(cost) << endl;
	return 0;
} */
