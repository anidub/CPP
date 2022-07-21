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
/*https://leetcode.com/problems/island-perimeter/
 * You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
https://leetcode.com/problems/island-perimeter/discuss/95126/C%2B%2B-solution-with-explanation

find how many 1 in the map. If without the consideration of surrounding cells, the total perimeter should be the total amount of 1 times 4.
find how many cell walls that connect with both lands. We need to deduct twice of those lines from total perimeter
 *
 */
//TC: O(NM), SC: O(1)
int islandPerimeter(vector<vector<int>>& grid) {
	if(grid.empty()) return 0;
	int count = 0, repeat = 0;

	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			if(grid[i][j] == 1) {
				count++;
				if(i != 0 && grid[i - 1][j] == 1) repeat++;
				if(j != 0 && grid[i][j - 1] == 1) repeat++;
			}
		}
	}
	return 4 * count - (repeat * 2);
}
/*
int main() {
	vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
	cout << islandPerimeter(grid) << endl;
	return 0;
}*/
