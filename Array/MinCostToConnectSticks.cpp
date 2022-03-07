#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/minimum-cost-to-connect-sticks/
 * You have some number of sticks with positive integer lengths. These lengths are given as an array sticks, where sticks[i] is the length of the ith stick.

You can connect any two sticks of lengths x and y into one stick by paying a cost of x + y. You must connect all the sticks until there is only one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.
https://leetcode.com/problems/minimum-cost-to-connect-sticks/discuss/552971/An-explanation-of-the-problem-statement%3A  : to understand problem
https://leetcode.com/problems/minimum-cost-to-connect-sticks/discuss/365836/C%2B%2B-Greedy-approach-using-priority-queue-(with-explanation)
 *
 */

//TC:O(NLOGN), SC : O(N)
int minCostConnectSticks(vector<int>& sticks) {
	if(sticks.empty()) return 0;
	priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
	int result = 0;
	while(pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		result += a + b;
		pq.push(a + b);
	}
	return result;
}

/*
int main() {
	vector<int> sticks = {2,4,3};
	cout << minCostConnectSticks(sticks) << endl;
}*/
