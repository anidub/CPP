#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/stickers-to-spell-word/
 * We are given n different types of stickers. Each sticker has a lowercase English word on it.

You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.
Input: stickers = ["with","example","science"], target = "thehat"
Output: 3
Explanation:
We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.
https://leetcode.com/problems/stickers-to-spell-word/discuss/108318/C%2B%2BJavaPython-DP-%2B-Memoization-with-optimization-29-ms-(C%2B%2B)
 */

int minStickersHelper(vector<vector<int>> &mp, unordered_map<string, int> &dp, string target);
//TC: O((m ^ n) * (26 ^ n) * n!)
int minStickers(vector<string>& stickers, string target) {
	int m = stickers.size();
	vector<vector<int>> mp(m, vector<int>(26, 0));
	unordered_map<string, int> dp;

	for(int i = 0; i < m; i++) {
		for(char c : stickers[i])
			mp[i][c - 'a']++;
	}
	dp[""] = 0;
	return minStickersHelper(mp, dp, target);
}

int minStickersHelper(vector<vector<int>> &mp, unordered_map<string, int> &dp, string target) {
	if(dp.count(target)) return dp[target];
	int ans = INT_MAX, n = mp.size();
	vector<int> tar(26, 0);
	for(char c : target)
		tar[c - 'a']++;

	for(int i = 0; i < n; i++) {
		if(mp[i][target[0] - 'a'] == 0) continue;
		string s;
		for(int j = 0; j < 26; j++)
			if(tar[j] - mp[i][j] > 0) s += string(tar[j] - mp[i][j], 'a' + j);
		int tmp = minStickersHelper(mp, dp, s);
		if(tmp != -1) ans = min(ans, 1 + tmp);
	}
	dp[target] = ans == INT_MAX ? -1 : ans;
	return dp[target];
}
/*
int main() {
	vector<string> stickers = {"with", "example", "science"};
	cout << minStickers(stickers, "thehat") << endl;

	return 0;
}*/
