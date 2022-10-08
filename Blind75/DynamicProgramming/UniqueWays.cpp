#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/unique-paths/
 * There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
 *  The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Input: m = 3, n = 7
Output: 28

https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
solution tab for recursion code
Since the robot can only move right and down, when it arrives at a point, it either arrives from left or above.

 */

class UniqueWays {
public:
	//TC:O(2 ^ N), SC:O(N)
	int uniqueWaysRecursion(int m, int n) {
		if(m == 1 || n == 1) return 1;
		return uniqueWaysRecursion(m - 1, n) + uniqueWaysRecursion(m, n - 1);
	}

	//TC:O(M * N), SC:O(M *N )
	int uniqueWaysDP(int m, int n) {
		if(m == 0 && n == 0) return 0;
		if(m == 1 || n == 1) return 1;

		vector<vector<int>> dp(m, vector<int>(n, 1));

		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[m - 1][n - 1];
	}
};
/*
int main() {
	UniqueWays uq;
	cout << uq.uniqueWaysRecursion(3, 7) << endl;

	cout << uq.uniqueWaysDP(3, 7) << endl;
}
*/
