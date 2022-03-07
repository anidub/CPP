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
/*https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 *A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.
Input: s = "((("
Output: 3
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/discuss/181132/C%2B%2BJavaPython-Straight-Forward-One-Pass
 */
//Time O(N) Space O(1)

int minAddParenthesisValid(string s){
	if(s.empty()) return 0;
	int left = 0, right = 0;

	for(char c : s) {
		if(c == '(')
			right++;
		else if(right > 0)
			right--;
		else
			left++;
	}
	return left + right;
}
/*
int main() {
	cout << minAddParenthesisValid("(((");

	return 0;
}*/
