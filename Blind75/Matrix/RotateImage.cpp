#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/rotate-image/
 * You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]


https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
https://leetcode.com/problems/rotate-image/discuss/1449737/Rotation-90Code-180-270-360-explanation-Inplace-O(1)-Space

 */
class RotateImage {
public:
	//TC:O(M), SC:O(1)
	void rotate(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if(m == 0) return;
		int n = matrix[0].size();
		if(n == 0) return;

		for(int i = 0; i < n / 2; i++) {
			for(int j = i + 1; j < n - i; j++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[n - j - 1][i];
				matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
				matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
				matrix[j][n - i - 1] = temp;
			}
		}
	}

	/*
	 * clockwise rotate
	 * first reverse up to down, then swap the symmetry
	 * 1 2 3     7 8 9     7 4 1
	 * 4 5 6  => 4 5 6  => 8 5 2
	 * 7 8 9     1 2 3     9 6 3
	*/
	void rotateEasy(vector<vector<int> > &matrix) {
	    reverse(matrix.begin(), matrix.end());
	    for (int i = 0; i < matrix.size(); ++i) {
	        for (int j = i + 1; j < matrix[i].size(); ++j)
	            swap(matrix[i][j], matrix[j][i]);
	    }
	}

	/*
	 * anticlockwise rotate
	 * first reverse left to right, then swap the symmetry
	 * 1 2 3     3 2 1     3 6 9
	 * 4 5 6  => 6 5 4  => 2 5 8
	 * 7 8 9     9 8 7     1 4 7
	*/
	void anti_rotate(vector<vector<int> > &matrix) {
	    for (auto vi : matrix) reverse(vi.begin(), vi.end());
	    for (int i = 0; i < matrix.size(); ++i) {
	        for (int j = i + 1; j < matrix[i].size(); ++j)
	            swap(matrix[i][j], matrix[j][i]);
	    }
	}
};
/*
int main() {
	RotateImage ri;
	vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
	ri.rotate(mat);
}
*/
