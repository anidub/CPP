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
/*https://leetcode.com/problems/rotting-oranges/
 * You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
https://leetcode.com/problems/rotting-oranges/discuss/588024/C%2B%2B-or-BFS-or-100-Space-95-time-or-explanation-of-logic
 */
//TC : O(M * N) , SC: O(m * n)
int daysForRottingOranges(vector<vector<int>>& grid) {
	if(grid.empty()) return 0;
	vector<int> dirs = {0, 1, 0, -1, 0};
	int fresh = 0;
	int m = grid.size(), n = grid[0].size();
	queue<pair<int, int>> q;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == 2)
				q.push({i, j});
			if(grid[i][j] == 1)
				fresh++;
		}
	}
	int ans = -1;
	while(!q.empty()) {
		int sz = q.size();
		while(sz--) {
			pair<int, int> p = q.front(); q.pop();
			for(int i = 0; i < 4; i++) {
				int r = p.first + dirs[i];
				int c = p.second + dirs[i + 1];
				if(r >= 0 && c >= 0 && r < m && c < n &&  grid[r][c] == 1) {
					grid[r][c] = 2;
					q.push({ r, c });
					fresh--;
				}
			}
		}
		ans++;
	}
	if(fresh > 0) return -1;
	if(ans ==  -1) return 0;
	return ans;
}
/*
int main() {
	vector<vector<int>> grid = {{2,1,1}, {0,1,1}, {1,0,1}};
	cout << daysForRottingOranges(grid) << endl;
	return 0;
}*/
