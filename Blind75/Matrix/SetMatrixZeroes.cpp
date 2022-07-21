#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/set-matrix-zeroes/
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 */
class SetMatrixZeroes {
public:
	//TC:O(MN),SC:O(M + N)
	void setZeroes(vector<vector<int>>& matrix) {
		if(matrix.empty()) return;

		unordered_map<int, int> row, col;

		for(int i = 0; i < matrix.size(); i++) {
			for(int j = 0; j < matrix[0].size(); j++) {
				if(matrix[i][j] == 0) {
					row[i]++;
					col[i]++;
				}
			}
		}

		for(int i = 0; i < matrix.size(); i++) {
			for(int j = 0; j < matrix[0].size(); j++) {
				if(row.count(i) == 1 || col.count(j) == 1)
					matrix[i][j] = 0;
			}
		}
	}

	//TC:O(MN), C:O(1)
	void setZeroesOptimal(vector<vector<int>>& matrix) {
		if(matrix.empty()) return;
		int m = matrix.size();
		int n = matrix[0].size();
		bool row = false, col = false;

		for(int i = 0; i < m; i++){
			if(matrix[i][0] == 0)
				col = true;
		}

		for(int j = 0; j < n; j++) {
			if(matrix[0][j] == false)
				row = true;
		}

		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++) {
				if(matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++) {
				if(matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}

		if(row) {
			for(int i = 0; i < n; i++){
				matrix[0][i] = 0;
			}
		}

		if(col) {
			for(int j = 0; j < m; j++) {
				matrix[j][0] = 0;
			}
		}
	}

	void print(vector<vector<int>>& matrix) {
		cout << endl;
		for(int i = 0; i < matrix.size(); i++) {
			for(int j = 0; j < matrix[0].size(); j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};

/*
int main() {
	vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};
	SetMatrixZeroes smz;
	smz.setZeroesOptimal(mat);

	//smz.setZeroes(mat);
	smz.print(mat);
}
*/
