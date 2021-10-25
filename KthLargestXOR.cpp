#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>
#include <unordered_set>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
 *You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.
The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).
Find the kth largest value (1-indexed) of all the coordinates of matrix.
Example 1:
Input: matrix = [[5,2],[1,6]], k = 1
Output: 7
Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.

well explanined :
https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/discuss/1032010/Detailed-Explanation-or-C%2B%2B-Solution-or-Easy-Implementation
 */
int kthLargestValueMatrix(vector<vector<int>>& matrix, int k) {
	if(matrix.empty()) return -1;
	int m = matrix.size(), n = matrix[0].size();

	priority_queue<int, vector<int>, greater<int>> pq;
	cout << " here " << endl;
	for(int i = 0; i < m; i++) {
		for(int j = 1; j < n; j++) {
			matrix[i][j] = matrix[i][j-1] ^ matrix[i][j];
		}
	}
	cout << " here 1" << endl;
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < m; j++) {
			matrix[j][i] = matrix[j-1][i] ^ matrix[j][i];
		}
	}
	cout << " here 2" << endl;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(pq.size() < k) {
				pq.push(matrix[i][j]);
			} else {
				if(matrix[i][j] > pq.top()) {
					pq.pop();
					pq.push(matrix[i][j]);
				}
			}
		}
	}
	return pq.top();
}
/*
int main() {
	vector<vector<int>> matrix;
	vector<int> nums;
	nums.push_back(5);nums.push_back(2);
	vector<int> nums1;
	nums1.push_back(1);nums1.push_back(6);
	matrix.push_back(nums);matrix.push_back(nums1);

	cout << kthLargestValueMatrix(matrix, 1) << endl;
}
*/
