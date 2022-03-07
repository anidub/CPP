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
/*https://leetcode.com/problems/concatenated-words/
 * Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
"dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
https://leetcode.com/problems/concatenated-words/discuss/95677/C%2B%2B-772-ms-dp-solution

 */
//Time complexity : O(N * L^3), where N = number of words and L = length of word.
//SC: O(N)
vector<string> findConcatednatedWordsOptimal(vector<string>& words) {
	if(words.empty()) return {};
	unordered_set<string> s(words.begin(), words.end());
	vector<string> res;

	for(auto w : words) {
		int n = w.size();
		vector<int> dp(n + 1);
		dp[0] = 1;
		for(int i = 0; i < n; i++) {
			if(dp[i] == 0) continue;
			for(int j = i+1; j  <= n; j++) {
				if(j - i < n && s.count(w.substr(i, j-i)))
					dp[j] = 1;
			}
			if(dp[n] == 1) {
				res.push_back(w);
				break;
			}
		}
	}
	return res;
}
/*https://www.youtube.com/watch?v=PY1LSBx-cNs
 *
 */
bool canFormWord(string word, unordered_set<string>& dict);
vector<string> findContatenatedWordsBruteForce(vector<string>& words) {
	unordered_set<string> s(words.begin(), words.end());
	vector<string> res;
	for(auto w : words) {
		if(canFormWord(w, s)) {
			res.push_back(w);
		}
	}
	return res;

}

bool canFormWord(string word, unordered_set<string>& dict) {
	for(int i = 1; i < word.size(); i++) {
		string left = word.substr(0, i);
		string right = word.substr(i+1);
		if(dict.count(left)) {
			if(dict.count(right) || canFormWord(right, dict)) {
				return true;
			}
		}
	}
	return false;
}
/*
int main() {
	vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
	findConcatednatedWordsOptimal(words);

	return 0;
}*/
