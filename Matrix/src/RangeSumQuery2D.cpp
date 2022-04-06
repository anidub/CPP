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
/*https://leetcode.com/problems/range-sum-query-2d-immutable/
 * Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

 * https://leetcode.com/problems/range-sum-query-2d-immutable/discuss/75350/Clean-C%2B%2B-Solution-and-Explaination-O(mn)-space-with-O(1)-time : explained in diagrams
 * https://leetcode.com/problems/range-sum-query-2d-immutable/discuss/572648/C%2B%2BJavaPython-Prefix-sum-with-Picture-explain-Clean-and-Concise
 */

class NumMatrix {
public:
	vector<vector<int>> sum;
	//Time : O(m*n), Space :  O(m*n)
	NumMatrix(vector<vector<int>> &matrix) {
		int m = matrix.size(), n = matrix[0].size();
		sum = vector<vector<int>> (m + 1, vector<int>(n + 1));// sum[i][j] is sum of all elements inside the rectangle [0,0,i,j]

		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				sum[i][j] = matrix[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
		}
	}
	//Time & Space: O(1)
	int sumRegion(int r1, int c1, int r2, int c2) {
		r1++; c1++; r2++; c2++;

		return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];

	}
};
/*
int main() {
	vector<vector<int>> matrix = {  {3, 0, 1, 4, 2},
									{5, 6, 3, 2, 1},
									{1, 2, 0, 1, 5},
									{4, 1, 0, 1, 7},
									{1, 0, 3, 0, 5} };
	NumMatrix* obj = new NumMatrix(matrix);
	int param_1 = obj->sumRegion(2, 1, 4, 3);
	cout << param_1 << endl;
	return 0;
}*/
