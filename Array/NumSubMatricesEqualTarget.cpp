#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
 * Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.
Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/discuss/303750/JavaC%2B%2BPython-Find-the-Subarray-with-Target-Sum

 */
//Time O(mnn) Space O(m)
int numSubmatricesEqualTarget(vector<vector<int>>& A, int target) {
	if(A.empty() || A[0].size() == 0) return 0;
	int m = A.size(), n = A[0].size();
	int result = 0;

	for(int i = 0; i < m; i++) {
		for(int j = 1; j < n; j++) {
			A[i][j] += A[i][j-1];
		}
	}

	unordered_map<int, int> counter;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			counter = {{0,1}};
			int cur = 0;
			for(int k = 0; k < m; k++) {
				cur += A[k][j] - (i > 0 ? A[k][i-1] : 0);
				result += (counter.find(cur - target) != counter.end() ? counter[cur-target] : 0);
				counter[cur]++;
			}
		}
	}
	return result;
}
/*
int main() {
	vector<vector<int>> A;
	vector<int> a1; a1.push_back(0);a1.push_back(1);a1.push_back(0);
	vector<int> a2; a2.push_back(1);a2.push_back(1);a2.push_back(1);
	vector<int> a3; a3.push_back(0);a3.push_back(1);a3.push_back(0);
	A.push_back(a1);A.push_back(a2);A.push_back(a3);
	cout << numSubmatricesEqualTarget(A, 0);
	return 0;
}*/
