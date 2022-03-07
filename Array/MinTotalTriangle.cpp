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
 * https://leetcode.com/problems/triangle/
 * Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
https://leetcode.com/problems/triangle/discuss/695264/C%2B%2B-and-Python-solutions
 */

int minTotaltriangle(vector<vector<int  >>& triangle) {
	if(triangle.empty()) return -1;
	vector<int> dp = triangle.back();
	for(int i = triangle.size() - 2; i >= 0; i--) {
		for(int j = 0; j < triangle[i].size(); j++) {
			dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
		}
	}
	return dp[0];
}
/*
int main() {
	vector<vector<int>> triangle;
	vector<int> t1; t1.push_back(2);
	vector<int> t2; t2.push_back(3);t2.push_back(4);
	vector<int> t3; t3.push_back(6);t3.push_back(5);t3.push_back(7);
	vector<int> t4; t4.push_back(4);t4.push_back(1);t4.push_back(8);t4.push_back(3);
	triangle.push_back(t1);triangle.push_back(t2);triangle.push_back(t3);triangle.push_back(t4);
	cout << minTotaltriangle(triangle) << endl;
	return 0;
}
*/
