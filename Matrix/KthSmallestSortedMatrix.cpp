#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <queue>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 * Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise
 */
int countOrLessEqual(vector<vector<int>> &matrix, int x);
//Time: O((M+N) * logD), where M <= 300 is the number of rows, N <= 300 is the number of columns, D <= 2*10^9 is the difference between the maximum element and the minimum element in the matrix.
//SC: Space: O(1).
int kthSmallestSorted(vector<vector<int>>& matrix, int k) {
	if(matrix.empty()) return -1;
	int m = matrix.size(), n = matrix[0].size();
	int left = matrix[0][0], right = matrix[m-1][n-1], ans = -1;

	while(left <= right) {
		int mid = left + (right - left) / 2;
		if(countOrLessEqual(matrix, mid) >= k) {
			ans = mid;
			right = mid - 1;// try to looking for a smaller value in the left side
		} else
			left = mid + 1;// try to looking for a bigger value in the right side
	}
	return ans;
}

int countOrLessEqual(vector<vector<int>> &matrix, int x) {
	int c = matrix[0].size() - 1, cnt = 0;// start with the rightmost column

	for(int r = 0; r < matrix.size(); r++) {
		while(c >= 0 && matrix[r][c] > x) c--;// decrease column until matrix[r][c] <= x
		cnt += (c + 1);
	}
	return cnt;
}
/*
int main() {
	vector<vector<int>> grid = {{1,5,9},{10,11,13},{12,13,15}};
	cout << kthSmallestSorted(grid, 8) << endl;

	return 0;
}*/
