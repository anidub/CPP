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
/*https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 * Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/discuss/1151423/C%2B%2B-Optimization-from-Brute-Force-to-DP-or-Easy-Solution-w-Explanation
 */

vector<vector<int>> LIP_DP;// dp[i][j] will store maximum path length starting from matrix[i][j]
int maxPath, m, n;
int moves[4][2] = {{-1,0}, {0, 1}, {1,0}, {0, -1}};//directions

int solveLongestIncreasingPath(vector<vector<int>>& matrix, int i, int j);
//Time Complexity : O(NM)  Space Complexity : O(NM)
int longestIncreasingPath(vector<vector<int>>& matrix) {
	if(matrix.empty()) return 0;
	maxPath = 0, m = matrix.size(), n = matrix[0].size();
	LIP_DP.resize(m, vector<int>(n));

	// calculating maximum path from each cell and at last returning the maximum length
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			maxPath = max(maxPath, solveLongestIncreasingPath(matrix, i, j));
		}
	}
	return maxPath;
}

int solveLongestIncreasingPath(vector<vector<int>>& matrix, int i, int j) {
	if(LIP_DP[i][j]) return LIP_DP[i][j];// return if result is already calculated
	LIP_DP[i][j] = 1; // minimum path from each cell is always atleast 1

	for(int k = 0; k < 4; k++) {
		int new_i = i + moves[k][0], new_j = j + moves[k][1];
		// bound checking as well as move to next cell only when it is greater in value
		if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || matrix[new_i][new_j] <= matrix[i][j]) continue;
		// max( current optimal, select current + optimal solution after moves[k] from current cell
		LIP_DP[i][j] = max(LIP_DP[i][j], 1 + solveLongestIncreasingPath(matrix, new_i, new_j));
	}
	return LIP_DP[i][j];
}

/*
int main() {
	vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
	cout << longestIncreasingPath(matrix) << endl;

	return 0;
}
*/
