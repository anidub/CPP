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
/*https://www.educative.io/courses/grokking-the-coding-interview/YMzBx1gE5EO
 * Given a string, find the length of the longest substring, which has all distinct characters.
 */
//TC: O(N), SC:O(K)where K is the number of distinct characters in the input
int findMaxLengthDistinctChars(const string& str) {
	if(str.empty()) return 0;
	unordered_map<char, int> charFreq;
	int windowStart = 0, maxLength = 0;

	for(int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
		int rightChar = str[windowEnd];
		if(charFreq.find(rightChar) != charFreq.end()) {
			windowStart = max(windowStart, charFreq[rightChar] + 1);
		}
		charFreq[rightChar] = windowEnd;
		maxLength = max(maxLength, windowEnd - windowStart + 1);
	}
	return maxLength;
}
/*
int main(int argc, char* argv[]) {
  cout << "Length of the longest substring: " << findMaxLengthDistinctChars("aabccbb") << endl;
  cout << "Length of the longest substring: " << findMaxLengthDistinctChars("abbbb") << endl;
  cout << "Length of the longest substring: " << findMaxLengthDistinctChars("abccde") << endl;
}*/
