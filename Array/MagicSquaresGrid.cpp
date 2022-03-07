#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/magic-squares-in-grid/
 * A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
Given a row x col grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).
Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1 // check link for pictures
https://leetcode.com/problems/magic-squares-in-grid/discuss/194689/100-simple-C%2B%2B-Solution
 */

bool chkIfMagicSq(vector<vector<int>>& grid, int m, int n) {
	if(m + 3 > grid.size()) return false;
	if(n + 3 > grid.size()) return false;

	vector<bool> v(10, false);
	for(int i = m; i < m+3; i++) {
		for(int j = n; j < n+3; j++) {
			v[grid[i][j]] = true;
		}
	}

	int sum = grid[m][n] + grid[m+1][n+1] + grid[m+2][n+2];//diagonal

	//anti diagonal
	if(sum != grid[m][n+2] + grid[m+1][n+1] + grid[m+2][n])
		return false;

	//rows
	for(int i = m; i < m+3; i++) {
		if(grid[i][n] + grid[i][n+1] + grid[i][n+2] != sum)
			return false;
	}

	//columns
	for(int i = n; i < n+3; i++) {
		if(grid[m][i] + grid[m+1][i] + grid[m+2][i] != sum)
			return false;
	}

	//check unique
	for(int i = 1; i <= 9; i++) {
		if(!v[i])
			return false;
	}
	return true;
}

//O(N2)
int magicSquares(vector<vector<int>>& grid) {
	if(grid.empty() || grid[0].size() == 0) return 0;

	int r = grid.size();
	int c = grid[0].size();
	int count = 0;

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(chkIfMagicSq(grid, i, j))
				count++;
		}
	}
	return count;
}

/*
int main() {
	vector<vector<int>> grid;
	vector<int> v1; v1.push_back(4);v1.push_back(3);v1.push_back(8);v1.push_back(4);
	vector<int> v2; v2.push_back(9);v2.push_back(5);v2.push_back(1);v2.push_back(9);
	vector<int> v3; v3.push_back(2);v3.push_back(7);v3.push_back(6);v3.push_back(2);
	grid.push_back(v1); grid.push_back(v2); grid.push_back(v3);

	cout << magicSquares(grid) << endl;
	return 0;
}*/
