#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*
 *https://leetcode.com/problems/minimum-path-sum/Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 - 3 - 1 - 1 - 1 minimizes the sum.
https://leetcode.com/problems/minimum-path-sum/discuss/23457/C%2B%2B-DP
 */

int minSumPath(vector<vector<int>>& matrix) {
	if(matrix.empty()) return 0;
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> sum(m, vector<int>(n, matrix[0][0]));

	for(int i = 1; i < m; i++)
		sum[i][0] = sum[i-1][0] + matrix[i][0];

	for(int j = 1; j < n; j++)
		sum[0][j] = sum[0][j-1] + matrix[0][j];

	for(int i = 1; i < m; i++)
		for(int j = 1; j < n; j++)
			sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + matrix[i][j];

	return sum[m-1][n-1];
}

int minSumPathSpaceOptimal(vector<vector<int>>& matrix) {
	if(matrix.empty()) return 0;
	int m = matrix.size(); int n = matrix[0].size();

	vector<int> cur(m, matrix[0][0]);

	for(int i = 1; i < m; i++)
		cur[i] = cur[i-1] + matrix[i][0];

	for(int j = 1; j < n; j++){
		cur[0] +=  matrix[0][j];
		for(int i = 1; i < m; i++) {
			cur[i] = min(cur[i-1], cur[i]) + matrix[i][j];
		}
	}
	return cur[m-1];
}
/*
int main() {
	vector<vector<int>> matrix;
	vector<int> nums; nums.push_back(1);nums.push_back(3);nums.push_back(1);
	vector<int> nums1; nums1.push_back(1);nums1.push_back(5);nums1.push_back(1);
	vector<int> nums2; nums2.push_back(4);nums2.push_back(2);nums2.push_back(1);

	matrix.push_back(nums);matrix.push_back(nums1);matrix.push_back(nums2);
	cout << minSumPath(matrix) << endl;
	cout << minSumPathSpaceOptimal(matrix) << endl;
	return 0;
}
*/
