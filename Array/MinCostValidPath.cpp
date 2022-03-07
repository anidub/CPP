#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
 * Given a m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
Notice that there could be some invalid signs on the cells of the grid which points outside the grid.

You will initially start at the upper left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path doesn't have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.
Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
Output: 3
Explanation: You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
The total cost = 3.
https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/discuss/809921/C%2B%2B-bfs : used
https://www.youtube.com/watch?v=Hvbjx9AUX9Y
https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
 */
struct Data {
	int i;
	int j;
	int cost;
	bool operator<(const Data& rhs) const { //operator overload for priority queue
		return cost > rhs.cost;
	}
};

int minCostValidPath(vector<vector<int>>& grid) {
	if(grid.empty() || grid[0].size() == 0) return -1;
	int n = grid.size(); int m = grid[0].size();
	vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
	priority_queue<Data> q;
	q.push(Data{0,0,0});
	while(!q.empty()) {
		auto [i,j,cost] = q.top(); q.pop();
		if(i==n-1 && j==m-1) return cost;
		if(grid[i][j] == -1) continue;
		const int path = grid[i][j];
		grid[i][j] = -1;
		for(int k = 0; k < 4; k++) {
			int x = i + dirs[k][0];
			int y = j + dirs[k][1];
			if(x < 0 || x >= n || y < 0 || y >= m) continue;
			int dCost = path == k+1 ? 0 : 1; // add 1 to change direction else keep same
			q.push(Data{x,y,cost+dCost});
		}
	}
	return -1;
}
/*
int main() {
	vector<vector<int>> grid;
	vector<int> v1; v1.push_back(1);v1.push_back(1);v1.push_back(1);v1.push_back(1);
	vector<int> v2; v2.push_back(2);v2.push_back(2);v2.push_back(2);v2.push_back(2);
	vector<int> v3; v3.push_back(1);v3.push_back(1);v3.push_back(1);v3.push_back(1);
	vector<int> v4; v4.push_back(2);v4.push_back(2);v4.push_back(2);v4.push_back(2);
	grid.push_back(v1);grid.push_back(v2);grid.push_back(v3);grid.push_back(v4);
	cout << minCostValidPath(grid) << endl;

	return 0;
}*/
