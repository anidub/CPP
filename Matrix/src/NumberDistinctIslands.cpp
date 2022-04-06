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
/*https://leetcode.com/problems/number-of-distinct-islands/
 * You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Return the number of distinct islands
https://leetcode.com/problems/number-of-distinct-islands/discuss/231041/C%2B%2B-BFSDSS
 */
void numDistinctIslandsHelper(int i, int j, string &path, vector<vector<int>> &grid, char dir);

//TC: O(MN), SC: O(MN)
int numDistinctIslands(vector<vector<int>>& grid) {
	if(grid.empty()) return 0;
	unordered_set<string> s;

	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			string path;
			if(grid[i][j])
				numDistinctIslandsHelper(i, j, path, grid, 'x');
			if(!path.empty()) s.insert(path);
		}
	}
	return s.size();
}

void numDistinctIslandsHelper(int i, int j, string &path, vector<vector<int>> &grid, char dir) {
	if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0)
		return;
	path.push_back(dir);
	grid[i][j] = 0;

	numDistinctIslandsHelper(i + 1, j, path, grid, 'd');
	numDistinctIslandsHelper(i - 1, j, path, grid, 'u');
	numDistinctIslandsHelper(i, j + 1, path, grid, 'r');
	numDistinctIslandsHelper(i, j - 1, path, grid, 'l');

	path.push_back('b');
}
/*
int main() {
	vector<vector<int>> grid = {{1,1,0,1,1},{1,0,0,0,0},{0,0,0,0,1},{1,1,0,1,1}};
	cout << numDistinctIslands(grid) << endl;

	return 0;
}*/
