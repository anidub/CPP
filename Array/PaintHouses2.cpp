#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.cnblogs.com/grandyang/p/5322870.html
 * There are a row of  n  houses, each house can be painted with one of the  k  colors.
 *  The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color .
The cost of painting each house with a certain color is represented by a   cost matrix. For example,
 is the cost of painting house 0 with color 0;   is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.n x kcosts[0][0]costs[1][2]
Note:
All costs are positive integers.
Example:
Input: [[1,5,3],[2,9,4]]
Output: 5
Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5;
 Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5

 */
//O ( nk )
int minCostPaintHouses2(vector<vector<int>>& costs) {
	if(costs.empty() || costs[0].empty()) return 0;
	int min1 = 0, min2 = 0, idx1 = -1;
	for(int i = 0; i < costs.size(); i++) {
		int m2 = INT_MAX, m1 = m2, id1 = -1;
		for(int j = 0; j < costs[0].size(); j++) {
			int cost = costs[i][j] + (j == idx1 ? min2 : min1);
			if(cost < m1) {
				m2 = m1;
				m1 = cost;
				id1 = j;
			} else if(cost < m2) {
				m2 = cost;
			}
		}
		min2 = m2;
		min1 = m1;
		idx1 = id1;
	}
	return min1;
}
/*
int main() {
	vector<vector<int>> costs;
	vector<int> c1; c1.push_back(1);c1.push_back(5);c1.push_back(3);
	vector<int> c2; c2.push_back(2);c2.push_back(9);c2.push_back(4);
	costs.push_back(c1);costs.push_back(c2);
	cout << minCostPaintHouses2(costs) << endl;

	return 0;
}*/
