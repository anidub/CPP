#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <deque>
#include <utility>

using namespace std;
/*
 *https://leetcode.com/problems/count-square-submatrices-with-all-ones/
 *https://leetcode.com/problems/count-square-submatrices-with-all-ones/Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/441306/JavaC%2B%2BPython-DP-solution
https://www.youtube.com/watch?v=_Lf1looyJMU
https://www.youtube.com/watch?v=RElcqtFYTm0
https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/643793/C%2B%2B-simple-solution
brute: https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/643588/From-Brute-force-to-Optimised-DP-solutions-with-time-and-space-complexities-with-comments
 */
int countSquares(vector<vector<int>>& A) {
	if(A.size() == 0 || A[0].size() == 0)
		return 0;

	int result = 0;
	for(int i = 0; i < A.size(); i++) {
		for(int j = 0; j < A[0].size(); j++) {
			if(i && j && A[i][j])
				A[i][j] += min({A[i][j-1], A[i-1][j-1], A[i-1][j]});
			result += A[i][j];
		}
	}
	return result;
}
/*
int main() {
	vector<vector<int>> matrix;
	vector<int> nums;vector<int> nums1;vector<int> nums2;

	nums.push_back(0);nums.push_back(1);nums.push_back(1);nums.push_back(1);
	nums1.push_back(1);nums1.push_back(1);nums1.push_back(1);nums1.push_back(1);
	nums2.push_back(0);nums2.push_back(1);nums2.push_back(1);nums2.push_back(1);

	matrix.push_back(nums);matrix.push_back(nums1);matrix.push_back(nums2);

	cout << countSquares(matrix) << endl;

	return 0;
}*/
