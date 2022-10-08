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
/*https://www.educative.io/courses/grokking-the-coding-interview/R8DVgjq78yR
 * Given a string with lowercase letters only, if you are allowed to replace no more than k letters with any letter,
 *  find the length of the longest substring having the same letters after replacement.
 * Input: String="aabccbb", k=2
Output: 5
Explanation: Replace the two 'c' with 'b' to have the longest repeating substring "bbbbb".
 */
//TC: O(N), SC : since only lower case then O(26) which is asymptotically equal to O(1)
int longestSubstringSameLetterAfterReplacement(const string &str, int K) {
	if(str.empty()) return 0;
	unordered_map<char, int> charFreq;
	int maxLength = 0, maxRepeat = 0, windowStart = 0;

	for(int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
		char rightChar = str[windowEnd];
		charFreq[rightChar]++;
		maxRepeat = max(maxRepeat, charFreq[rightChar]);

		if(windowEnd - windowStart + 1 - maxRepeat > K) {
			char leftChar = charFreq[windowStart];
			charFreq[leftChar]--;
			windowStart++;
		}
		maxLength = max(maxLength, windowEnd - windowStart + 1);
	}
	return maxLength;
}
/*
int main() {
	  cout << longestSubstringSameLetterAfterReplacement("aabccbb", 2) << endl;
	  cout << longestSubstringSameLetterAfterReplacement("abbcb", 1) << endl;
	  cout << longestSubstringSameLetterAfterReplacement("abccde", 1) << endl;
}*/
