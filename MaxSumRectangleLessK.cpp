#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <set>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
 * Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.
Example 1:
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/469544/Simple-C%2B%2B-Prefix-Sum-Solution-or-w-Explanation
 */
//ON3)
int maxSumSubMatrix(vector<vector<int>>& matrix, int k) {
	if(matrix.empty() || matrix[0].empty()) return 0;

	for(int row = 0; row < matrix.size(); row++) {
		int curSum = 0;
		for(int col = 0; col < matrix[0].size(); col++) {
			curSum += matrix[row][col];
			matrix[row][col] = curSum;
		}
	}
	int maxSum = INT_MIN;
	for(int lcol = 0; lcol < matrix[0].size(); lcol++) {
		for(int rcol = lcol; rcol < matrix[0].size(); rcol++) {

			set<int> bst;
			bst.insert(0);
			int rowPrefSum = 0;
			for(int row = 0; row < matrix.size(); row++) {
				int curSum = matrix[row][rcol] - (lcol == 0 ? 0 : matrix[row][lcol-1]);
				rowPrefSum += curSum;

				auto searchRes = bst.lower_bound(rowPrefSum - k);
				if(searchRes != bst.end())
					maxSum = max(maxSum, rowPrefSum - *searchRes);
				  bst.insert(rowPrefSum);
			}
		}
	}
	return maxSum;
}
/*
int main() {
	vector<vector<int>> matrix;
	vector<int> m1; m1.push_back(1);m1.push_back(0);m1.push_back(1);
	vector<int> m2; m2.push_back(0);m2.push_back(-2);m2.push_back(3);
	matrix.push_back(m1);matrix.push_back(m2);
	cout << maxSumSubMatrix(matrix, 2) << endl;

	return 0;
}*/
