#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/unique-paths-ii/
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
https://leetcode.com/problems/unique-paths-ii/discuss/608205/C%2B%2B-or-DP
https://leetcode.com/problems/unique-paths-ii/discuss/23252/4ms-O(n)-DP-Solution-in-C%2B%2B-with-Explanations
 */
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
	if(grid.empty() || grid[0].size() == 0) return 0;
	int m = grid[0].size();
	int n = grid[1].size();

	vector<vector<int>> v (m,vector<int>(n,0));

	for(int j = 0; j < n; j++) {
		if(grid[0][j] == 0)
			v[0][j] = 1;
		else
			break;
	}

	for(int i = 0; i < m; i++) {
		if(grid[i][0] == 0)
			v[i][0] = 1;
		else
			break;
	}

	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			if(grid[i][j] == 1)
				v[i][j] = 0;
			else
				v[i][j] = v[i-1][j] + v[i][j-1];
		}
	}
	return v[m-1][n-1];
}
/*
int main() {
	vector<vector<int>> grid;
	vector<int> v1; v1.push_back(0);v1.push_back(0);v1.push_back(0);
	vector<int> v2; v2.push_back(0);v2.push_back(1);v2.push_back(0);
	vector<int> v3; v3.push_back(0);v3.push_back(0);v3.push_back(0);
	grid.push_back(v1); grid.push_back(v2); grid.push_back(v3);

	cout << uniquePathsWithObstacles(grid) << endl;
	return 0;
}*/
