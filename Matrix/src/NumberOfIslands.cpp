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
/*https://leetcode.com/problems/number-of-islands/
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
https://leetcode.com/problems/number-of-islands/discuss/56589/C%2B%2B-BFSDFS
 */
//TC : O(MN), sc : o(row)
void processIslands(vector<vector<char>>& grid, int i, int j);
int numIslands(vector<vector<char>>& grid) {
	int islands = 0;
	if(grid.empty()) return 0;
	int m = grid.size(), n = grid[0].size();

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == '1') {
				islands++;
				processIslands(grid, i, j);
			}
		}
	}
	return islands;
}
//    //time: o(row * column) //space: o(column)
void processIslands(vector<vector<char>>& grid, int i, int j) {
	int m = grid.size(), n = grid[0].size();
	if(i < 0 || j < 0 || i == m || j == n || grid[i][j] == '0')
		return;
	grid[i][j] = '0';
	processIslands(grid, i+1, j);
	processIslands(grid, i-1, j);
	processIslands(grid, i, j+1);
	processIslands(grid, i, j-1);
}

int numIslandsBFS(vector<vector<char>>& grid) {
	int islands = 0;
	if(grid.empty()) return 0;
	int m = grid.size(), n = grid[0].size();
	int offsets[] = {0, 1, 0, -1, 0};

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == '1') {
				islands++;
				grid[i][j] = '0';
				queue<pair<int, int>> todo;
				todo.push({i, j});
				while(!todo.empty()) {
					pair<int, int> p = todo.front();
					todo.pop();
					for(int k = 0; k < 4 ; k++) {
						int r = p.first + offsets[k], c = p.second + offsets[k+1];
						if(r < 0 || r == m || c < 0 || c == n || grid[r][c] == '0')
							continue;
						grid[r][c] = '0';
						todo.push({r, c});
					}
				}

			}
		}
	}
	return islands;
}
/*
int main() {
	vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'} };
	cout << numIslands(grid) << endl;

	return 0;
}*/
