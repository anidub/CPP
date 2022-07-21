#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/x1NJVYKNvqz
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/ : USED
 * Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

 */
class KthSmallestElementSortedMatrix {
public:
	//TC:O(N * LOG(MAX - MIN)), SC: O(1)
	int kthSmallestElementSortedMatrix(vector<vector<int>> &matrix, int k) {
		if(matrix.empty()) return -1;
		int m = matrix.size(), n = matrix[0].size();

		int left = matrix[0][0], right = matrix[m-1][n-1];
		int ans = -1;

		while(left <= right) {
			int mid = left + (right - left) / 2;
			if(countLessOrEqual(matrix, mid) >= k) {
				ans = mid;
				right = mid - 1;
			} else
				left = mid + 1;
		}
		return ans;
	}
private:
	int countLessOrEqual(vector<vector<int>> &matrix, int x) {
		int count = 0,  c = matrix[0].size() - 1;

		for(int r = 0; r < matrix.size(); r++) {
			while(c >= 0 && matrix[r][c] > x)
				c--;
			count += (c + 1);
		}
		return count;
	}
};

/*
int main(int argc, char *argv[]) {
	KthSmallestElementSortedMatrix ksesm;
  vector<vector<int>> matrix2 = {vector<int>{2, 6, 8},
		  	  	  	  	  	  	  vector<int>{3, 7, 10},
                                 vector<int>{5, 8, 11}};
  int result = ksesm.kthSmallestElementSortedMatrix(matrix2, 5);
  cout << "Kth smallest number is: " << result << endl;
}
*/
