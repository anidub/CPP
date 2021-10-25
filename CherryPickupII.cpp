#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_set>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/cherry-pickup-ii/
 *Given a rows x cols matrix grid representing a field of cherries. Each cell in grid represents the number of cherries that you can collect.

You have two robots that can collect cherries for you, Robot #1 is located at the top-left corner (0,0) , and Robot #2 is located at the top-right corner (0, cols-1) of the grid.

Return the maximum number of cherries collection using both robots  by following the rules below:

From a cell (i,j), robots can move to cell (i+1, j-1) , (i+1, j) or (i+1, j+1).
When any robot is passing through a cell, It picks it up all cherries, and the cell becomes an empty cell (0).
When both robots stay on the same cell, only one of them takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in the grid.
Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.

https://leetcode.com/problems/cherry-pickup-ii/discuss/660536/C%2B%2B-with-explanation
 */
int getMaxCherries(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();

	int f[m][n][n];
	//memset(f, -1, sizeof(f));//works
	f[0][0][n-1] = grid[0][0] + grid[0][n-1];
	int result = 0;

	for(int i = 1; i < m; i++) {
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++) {
				int value = (j == k) ? grid[i][j] : grid[i][j] + grid[i][k];
				for(int col1 = j-1; col1 <= j+1; col1++) {
					for(int col2 = k-1; col2 <= k+1; col2++) {
						if(col1 >= 0 && col1 < n && col2 >= 0 && col2 < m && f[i-1][col1][col2] >= 0) {
							f[i][j][k] = max(f[i][j][k], f[i-1][col1][col2] + value);
							if(i == m-1)
								result = max(result, f[i][j][k]);
						}
					}
				}
			}
		}
	}
	return result;
}
/*
int main() {
	vector<vector<int>> grid;
	vector<int> v1; v1.push_back(3);v1.push_back(1);v1.push_back(1);
	vector<int> v2; v2.push_back(2);v2.push_back(5);v2.push_back(1);
	vector<int> v3; v3.push_back(1);v3.push_back(5);v3.push_back(5);
	vector<int> v4; v4.push_back(2);v4.push_back(1);v4.push_back(1);
	grid.push_back(v1);grid.push_back(v2);grid.push_back(v3);grid.push_back(v4);


	return 0;
}*/
