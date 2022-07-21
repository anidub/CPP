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
/*https://leetcode.com/problems/longest-string-chain/
 * You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
https://leetcode.com/problems/longest-string-chain/discuss/294890/JavaC%2B%2BPython-DP-Solution : comments pg7
Let N be the number of words in the list and LL be the maximum possible length of a word.

Time complexity: O(N (log N + L ^ 2))
 */
///Time O(NlogN) for sorting , Time O(NSS) for the for loop, where the second S refers to the string generation and S <= 16.
//SC : O(NS)
int longestStrChain(vector<string>& words) {
	if(words.empty()) return 0;

	auto comp = [](const string& s1, const string& s2) {
		return s1.size() == s2.size() ? (s1 < s2) : (s1.size() < s2.size() );
	};

	sort(words.begin(), words.end(), comp);//Sort the words by word's length
	unordered_map<string, int> dp;
	int res = 0;

	for(auto& word : words) {
		if(dp.count(word)) continue;
		for(int i = 0; i < word.size(); i++) {
			string word_less1(word);
			word_less1.erase(i, 1);
			dp[word] = max(dp[word], 1 + dp[word_less1]);
		}
		res = max(res, dp[word]);
	}
	return res;
}
/*
int main() {
	vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
	cout << longestStrChain(words) << endl;
	return 0;
}
*/
