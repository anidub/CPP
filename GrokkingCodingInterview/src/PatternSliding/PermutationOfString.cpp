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
/*https://www.educative.io/courses/grokking-the-coding-interview/N0o9QnPLKNv
 * Given a string and a pattern, find out if the string contains any permutation of the pattern.

Permutation is defined as the re-arranging of the characters of the string. For example, “abc” has the following six permutations:

abc
acb
bac
bca
cab
cba
If a string has ‘n’ distinct characters, it will have n! permutations.
 Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.
 */

// TC: O(N + M), SC : O(M)
bool findPermutation(const string &str, const string &pattern) {
	unordered_map<char, int> charFreq;
	int windowStart = 0, matched = 0;

	for(auto &c : pattern) {
		charFreq[c]++;
	}

	for(int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
		char rightChar = str[windowEnd];

		if(charFreq.find(rightChar) != charFreq.end()) {
			charFreq[rightChar]--;
			if(charFreq[rightChar] == 0) {
				matched++;
			}
		}
		if(matched == (int)charFreq.size()) return true;

		if(windowEnd >= pattern.length() - 1) {
			char leftChar = str[windowStart++];
			if(charFreq.find(leftChar) != charFreq.end()) {
				if(charFreq[leftChar] == 0) {
					matched--;
				}
				charFreq[leftChar]++;
			}
		}
	}
	return false;
}
/*
int main() {
	  cout << "Permutation exist: " << findPermutation("oidbcaf", "abc") << endl;
	  cout << "Permutation exist: " << findPermutation("odicf", "dc") << endl;
	  cout << "Permutation exist: " << findPermutation("bcdxabcdy", "bcdyabcdx") << endl;
	  cout << "Permutation exist: " << findPermutation("aaacb", "abc") << endl;
}
*/
