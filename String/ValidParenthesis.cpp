#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/valid-parentheses/
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Input: s = "()[]{}"
Output: true
 *https://leetcode.com/problems/valid-parentheses/discuss/9222/My-0ms-c%2B%2B-solution-using-stack
 */

//TC : O(N), SC : O(N)
bool isValidParenthsesis(string s){
	stack<char> st;
	for(char c : s) {
		if(c == '(' || c == '{' || c == '[')
			st.push(c);
		else {
			if(st.empty()) return false;
			if(c == ')' && st.top() != '(') return false;
			if(c == '}' && st.top() != '{') return false;
			if(c == ']' && st.top() != '[') return false;
			st.pop();
		}
	}
	return st.empty();
}
/*
int main() {
	string s = "()[]{}";
	cout << isValidParenthsesis(s) << endl;
	return 0;
}
*/
