#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix

https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/discuss/510277/C%2B%2B-Count-Right-To-Left
*/

int countNonNegative(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	int result = 0;
	for(int i = n - 1; i >= 0 && matrix[i].back() < 0; --i) {
		for(int j = matrix[i].size() - 1; j >= 0 && matrix[i][j] < 0; --j) {
			result++;
		}
	}
	cout << result;
	return result;
}

/*

int main() {
	vector<int> nums;vector<int> nums1;vector<int> nums2;vector<int> nums3;
		vector<vector<int>> matrix;
		nums.push_back(4);nums.push_back(3);nums.push_back(2);nums.push_back(-1);
		nums1.push_back(3);nums1.push_back(2);nums1.push_back(1);nums1.push_back(-1);
		nums2.push_back(1);nums2.push_back(1);nums2.push_back(-1);nums2.push_back(-2);
		nums3.push_back(-1);nums3.push_back(-1);nums3.push_back(-2);nums3.push_back(-3);
		matrix.push_back(nums);matrix.push_back(nums1);matrix.push_back(nums2);matrix.push_back(nums3);
		countNonNegative(matrix);

	return 0;
} */

