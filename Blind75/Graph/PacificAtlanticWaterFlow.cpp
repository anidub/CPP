#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the
 *  island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c]
 represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west
if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci)
to both the Pacific and Atlantic oceans.


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

https://www.youtube.com/watch?v=krL3r7MY7Dc : problem explained
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/1126937/Pacific-Atlantic-Water-Flow-or-Short-and-Easy-w-Explanation-and-diagrams
 */
class PacificAtlanticWaterFlow {
public:
	int m, n;
	vector<vector<bool>> atlantic, pacific;
	vector<vector<int>> ans;

	//Time Complexity : O(M*N), in worst case, all cells are reachable to both oceans and would be visited twice. This case can occur when all elements are equal.
	//Space Complexity : O(M*N), to mark the atlantic and pacific visited cells.
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		if(heights.empty()) return {};
		m = heights.size(), n = heights[0].size();

		atlantic = pacific = vector<vector<bool>>(m, vector<bool>(n, false));

		// perform dfs from all edge cells (ocean-connected cells)
		for(int i = 0; i < m; i++) {
			dfs(heights, pacific, i, 0);
			dfs(heights, atlantic, i, n - 1);
		}

		for(int i = 0; i < n; i++) {
			dfs(heights, pacific, 0, i);
			dfs(heights, atlantic, m - 1, i);
		}
	}


	void dfs(vector<vector<int>>& heights, vector<vector<bool>> &visited,  int i, int j) {
		if(visited[i][j]) return;

		visited[i][j] = true;

		if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});

		// dfs from current cell only if height of next cell is greater
		if(i - 1 >= 0 && heights[i - 1][j]  >= heights[i][j]) dfs(heights, visited, i - 1, j); // up
		if(j + 1 < n && heights[i][j + 1] >= heights[i][j]) dfs(heights, visited, i, j + 1);//right

		if(i + 1 < m && heights[i + 1][j] >= heights[i][j]) dfs(heights, visited, i + 1, j);//down
		if(j - 1 >= 0 && heights[i][j - 1] >= heights[i][j]) dfs(heights, visited, i, j - 1);//left
	}

};
