#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <queue>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/shortest-bridge/
 * You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
https://leetcode.com/problems/shortest-bridge/discuss/189293/C%2B%2B-BFS-Island-Expansion-%2B-UF-Bonus : comments sumedha093

 */

void shortestBridgeFindIsland(int x, int y, queue<pair<int, int>> &queue, vector<vector<int>>& A);
//Time complexity O(MN) Space complexity O(MN)
int shortestBridge(vector<vector<int>>& A) {
	if(A.empty()) return 0;
	queue<pair<int, int>> q;
	bool flag = false;

	for(int i = 0; i < A.size(); i++) {
		for(int j = 0; j < A[0].size(); j++) {
			if(A[i][j] == 1) {
				shortestBridgeFindIsland(i, j, q, A);
				flag = true;
				break;
			}
		}
		if(flag) break;
	}

	int steps = 0;
	vector<vector<int>> dirs = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

	while(!q.empty()) {
		int sz = q.size();
		for(int i = 0; i < sz; i++) {
			auto point = q.front(); q.pop();
			for(auto dir : dirs) {
				int x = point.first + dir[0];
				int y = point.second + dir[1];
				if(x >= 0 && y >= 0 && x  < A.size() && y < A[0].size() && A[x][y] != -1) {
					if(A[x][y] == 1) return steps;
					q.push({x, y});
					A[x][y] = -1;
				}
			}
		}
		steps++;
	}
	return -1;
}

void shortestBridgeFindIsland(int x, int y, queue<pair<int, int>> &queue, vector<vector<int>>& A) {
	if(x < 0 || y < 0 || x == A.size() || y == A[0].size() || A[x][y] != 1) return;
	queue.push({x, y});
	A[x][y] = -1;
	shortestBridgeFindIsland(x + 1, y, queue, A);
	shortestBridgeFindIsland(x - 1, y, queue, A);
	shortestBridgeFindIsland(x, y + 1, queue, A);
	shortestBridgeFindIsland(x, y - 1, queue, A);
}

/*
int main() {
	vector<vector<int>> grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
	cout << shortestBridge(grid) << endl;

	return 0;
}
*/
