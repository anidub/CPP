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
/*https://leetcode.com/problems/reverse-words-in-a-string/
 * Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
https://leetcode.com/problems/reverse-words-in-a-string/discuss/47840/C%2B%2B-solution-in-place%3A-runtime-O(n)-memory-O(1)
 *
 */
void  reverseWord(string& s, int i, int j);
//Time O(n), Space O(1)
string reverseWordsSentence(string s) {
	int i = 0, j = 0, start = 0;
	int len = s.length();
	int wordCount = 0;

	while(true) {
		while(i < len && s[i] == ' ') i++;// skip spaces in front of the word
		if(i == len) break;
		if(wordCount) s[j++] = ' ';
		start = j;
		while(i < len && s[i] != ' ') {
			s[j] = s[i];
			i++; j++;
		}
		reverseWord(s, start, j-1);// reverse word in place
		wordCount++;
	}
	s.resize(j);// resize result string after removing unnecessary spaces
	reverseWord(s, 0, j-1);// reverse whole string
	return s;
}

void  reverseWord(string& s, int i, int j) {
	while(i < j) {
		char t = s[i];
		s[i++] = s[j];
		s[j--] = t;
	}
}
/*
int main() {
	cout << reverseWordsSentence("a good   example") << endl;

	return 0;
}*/
