#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * Given a m x n matrix mat and an integer threshold. Return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.
Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.

 * https://www.youtube.com/watch?v=t4J-Sp3BWh4
 * https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/discuss/452020/C%2B%2B-DP-solution-with-comments-and-example
 https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/discuss/451871/Java-sum%2Bbinary-O(m*n*log(min(mn)))-or-sum%2Bsliding-window-O(m*n)
https://blog.baozitraining.org/2020/01/leetcode-solution-1292-maximum-side.html
 */

//O(N3)
int maxSideLength(vector<vector<int>>& mat, int threshold) {
	if(mat.empty() || mat.size() == 0 || mat[0].size() == 0)
		return 0;

	int row = mat.size();
	int col = mat[0].size();
	vector<vector<int>> prefixSum (row+1,vector<int>(col+1, 0));

	for(int i = 1; i <= row; i++) {
		for(int j = 1; j <= col; j++) {
			prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + mat[i - 1][j - 1]; // needs to plus itself as well
		}
	}

	int minLen = min(row, col);
	for(int len = minLen; len >= 1; len--) {
		for(int i = 1; i+len <= row; i++) {
			for(int j = 1; j+len <= col; j++) {
				if(prefixSum[i+len][j+len] - prefixSum[i-1][j+len] - prefixSum[i+len][j-1] + prefixSum[i-1][j-1] <= threshold) {
					return len+1;
				}
			}
		}
	}
	return 0;
}

//https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/discuss/451871/Java-sum%2Bbinary-O(m*n*log(min(mn)))-or-sum%2Bsliding-window-O(m*n)
bool isSquareExist(vector<vector<int>>& prefixSum, int threshold, int len) {
	for(int i = len; i <= prefixSum.size(); i++) {
		for(int j = len; j <= prefixSum[0].size(); j++) {
			if(prefixSum[i][j] - prefixSum[i-len][j] - prefixSum[i][j-len] + prefixSum[i-len][j-len] <= threshold)
				return true;
		}
	}
	return false;
}

int maxSideLen(vector<vector<int>>& mat, int threshold) {
	if(mat.empty() || mat.size() == 0 || mat[0].size() == 0)
		return 0;

	int row = mat.size();
	int col = mat[0].size();
	vector<vector<int>> prefixSum (row+1,vector<int>(col+1, 0));

	for(int i = 1; i <= row; i++) {
		for(int j = 1; j <= col; j++) {
			prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + mat[i - 1][j - 1]; // needs to plus itself as well
		}
	}

	int lo = 0, hi = min(row, col);
	while(lo <= hi) {
		int mid = (lo + hi)/2;
		if(isSquareExist(prefixSum, threshold, mid)) {
			lo = mid+1;
		} else {
			hi = mid - 1;
		}
	}
	return hi;
}

// O(m*n)
int maxSideLenOptimal(vector<vector<int>>& mat, int threshold) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> sum (m+1,vector<int>(n+1, 0));

    int res = 0;
    int len = 1; // square side length

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i-1][j-1];

            if (i >= len && j >= len && sum[i][j] - sum[i-len][j] - sum[i][j-len] + sum[i-len][j-len] <= threshold)
                res = len++;
        }
    }

    return res;
}
