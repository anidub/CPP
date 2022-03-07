#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode.com/problems/matrix-diagonal-sum/
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once. */

int diagonalSum(vector<vector<int>>& matrix) {
	int sum = 0;
	int N = matrix.size();
	if(N == 0) return sum;
	for(int i = 0, j = 0; i < N; i++,j++) {
		sum += matrix[i][j]; //diagonal top left to bottom right
	}

	for(int i = N-1, j = 0; i >= 0; i--, j++) {  //diagonal top right to bottom left
		sum += matrix[i][j];
	}

	if(N % 2) //remove duplicates
		sum -= matrix[N/2][N/2];

	cout << sum;
	return sum;
}
/*
int main() {
	vector<int> nums;vector<int> nums1;vector<int> nums2;
	vector<vector<int>> matrix;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);
	nums1.push_back(4);nums1.push_back(5);nums1.push_back(6);
	nums2.push_back(7);nums2.push_back(8);nums2.push_back(9);

	matrix.push_back(nums);matrix.push_back(nums1); matrix.push_back(nums2);
	diagonalSum(matrix);

	return 0;
} */
