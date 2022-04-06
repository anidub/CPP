#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>

using namespace std;
/*https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 * Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.

https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/discuss/888949/JavaC%2B%2BPython-Parentheses-Problem-Foundation

More Parentheses Problem To Advance
Here is a ladder of parentheses problem, in order of problem number.

Minimum Insertions to Balance a Parentheses String
Minimum Remove to Make Valid Parentheses
Maximum Nesting Depth of Two Valid Parentheses Strings
Reverse Substrings Between Each Pair of Parentheses
Remove Outermost Parentheses
Minimum Add to Make Parentheses Valid
Score of Parentheses

 */
//TC:O(n), SC: O(1)
int maxDepthParenthesis(string s) {
	int res = 0, cur = 0;
	for(char &c : s) {
		if(c == '(') {
			cur++;
			res = max(res, cur);
		}
		if(c == ')')
			cur--;
 	}
	return res;
}
/*
int main() {
	cout << maxDepthParenthesis("(1+(2*3)+((8)/4))+1") << endl;

	return 0;
}
*/
