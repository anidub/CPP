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
/*https://leetcode.com/problems/shortest-path-in-binary-matrix/
 * Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
 *
 * https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/312711/C%2B%2B-BFS : comments using visited
 *
 * https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/312814/simple-BFS-C%2B%2B : used
 */

//TC : O(N), SC : O(N).The additional space we used was the queue. We determined that at most, we enqueued N cells. Therefore, an upper bound on the worst-case space complexity is O(N)
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
	if(grid.empty()) return -1;
	int row = grid.size(), col = grid[0].size();
	if(grid[0][0] != 0 || grid[row-1][col-1]) return -1;

	queue<pair<int, int>> queue;
	queue.push(make_pair(0, 0));

	vector<vector<int>> dirs = { {-1, 0}, {-1, 1}, {0, 1}, {1,1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

	grid[0][0] = 1;
	while(!queue.empty()) {
		auto curr = queue.front();
		queue.pop();
		int x = curr.first , y = curr.second;

		if(x == row - 1 && y == col - 1) return grid[x][y]; // to store total distance covered

		for(auto &dir : dirs) {
			int nx = x + dir[0];
			int ny = y + dir[1];

			if(nx >= 0 && ny >= 0 && nx < row && ny < col && grid[nx][ny] == 0) {
				queue.push(make_pair(nx, ny));
				grid[nx][ny] = grid[x][y] + 1; // increment dist by 1
			}
		}
	}
	return -1;
}

/*
int main() {
	vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};

	cout << shortestPathBinaryMatrix(grid) << endl;

	return 0;
}*/
