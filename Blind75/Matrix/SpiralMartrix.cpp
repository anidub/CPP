#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/spiral-matrix/
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

 */
class SpiralMatrix {
public:
	//TC:O(M N), SC:O(1)
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int top = 0, left = 0, down = matrix.size() - 1, right = matrix[0].size() - 1;

		while(left <= right && top <= down) {
			for(int j = left; j <= right; j++) {
				res.push_back(matrix[top][j]);
			}
			top++;

			for(int i = top; i <= down; i++) {
				res.push_back(matrix[i][right]);
			}
			right--;

			if(top <= down) {
				for(int j = right; j >= left; j--) {
					res.push_back(matrix[down][j]);
				}
				down--;
			}
			if(left <= right) {
				for(int i = down; i >= top; i--) {
					res.push_back(matrix[i][left]);
				}
				left++;
			}
		}
		return res;
	}
};

/*
int main() {
	SpiralMatrix sm;
	vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
	sm.spiralOrder(mat);
}*/
