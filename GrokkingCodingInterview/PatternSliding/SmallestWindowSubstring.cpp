#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/xoyL4q6ApNE
 * Given a string and a pattern, find the smallest substring in the given string which has all the character occurrences of the given pattern.
 * Input: String="aabdec", Pattern="abac"
Output: "aabdec"
Explanation: The smallest substring having all character occurrences of the pattern is "aabdec"
 */
//TC: O(N + M), SC: O(M)
string findSmallestWindowSubstring(const string &str, const string &pattern) {
	unordered_map<char, int> charFreq;
	int minLen = str.length() + 1, start = 0, matched = 0, windowStart = 0;

	for(auto &c : pattern) {
		charFreq[c]++;
	}

	for(int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
		char rightChar = str[windowEnd];
		if(charFreq.find(rightChar) != charFreq.end()) {
			charFreq[rightChar]--;
			if(charFreq[rightChar] >= 0) matched++;// count every matching of a character
		}
		while(matched == pattern.length()) {// shrink the window if we can, finish as soon as we remove a matched character
			if(minLen > windowEnd - windowStart + 1) {
				minLen = windowEnd - windowStart + 1;
				start = windowStart;
			}
			char leftChar = str[windowStart++];
			if(charFreq.find(leftChar) != charFreq.end()) {
				if(charFreq[leftChar] == 0) matched--;// note that we could have redundant matching characters, therefore we'll decrement the
				//matched count only when a useful occurrence of a matched character is going out of the window
				charFreq[leftChar]++;
			}
		}
	}
	return minLen > str.length() ? "" : str.substr(start, minLen);
}

/*
int main(int argc, char *argv[]) {
  cout << findSmallestWindowSubstring("aabdec", "abc") << endl;
  cout << findSmallestWindowSubstring("aabdec", "abac") << endl;
  cout << findSmallestWindowSubstring("abdbca", "abc") << endl;
  cout << findSmallestWindowSubstring("adcad", "abc") << endl;
}
*/
