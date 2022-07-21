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
/*https://leetcode.com/problems/word-break/
 * Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a
 * space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

https://leetcode.com/problems/word-break/
 */
class WordBreak {
public:
	//TC:O(N ^ 3):. There are two nested loops, and substring computation at each iteration. Overall that results in O(n^3) SC:O(N)
	 bool wordBreakMemo(string s, vector<string>& wordDict) {
		 unordered_set<string> word_set(wordDict.begin(), wordDict.end());
		 vector<int> memo(s.length(), - 1);
		 return wordBreakMemo(s, word_set, 0, memo);
	 }

	 //TC:O(N ^ 3):. There are two nested loops, and substring computation at each iteration. Overall that results in O(n^3)
	 //SC:O(N): The depth of recursion tree can go up to n.
	 bool wordBreakDP(string s, vector<string>& wordDict) {
		 unordered_set<string> word_set(wordDict.begin(), wordDict.end());
		 vector<bool> dp(s.length() + 1);
		 dp[0] = true;

		 for(int i = 1; i < s.length() + 1; i++) {
			 for(int j = 0; j < i; j++) {
				 if(word_set.find(s.substr(j, i - j)) != word_set.end() && dp[j]) {
					 dp[i] = true;
					 break;
				 }
			 }
		 }

		 return dp[s.length()];


	 }

private:
	 bool wordBreakMemo(string &s, unordered_set<string>& word_set, int start, vector<int> &memo) {
		 if(start == s.length()) return true;

		 if(memo[start] != -1)
			 return memo[start];

		 for(int end = start + 1; end < s.length() + 1; end++) {
			 if(word_set.find(s.substr(start, end - start)) != word_set.end() &&
					 wordBreakMemo(s, word_set, end, memo) ) {
				 return memo[start] = true;
			 }
		 }

		 return memo[start] = false;
	 }
};

/*
int main() {
	WordBreak wb;
	vector<string> wordDict = {"leet", "code"};
	cout << wb.wordBreakMemo("leetcode", wordDict) << endl;
	cout << wb.wordBreakDP("leetcode", wordDict) << endl;

	return 0;
}*/
