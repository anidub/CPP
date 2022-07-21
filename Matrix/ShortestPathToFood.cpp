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
/*https://leetcode.com/problems/shortest-path-to-get-food/
 * You are starving and you want to eat food as quickly as possible. You want to find the shortest path to arrive at any food cell.

You are given an m x n character matrix, grid, of these different types of cells:

'*' is your location. There is exactly one '*' cell.
'#' is a food cell. There may be multiple food cells.
'O' is free space, and you can travel through these cells.
'X' is an obstacle, and you cannot travel through these cells.
You can travel to any adjacent cell north, east, south, or west of your current location if there is not an obstacle.

Return the length of the shortest path for you to reach any food cell. If there is no path for you to reach food, return -1.

 *
 *
 * Input: grid = [['X','X','X','X','X','X'],['X','*','O','O','O','X'],['X','O','O','#','O','X'],['X','X','X','X','X','X']]
Output: 3
Explanation: It takes 3 steps to reach the food.


https://leetcode.com/problems/shortest-path-to-get-food/discuss/1208913/C%2B%2B-Detailed-BFS-solution-with-comments

If you want to calculate the minimum moves to collect all the food then it is basically a version of the "Travelling salesman problem".
 */

//TC: O(m*n). SC : O(m*n)
int shortestPathGetFood(vector<vector<char>>& grid) {
	if(grid.empty()) return 0;
	int m = grid.size(), n = grid[0].size();

	vector<vector<int>> dirs = { {-1, 0}, {0, 1}, {1,0}, {0,-1} };// To traverse in all directions i.e. north, east, south, and west
	int steps = 0;
	queue<pair<int, int>> q;

	// Get the starting location in the Grid
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == '*') {
				q.push(make_pair(i, j));
				break;// We found the starting place. Now, break from this loop.
			}
		}
	}

	while(!q.empty()) {
		steps++;
		int sz = q.size();
		for(int i = 0; i < sz; i++) {
			auto elem = q.front(); q.pop();
			for(int i = 0; i < dirs.size(); i++) { // Traverse in each directions i.e.  north, east, south, and west
				int x = elem.first + dirs[i][0];
				int y = elem.second + dirs[i][1];

				if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 'X') // If obstacle or reaching boundaries just continue
					continue;

				if(grid[x][y] == '#')  // We found the food
					return steps;

				grid[x][y] = 'X';// Mark this cell as visited by putting obstacle ('X')
				q.push(make_pair(x, y));
			}
		}
	}
	return -1;
}
/*
int main() {
	vector<vector<char>> grid = {{'X','X','X','X','X'},
								{'X','*','X','O','X'},
								{'X','O','X','#','X'},
								{'X','X','X','X','X'}};
	cout << shortestPathGetFood(grid) << endl;

	return 0;
}*/
