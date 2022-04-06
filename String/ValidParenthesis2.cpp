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
/*https://leetcode.com/problems/valid-parenthesis-string/
 * Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

 * Input: s = "(*))"
Output: true
https://leetcode.com/problems/valid-parenthesis-string/discuss/302732/C%2B%2B-O(S)-Time-O(1)-Space-One-Pass-with-Explanation : EXPLAINED,
also check solutions for explained
 */
//TC: O(S), SC:O(1)
bool checkValidStringParenthsesis(string s) {
	if(s.empty()) return false;
	int maxDiff = 0, minDiff = 0;

	for(char c : s) {
		maxDiff += (c == '(' || c == '*') ? 1 : -1;
		minDiff += (c == ')' || c == '*') ? -1 : 1;

		if(maxDiff < 0) return false;
		minDiff = max(minDiff, 0);
	}
	return minDiff == 0;

}
/*
int main() {
	cout << checkValidStringParenthsesis("(*))") << endl;
	return 0;
}*/
