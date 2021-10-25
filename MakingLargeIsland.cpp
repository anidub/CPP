#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/making-a-large-island/
 * You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.
Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
https://leetcode.com/problems/making-a-large-island/discuss/127015/C%2B%2B-with-picture-O(n*m) : comments
 */
//On*m)
int paint(vector<vector<int>>& grid, int i, int j, int color) {
	if(i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || grid[i][j] != 1) return 0;
	grid[i][j] = color;
	return 1 + paint(grid, i+1, j, color) + paint(grid, i-1, j, color) + paint(grid, i, j-1, color) + paint(grid, i, j+1, color);
}

int makeLargestIsland(vector<vector<int>>& grid) {
	if(grid.empty() || grid[0].empty()) return 0;
	unordered_map<int, int> map;//Key: color, Val: size of island painted of that color
	map[0] = 0;//We won't paint island 0, hence make its size 0, we will use this value later
	int n = grid.size();
	int colorIndex = 2; //0 and 1 is already used in grid, hence we start colorIndex from 2

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == 1) {
				int size = paint(grid, i, j, colorIndex);
				map[colorIndex] = size;
				colorIndex++;
			}
		}
	}
    //If there is no island 0 from grid, res should be the size of islands of first color
    //If there is no island 1 from grid, res should be 0
	int res = map[2];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == 0) {
				//We use a set to avoid repeatly adding islands with the same color
				unordered_set<int> set;
				//If current island is at the boundary, we add 0 to the set, whose value is 0 in the map
				set.insert(i > 0 ? grid[i-1][j] : 0);
				set.insert(i < n-1 ? grid[i+1][j] : 0);
				set.insert(j > 0 ? grid[i][j-1] : 0);
				set.insert(j < n-1 ? grid[i][j+1] : 0);
				int newSize = 1;//We need to count current island as well, hence we init newSize with 1
				for(int color : set) newSize += map[color];
				res = max(res, newSize);
			}
		}
	}
	return res;
}

/*
int main() {
	vector<vector<int>> grid;
	vector<int> g1; g1.push_back(1);g1.push_back(0);
	vector<int> g2; g2.push_back(0);g2.push_back(1);
	grid.push_back(g1);grid.push_back(g2);

	cout << makeLargestIsland(grid) << endl;

	return 0;
}*/
