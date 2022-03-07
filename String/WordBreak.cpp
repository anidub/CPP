#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/word-break/
 * Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
 * Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

https://www.youtube.com/watch?v=th4OnoGasMU

expalined in solution tab, draw by hand
https://leetcode.com/problems/word-break/discuss/809993/C%2B%2B-DP-oror-Easy-to-understand
https://leetcode.com/problems/word-break/discuss/870144/C%2B%2B-simple-and-short-dynamic-programming-solution : comments

 */

bool wordBreak(string s, vector<string>& wordDict) {
	if(s.empty()) return false;
	unordered_set<string> word_set(wordDict.begin(), wordDict.end());
	vector<bool> dp(s.length() + 1);
	dp[0] = true;

	for(int i = 1; i <= s.length(); i++) {
		for(int j = 0; j < i; j++) {
			if(dp[j] &&
					word_set.find(s.substr(j, i-j)) != word_set.end()) {
				dp[i] = true;
				break;
			}
		}
	}
	return dp[s.length()];
}
/*
int main() {
	vector<string> wd = {"my", "pen"};

	cout << wordBreak("mypenmy", wd) << endl;

	return 0;
}*/
