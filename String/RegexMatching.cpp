#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/regular-expression-matching/
 * Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
https://www.youtube.com/watch?v=l3hda49XcDE : well explained
https://leetcode.com/problems/regular-expression-matching/discuss/5684/C%2B%2B-O(n)-space-DP

We define dp[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. The state equations will be:

dp[i][j] = dp[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
dp[i][j] = dp[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 time;
dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 time.
 */
//TC: O(NM), O(NM)
bool isRegexMatch(string s, string p) {
	if(s.empty() || p.empty()) return true;

	int m = s.size(), n = p.size();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1 , false));
	dp[0][0] = true;

	for(int i = 0; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(p[j - 1] == '*') {
				dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.') );
			} else {
				dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
		}
	}
	return dp[m][n];
}
/*
int main() {
	cout << isRegexMatch("xaabyc", "xa*b.c") << endl;

	return 0;
}*/
