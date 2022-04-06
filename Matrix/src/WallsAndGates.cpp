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
/*https://leetcode.com/problems/walls-and-gates/
 * You are given an m x n grid rooms initialized with these three possible values.

-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

https://leetcode.com/problems/walls-and-gates/discuss/72793/C%2B%2B-BFS-clean-solution-with-simple-explanations
 */

//TC: O(MN), SC: O(MN)
void wallsAndGates(vector<vector<int>>& rooms) {
	if(rooms.empty()) return;
	const int rows = rooms.size();
	const int cols = rooms[0].size();

	vector<vector<int>> dirs = { {-1,0}, {0,1}, {1,0}, {0,-1} };

	queue<pair<int, int>> canReach;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(rooms[i][j] == 0)
				canReach.push({i, j});
		}
	}

	while(!canReach.empty()) {
		int r = canReach.front().first, c = canReach.front().second;
		canReach.pop();
		for(auto &dir : dirs) {
			int x = r + dir[0], y = c + dir[1];
			if(x < 0 || y < 0 || x >= rows || y >= cols || rooms[x][y] < INT_MAX) continue;
			rooms[x][y] = 1 + rooms[r][c];
			canReach.push({x, y});
		}
	}
}
/*
int main() {
	vector<vector<int>> rooms = {{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},{2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
	wallsAndGates(rooms);
	return 0;
}*/
