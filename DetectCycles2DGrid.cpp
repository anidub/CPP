#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;

/*https://leetcode.com/problems/detect-cycles-in-2d-grid/
 * Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.
 * Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
https://leetcode.com/problems/detect-cycles-in-2d-grid/discuss/805742/C%2B%2B-or-DFS-or-Easy-to-understand
 */
///Time: O(N*M)
vector<int> dirs = {0, 1, 0, -1, 0};
bool isCyclic2DGrid(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int x, int y) {
	visited[i][j] = true;
	for(int d = 0; d < 4; d++) {
		int a = i + dirs[d];
		int b = j + dirs[d+1];
		if(a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == grid[i][j] && !(x == a && y == b))
			if(visited[a][b] || isCyclic2DGrid(grid, visited, a, b, i, j))
				return true;
	}
	return false;
}

bool containsCycle2DGrid(vector<vector<char>>& grid) {
	if(grid.empty()) return false;
	int n = grid.size(), m = grid[0].size();
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!visited[i][j] && isCyclic2DGrid(grid, visited, i, j, -1, -1))
				return true;
		}
	}
	return false;
}

/*
int main() {
	vector<vector<char>> grid;
	vector<char> g1; g1.push_back('a');g1.push_back('a');g1.push_back('a');g1.push_back('a');
	vector<char> g2; g2.push_back('a');g2.push_back('b');g2.push_back('b');g2.push_back('a');
	vector<char> g3; g3.push_back('a');g3.push_back('b');g3.push_back('b');g3.push_back('a');
	vector<char> g4; g4.push_back('a');g4.push_back('a');g4.push_back('a');g4.push_back('a');
	grid.push_back(g1);grid.push_back(g2);grid.push_back(g3);grid.push_back(g4);
	cout << containsCycle2DGrid(grid) << endl;

	return 0;
}
*/
