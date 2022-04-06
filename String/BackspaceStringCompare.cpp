#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>

using namespace std;
/*https://leetcode.com/problems/backspace-string-compare/
 * Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
https://leetcode.com/problems/backspace-string-compare/discuss/135603/JavaC%2B%2BPython-O(N)-time-and-O(1)-space
 */
// Time : O(N) space: O(1)
bool backspaceCompare(string S, string T) {
	int i = S.length(), j = T.length(), back = 0;

	while(true) {
		back = 0;
		while(i >= 0 && (back > 0 || S[i] == '#')) {
			back += S[i] == '#' ? 1 : -1;
			i--;
		}
		back = 0;
		while(j >= 0 && (back > 0 || T[j] == '#')) {
			back += T[j] == '#' ? 1 : -1;
			j--;
		}
		if(i >= 0 && j >= 0 && S[i] == T[j]) {
			i--;
			j--;
		} else
			break;
	}
	return i == -1 && j == -1;
}
/*
int main() {
	cout << backspaceCompare("ab#c", "ad#c") << endl;

	return 0;
}*/
