#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <stack>

using namespace std;
/*
 * https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/submissions/
 * You are given a rows x cols matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.
Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (rows - 1, cols - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative return -1.
Notice that the modulo is performed after getting the maximum product.
Example 1:
Input: grid = [[-1,-2,-3],
               [-2,-3,-3],
               [-3,-3,-2]]
Output: -1
Explanation: It's not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/discuss/855082/C%2B%2B-Dynamic-Programming-With-Comments : used
https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/discuss/884506/C%2B%2B-Straightforward-Bottom-Up-DP-(Track-Max-and-Min)-with-Brief-Explanation
 */

//O(M*N)
int maxNonNegativeProduct(vector<vector<int>>& grid) {
	if(grid.empty() || grid[0].empty()) return 0;
	int m = grid.size(), n = grid[0].size();

	vector<vector<long long>> mx(m, vector<long long>(n));
	vector<vector<long long>> mn(m, vector<long long>(n));

	mx[0][0] = mn[0][0] = grid[0][0];

	for(int i = 1; i < m; i++)
		mx[i][0] = mn[i][0] = mx[i-1][0] * grid[i][0];

	for(int j = 1; j < n; j++)
		mx[0][j] = mn[0][j] = mn[0][j-1] * grid[0][j];

	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			if(grid[i][j] < 0) {
				mx[i][j] = min(mn[i-1][j], mn[i][j-1]) * grid[i][j];
				mn[i][j] = max(mx[i-1][j], mx[i][j-1]) * grid[i][j];
			} else {
				mx[i][j] = max(mx[i-1][j], mx[i][j-1]) * grid[i][j];
				mn[i][j] = min(mn[i][j-1], mn[i-1][j]) * grid[i][j];
			}
		}
	}

	int mod = 1e9 + 7;
	int result = mx[m-1][n-1] % mod;
	return result < 0 ? -1 : result;
}
/*
int main() {
	vector<vector<int>> grid;
	vector<int> g1; g1.push_back(1);g1.push_back(3);
	vector<int> g2; g2.push_back(0);g2.push_back(-4);
	grid.push_back(g1); grid.push_back(g2);
	cout << maxNonNegativeProduct(grid) << endl;

	return 0;
}*/
