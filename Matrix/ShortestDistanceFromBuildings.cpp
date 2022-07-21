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
/*https://leetcode.com/problems/shortest-distance-from-all-buildings/
 * You are given an m x n grid grid of values 0, 1, or 2, where:

each 0 marks an empty land that you can pass by freely,
each 1 marks a building that you cannot pass through, and
each 2 marks an obstacle that you cannot pass through.
You want to build a house on an empty land that reaches all buildings in the shortest total travel distance. You can only move up, down, left, and right.

Return the shortest travel distance for such a house. If it is not possible to build such a house according to the above rules, return -1.

The total travel distance is the sum of the distances between the houses of the friends and the meeting point.

The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
Input: grid = [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
Output: 7
Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2).
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal.
So return 7.

https://leetcode.com/problems/shortest-distance-from-all-buildings/discuss/76880/36-ms-C%2B%2B-solution : comments
solution : used
follow diagram of solution to understand...check both grid and total matrix
 */

//TC: O(N^2M^2), SC : O(NM)
int shortestDistanceFromAllBuildings(vector<vector<int>>& grid) {
	if(grid.empty()) return 0;
	int rows = grid.size();
	int cols = grid[0].size();

	vector<vector<int>> dirs = { {-1, 0}, {0, 1}, {1,0}, {0, -1}  };
	int minDistance = INT_MAX;

	vector<vector<int>> total(rows, vector<int>(cols, 0));

	int minDist = INT_MAX;
	int emptyLand = 0;


	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(grid[i][j] != 1) continue;

			queue<pair<int, int>> q;
			q.push({i, j});
			minDist = INT_MAX;

			int steps = 0;
			while(!q.empty()) {
				steps++;
				for(int level = q.size(); level > 0; level--) {
					auto curr = q.front(); q.pop();

					for(auto &d : dirs) {
						int next_row = curr.first + d[0];
						int next_col = curr.second + d[1];

						if(next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols &&
							grid[next_row][next_col] == emptyLand) {
								grid[next_row][next_col]--;
								total[next_row][next_col] += steps;
								q.push({next_row, next_col});
								minDist = min(minDist, total[next_row][next_col]);
						}
					}
				}
			}
			emptyLand--;
		}
	}
	return minDist == INT_MAX ? -1 : minDist;
}

/*
int main() {
	vector<vector<int>> grid = {{1,0,2,0,1},{0,0,0,0,0}, {0,0,1,0,0}};
	cout << shortestDistanceFromAllBuildings(grid) << endl;

	return 0;
}*/
