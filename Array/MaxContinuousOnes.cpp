#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;
/*
 * https://www.cnblogs.com/grandyang/p/6900866.html
 * Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.

Example:

Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
https://protegejj.gitbook.io/algorithm-practice/leetcode/dynamic-programming/562-longest-line-of-consecutive-one-in-matrix
 * https://www.cnblogs.com/grandyang/p/6900866.html used
 *
 * Time: O(mn) && Space: O(1)
 */
int maxContinuousOnes(vector<vector<int>>& M) {
	if(M.empty() || M[0].empty()) return -1;
	int m = M.size(), n = M[0].size();
	int result = 0;

	vector<vector<int>> dirs{{1,0}, {0,1}, {-1,-1}, {-1,1}};
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(M[i][j] == 0) continue;
			for(int k = 0; k < 4; k++) {
				int cnt = 0, x = i, y = j;
				while(x >= 0 && x < m && y >= 0 && y < n && M[x][y] == 1) {
					x += dirs[k][0];
					y += dirs[k][1];
					cnt++;
				}
				result = max(result, cnt);
 			}
		}
	}
	return result;
}
/*
int main() {
	vector<vector<int>> nums;
	vector<int> n1; n1.push_back(0);n1.push_back(1);n1.push_back(1);n1.push_back(0);
	vector<int> n2; n2.push_back(0);n2.push_back(1);n2.push_back(1);n2.push_back(0);
	vector<int> n3; n3.push_back(0);n3.push_back(0);n3.push_back(0);n3.push_back(1);
	nums.push_back(n1);nums.push_back(n2);nums.push_back(n3);
	cout << maxContinuousOnes(nums) << endl;
	return 0;
}
*/
