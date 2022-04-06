#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/minimum-cost-for-tickets/
 * You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.
https://leetcode.com/problems/minimum-cost-for-tickets/discuss/630868/explanation-from-someone-who-took-2-hours-to-solve : used
https://leetcode.com/problems/minimum-cost-for-tickets/discuss/226659/Two-DP-solutions-with-pictures
 */
//Time Complexity: O(W), where W = 365W=365 is the maximum numbered day in your travel plan.
//Space Complexity: O(W)

int minCostTicketsMemo(vector<int>& days, vector<int> &costs, int start_index);
vector<int> dp;
int mincostTickets(vector<int>& days, vector<int>& costs) {
	if(days.empty() || costs.empty()) return 0;
	dp.resize(367);
	return minCostTicketsMemo(days, costs, 0);
}

int minCostTicketsMemo(vector<int>& days, vector<int> &costs, int start_index) {
	int n = days.size();
	if(start_index >= n) return 0;
	if(dp[start_index]) return dp[start_index];

	int cost_day = costs[0] + minCostTicketsMemo(days, costs, start_index + 1);

	int i = start_index;
	while(i < n && days[i] < days[start_index] + 7)
		i++;
	int cost_week = costs[1] + minCostTicketsMemo(days, costs, i);

	i = start_index;
	while(i < n && days[i] < days[start_index] + 30)
		i++;
	int cost_month = costs[2] + minCostTicketsMemo(days, costs, i);

	dp[start_index] = min({cost_day, cost_week, cost_month});// we store answer for future references
	return dp[start_index];
}
/*
int main() {
	vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
	cout << mincostTickets(days, costs) << endl;

	return 0;
}*/
