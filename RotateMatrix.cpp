#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/rotate-image/
 * You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
https://leetcode.com/problems/rotate-image/discuss/448881/Easy-to-understand-C%2B%2B-Solution
 */

void printMatrix(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
//+90 clockwise
void rotate(vector<vector<int>>& matrix) {
	int m = matrix.size();
	if(m == 0) return;
	int n = matrix[0].size();
	if(n == 0) return;

	for(int i = 0; i < n/2; i++) {
		for(int j = i+1; j < n-i; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[n-j-1][i];
			matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
			matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
			matrix[j][n-i-1] = temp;
		}
	}
}

//-90 clockwise
void rotatAntiClock(vector<vector<int>>& matrix) {
	int m = matrix.size();
	if(m == 0) return;
	int n = matrix[0].size();
	if(n == 0) return;

	for(int i = 0; i < n/2; i++) {
		for(int j = i+1; j < n-i; j++) {
			cout << "---" << endl;
			int temp = matrix[i][j];
			matrix[i][j] =  matrix[j][n-i-1];
			matrix[j][n-i-1] = matrix[n-i-1][n-j-1];
			matrix[n-i-1][n-j-1] = matrix[n-j-1][i];
			matrix[n-j-1][i] = temp;
			printMatrix(matrix);
		}
	}
}
/*
int main() {
	vector<vector<int>> matrix;
	vector<int> nums; nums.push_back(1);nums.push_back(2);nums.push_back(3);
	vector<int> nums1; nums1.push_back(4);nums1.push_back(5);nums1.push_back(6);
	vector<int> nums2; nums2.push_back(7);nums2.push_back(8);nums2.push_back(9);
	matrix.push_back(nums);matrix.push_back(nums1);matrix.push_back(nums2);
	print(matrix);
	rotatAntiClock(matrix);
	cout << "---" << endl;
	print(matrix);

	return 0;
}*/
