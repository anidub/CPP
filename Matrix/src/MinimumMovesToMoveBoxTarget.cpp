#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <queue>
#include <set>

using namespace std;
/*https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/
 * A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.

The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.

Your task is to move the box 'B' to the target position 'T' under the following rules:

The character 'S' represents the player. The player can move up, down, left, right in grid if it is a floor (empty cell).
The character '.' represents the floor which means a free cell to walk.
The character '#' represents the wall which means an obstacle (impossible to walk there).
There is only one box 'B' and one target cell 'T' in the grid.
The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
The player cannot walk through the box.
Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.
Input: grid = [['#','#','#','#','#','#'],
               ['#','T','#','#','#','#'],
               ['#','.','.','B','.','#'],
               ['#','.','#','#','.','#'],
               ['#','.','.','.','S','#'],
               ['#','#','#','#','#','#']]
Output: 3
Explanation: We return only the number of times the box is pushed.

 *https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/discuss/1265127/C%2B%2B-Accepted-Clear-solution-to-understand-for-this-long-problem-with-proper-variable-names

 */

int m_, n_;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool inside(int x, int y) {
	return (x >= 0 && x < m_ && y >= 0 && y < n_);
}

bool canWalk(int srcX, int srcY, int destX, int destY, vector<vector<char>> &grid, vector<vector<int>> &visited) {
	if(srcX == destX && srcY == destY) return true;
	visited[srcX][srcY] = 1;

	for(int i = 0; i < 4; i++) {
		int x = srcX + dir[i][0];
		int y = srcY + dir[i][1];

		if( inside(x, y) && !visited[x][y] && grid[x][y] != '#') {
			if(canWalk(x, y, destX, destY, grid, visited)) return true;
		}
	}
	return false;
}

int minPushBox(vector<vector<char>>& grid) {
	m_ = grid.size(), n_ = grid[0].size();
	int boxX, boxY, personX, personY, targetX, targetY;

	for(int i = 0; i < m_; i++) {
		for(int j = 0; j < n_; j++) {
			if(grid[i][j] == 'S') {
				personX = i, personY = j;
			} else if(grid[i][j] == 'B') {
				boxX = i, boxY = j;
			} else if(grid[i][j] == 'T') {
				targetX = i, targetY = j;
			}
		}
	}
	queue<vector<int>> q;
	set<vector<int>> seen;
	q.push({boxX, boxY, personX, personY});
	int ans = 0;
	while(!q.empty()) {
		int sz = q.size();
		while(sz--) {
			auto p = q.front(); q.pop();
			boxX = p[0]; boxY = p[1]; personX = p[2]; personY = p[3];
			if(boxX == targetX && boxY == targetY) return ans;

			grid[boxX][boxY] = '#';
			for(int i = 0; i < 4; i++) {
				int new_boxX = boxX + dir[i][0], new_boxY = boxY + dir[i][1];
				int new_personX = boxX - dir[i][0], new_personY = boxY - dir[i][1];

				vector<int> curPos = {new_boxX, new_boxY, new_personX, new_personY};
				vector<vector<int>> visited(m_, vector<int>(n_, 0));

				if( inside(new_boxX, new_boxY) && grid[new_boxX][new_boxY] != '#' && !seen.count(curPos)  &&
						canWalk(personX, personY, new_personX, new_personY, grid, visited)) {
					q.push(curPos);
					seen.insert(curPos);
				}
			}
			grid[boxX][boxY] = '.';
		}
		ans++;
	}
	return -1;
}
/*
int main() {
	vector<vector<char>> grid = { {'#','#','#','#','#','#'},
								 {'#','T','.','.','#','#'},
								 {'#','.','#','B','.','#'},
								 {'#','.','.','.','.','#'},
								 {'#','.','.','.','S','#'},
								 {'#','#','#','#','#','#'} };
	cout << minPushBox(grid) << endl;

	return 0;
}*/
