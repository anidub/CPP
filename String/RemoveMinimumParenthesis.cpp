#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 *Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/1073189/C%2B%2B-or-2-Approaches-or-O(n)-Beats-100-or-No-Extra-Space-(Best)-or-Explanation
 */
//TC: O(N); S(N)
string removeMinParenthesis(string s) {
	if(s.empty()) return s;
	stack<int> st;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '(') st.push(i);
		else if(s[i] == ')'){
			if(st.empty())
				s[i] = '#';
			else
				st.pop();
		}
	}

	while(!st.empty()) {
		s[st.top()] = '#';
		st.pop();
	}
	string ans="";
	for(int i = 0; i < s.length(); i++) {
		if(s[i] != '#') ans.push_back(s[i]);
	}
	return ans;
}
//TC: O(N); S(1)
string removeMinParenthesisOptimal(string s) {
	if(s.empty()) return s;
	int count = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '(')
			count++;
		else if(s[i] == ')'){
			if(count == 0)
				s[i] = '#';
			else
				count--;
		}
	}

	count = 0;
	for(int i = s.length()-1; i >= 0; i--) {
		if(s[i] == ')')
			count++;
		else if(s[i] == '(') {
			if(count == 0)
				s[i] = '#';
			else
				count--;
		}
	}
	string ans = "";
	for(int i = 0; i < s.length(); i++) {
		if(s[i] != '#') ans.push_back(s[i]);
	}
	return ans;
}
/*
int main() {
	string  s = "lee(t(c)o)de)";
	cout << removeMinParenthesis(s) << endl;

	cout << removeMinParenthesisOptimal(s) << endl;
	return 0;
}*/
