#include <iostream>
#include <vector>

using namespace std;
/*
https://leetcode.com/problems/flipping-an-image/
Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
*/
vector<vector<int>> flipAndInvert(vector<vector<int>>& A) {
	if(A.size() == 0 || A[0].size() == 0)
		return {};
	for(auto& row: A)
		//reverse(row.begin(), row.end()); //works

	for(size_t row = 0; row < A.size(); row++) {
		for(int column = 0; column < A.size(); column++){
			A[row][column] = 1 - A[row][column];
		}
	}
	return A;
}

/*
int main() {
	vector<vector<int>> matrix;

	vector<int> nums;vector<int> nums1;vector<int> nums2;
	nums.push_back(1);nums.push_back(1);nums.push_back(0);
	nums1.push_back(1);nums1.push_back(0);nums1.push_back(1);
	nums2.push_back(0);nums2.push_back(0);nums2.push_back(0);

	matrix.push_back(nums);matrix.push_back(nums1); matrix.push_back(nums2);
	flipAndInvert(matrix);

	return 0;
}*/
