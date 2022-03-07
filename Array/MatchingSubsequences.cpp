#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>
#include <list>

using namespace std;

/*
 * https://leetcode.com/problems/number-of-matching-subsequences/
 * Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
Example 1:
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
https://leetcode.com/problems/number-of-matching-subsequences/discuss/117598/Java-solution-using-HashMap-and-Queue comments
//seems like the time complexity is O(S + W * L) , S is the length of S, W is the number of words and L is length of every word
 */
int numMatchingSubseq(string S, vector<string>& words) {
	if(words.empty()) return 0;
	int count = 0;
	unordered_map<char, list<string>> map;
	for(auto& s : words) {
		map[s[0]].push_back(s);
	}

	for(auto& c : S) {
		if(map.count(c)) {
			int n = map[c].size();
			while(n--) {
				string word = map[c].front();
				map[c].pop_front();
				if(word.length() == 1) count++;
				else
					map[word[1]].push_back(word.substr(1));
			}
		}
	}
	return count;
}
/*
int main() {
	string s  = "abcde";
	vector<string> words;
	words.push_back("a");words.push_back("bb");words.push_back("acd");words.push_back("ace");
	cout << numMatchingSubseq(s, words) << endl;
	return 0;
}
*/
