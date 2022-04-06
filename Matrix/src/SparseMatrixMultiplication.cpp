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
//TC: O(m. p. n). SC: O(p)
vector<vector<int>> multiplySparseMatrixOptimal(vector<vector<int>>& A, vector<vector<int>>& B) {
	int m = A.size(), n = A[0].size(), p = B[0].size();
	vector<vector<int>> ans(m, vector<int>(p, 0));

	for(int j = 0; j < n; j++) {
		vector<int> rowB;
		for(int i = 0; i < p; i++) {
			if(B[j][i]) rowB.push_back(i);
		}

		for(int i = 0; i < m; i++) {
			if(A[i][j]) {
				for(int &k : rowB) {
					ans[i][k] += A[i][j] * B[j][k];
				}
			}
		}
	}
	return ans;
}

vector<vector<pair<int, int>>> compressMatrx(vector<vector<int>> &matrix) {
	int rows = matrix.size(), cols = matrix[0].size();
	vector<vector<pair<int, int>>> compressedMatrix(rows);

	for(int row = 0; row < rows; row++) {
		for(int col = 0; col < cols; col++) {
			if(matrix[row][col] != 0) {
				compressedMatrix[row].push_back({matrix[row][col], col});
			}
		}
	}
	return compressedMatrix;
}
//TC: O(m. k. n). SC:(m.k + k.n) : solution tab
vector<vector<int>> multiplySparseMatrix(vector<vector<int>> &A, vector<vector<int>> &B) {
	int m = A.size(), n = B[0].size();

vector<vector<pair<int, int>>> compA = compressMatrx(A);
vector<vector<pair<int, int>>> compB = compressMatrx(B);

vector<vector<int>> ans(m, vector<int>(n, 0));

for (int mat1Row = 0; mat1Row < m; ++mat1Row) {
    // Iterate on all current 'row' non-zero elements of mat1.
    for (auto [element1, mat1Col] : compA[mat1Row]) {

        // Multiply and add all non-zero elements of mat2
        // where the row is equal to col of current element of mat1.
        for (auto [element2, mat2Col] : compB[mat1Col]) {
            ans[mat1Row][mat2Col] += element1 * element2;
        }
    }
}
return ans;
}
/*
int main() {
	vector<vector<int>> m1 = {{1,0,0},{-1,0,3}};
	vector<vector<int>> m2 = {{7,0,0},{0,0,0}, {0,0,1}};
	multiplySparseMatrixOptimal(m1, m2);
	return 0;
}*/
