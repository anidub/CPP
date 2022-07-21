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
/*https://leetcode.com/problems/valid-word-abbreviation/
 * A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):

"s10n" ("s ubstitutio n")
"sub4u4" ("sub stit u tion")
"12" ("substitution")
"su3i1u2on" ("su bst i t u ti on")
"substitution" (no substrings replaced)
The following are not valid abbreviations:

"s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
"s010n" (has leading zeros)
"s0ubstitution" (replaces an empty substring)
Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

A substring is a contiguous non-empty sequence of characters within a string.

Input: word = "internationalization", abbr = "i12iz4n"
Output: true
Explanation: The word "internationalization" can be abbreviated as "i12iz4n" ("i nternational iz atio n")

https://leetcode.com/problems/valid-word-abbreviation/discuss/89579/Concise-C%2B%2B-Solution
 */

//TC: O(N) N = length of max word
bool validWordAbbrevation(string word, string abbr) {
	if(word.empty() || abbr.empty()) return false;
	int i = 0, j = 0;

	while(i < word.size() && j < abbr.size()) {
		if( isdigit(abbr[j]) ) {
			if(abbr[j] == '0') return false;
			int val = 0;
			while(j < abbr.size() && isdigit(abbr[j]))
				val = val * 10 + abbr[j++] - '0';

			i += val;
		} else if(abbr[j++] != word[i++]) return false;
 	}
	return i == word.size() && j == abbr.size();
}
/*
int main() {
	cout << validWordAbbrevation("internationalization", "i12iz4n") << endl;

	return 0;
}*/
