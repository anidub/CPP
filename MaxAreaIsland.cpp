#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/max-area-of-island/
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
https://leetcode.com/problems/max-area-of-island/discuss/251369/C%2B%2B-BFS-and-DFS
 */
int maxAreaIslandIterative(vector<vector<int>>& grid) {
	int m = grid.size(); int n = grid[0].size();
	int maxarea = 0; int offset[] = {0, 1, 0 , -1, 0};

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j]) {
				grid[i][j] = 0;
				int a = 1;
				queue<pair<int, int>> todo;
				todo.push({i, j});
				while(!todo.empty()) {
					pair<int, int> p = todo.front();
					todo.pop();
					for(int k = 0; k < 4; k++) {
						int r = p.first + offset[k];
						int c = p.second + offset[k+1];
						if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c]) {
							grid[r][c] = 0;
							todo.push({r, c});
							a++;
						}
					}
				}
				maxarea = max(maxarea, a);
			}
		}
	}
	return maxarea;
}

void maxAreaUtil(int i, int j, int& a, vector<vector<int>>& grid) {
	int m = grid.size(); int n = grid[0].size();
	if(i >= 0 && j >= 0 && i < m && j < n && grid[i][j]) {
		a++;
		grid[i][j] = 0;
		maxAreaUtil(i+1, j, a, grid);
		maxAreaUtil(i-1, j, a, grid);
		maxAreaUtil(i, j+1, a, grid);
		maxAreaUtil(i, j-1, a, grid);
	}
}

int maxAreaIslandRecursive(vector<vector<int>>& grid) {
	int m = grid.size(); int n = grid[0].size();
	int maxarea = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j]) {
				int a = 0;
				maxAreaUtil(i, j, a, grid);
				maxarea = max(maxarea, a);
			}
		}
	}
	return maxarea;
}
/*
int main() {

	return 0;
}*/
