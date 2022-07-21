#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/valid-parentheses/
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Input: s = "()[]{}"
Output: true

 */
class ValidParenthesis {
public:
	//TC:O(N), SC:O(N)
	bool isValid(string s) {
		stack<char> st;
		for(char &c : s) {
			if(c == '[' || c =='{' || c == '(')
				st.push(c);
			else {
				if(st.empty()) return false;
				if(c == ']' && st.top() != '[') return false;
				if(c == '}' && st.top() != '{') return false;
				if(c == ')' && st.top() != '(') return false;
				st.pop();
			}
		}
		return st.empty();
	}
};
/*
int main() {
	ValidParenthesis vp;
	cout << vp.isValid("()[]{}") << endl;
}
*/
