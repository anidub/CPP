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
/*https://leetcode.com/problems/longest-common-subsequence/
 * Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
https://leetcode.com/problems/longest-common-subsequence/discuss/981992/recursivememoizationdpc%2B%2Beasy-understanding
 */
class LongestCommonSubsequence {
public:
	int longestCommonSubsequenceRecursion(string text1, string text2) {
		int m = text1.size(), n = text2.size();
		return longestCommonSubsequenceRecursion(text1, text2, m, n);
	}

	//TC:O(MN) SC: O(MN)
	int longestCommonSubsequenceMemo(string text1, string text2) {
		int m = text1.size(), n = text2.size();
		vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

		return longestCommonSubsequenceMemo(text1, text2, m, n, memo);
	}

	//TC:O(MN) SC: O(MN)
	int longestCommonSubsequenceDP(string text1, string text2) {
		int m = text1.size(), n = text2.size();

		int dp[m + 1][n + 1];

		for(int i = 0; i < m + 1; i++)
			dp[i][0] = 0;

		for(int j = 0; j < n + 1; j++)
			dp[0][j] = 0;

		for(int i = 1; i < m + 1; i++) {
			for(int j = 1; j < n + 1; j++) {
				if(text1[i - 1] == text2[ j - 1])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		return dp[m][n];
	}

private:
	int longestCommonSubsequenceRecursion(string text1, string text2, int m, int n) {
		if(m == 0 || n == 0) return 0;

		if(text1[m - 1] == text2[n - 1])
			return 1 + longestCommonSubsequenceRecursion(text1, text2, m - 1, n - 1);
		else
			return max(longestCommonSubsequenceRecursion(text1, text2, m - 1, n), longestCommonSubsequenceRecursion(text1, text2, m, n - 1));
	}

	int longestCommonSubsequenceMemo(string &text1, string &text2, int m, int n, vector<vector<int>> &memo) {
		if(m == 0 || n == 0) return 0;
		if(memo[m][n] != -1)
			return memo[m][n];

		if(text1[m] == text2[n])
			return memo[m][n] = 1 + longestCommonSubsequenceMemo(text1, text2, m - 1, n - 1, memo);
		else
			return memo[m][n] = max(longestCommonSubsequenceMemo(text1, text2, m - 1, n, memo), longestCommonSubsequenceMemo(text1, text2, m, n - 1, memo));

	}
};

/*
int main() {
	LongestCommonSubsequence lcs;
	cout << lcs.longestCommonSubsequenceRecursion("abcde", "ace") << endl;

	cout << lcs.longestCommonSubsequenceMemo("abcde", "ace") << endl;

	cout << lcs.longestCommonSubsequenceDP("abcde", "ace") << endl;
}
*/
