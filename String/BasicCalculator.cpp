#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>

using namespace std;
/*https://leetcode.com/problems/basic-calculator-ii/
 *Given a string s which represents an expression, evaluate this expression and return its value.
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "3+2*2"
Output: 7
 * https://leetcode.com/problems/basic-calculator-ii/discuss/1646099/C%2B%2BPython-Simple-Solutions-w-Explanation-or-Postfix-%2B-Stack-%2B-Without-Stack
 https://leetcode.com/problems/basic-calculator-ii/discuss/63006/C%2B%2B-stack-solution.
 */
// Time Complexity : O(N) Space Complexity : O(1)
int calculateBasicOptimal(string s) {
	int cur = 0, ans = 0, interimRes = 0;
	char prevOp = '+';
	s += "##";

	for(char c : s) {
		if(c == ' ') continue;
		else if(isdigit(c))
			cur = cur * 10 + (c - '0');
		else {
			if(prevOp == '*')
				interimRes *= cur;
			else if(prevOp == '/')
				interimRes /= cur;
			else {
				ans += interimRes;
				interimRes = prevOp == '+' ? cur : -cur;
			}
			prevOp = c;
			cur = 0;
		}
	}
	return ans;
}

int calculateBasic(string s) {
   /* stack<int> myStack;
    char sign = '+';
    int res = 0, tmp = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (isdigit(s[i]))
            tmp = 10*tmp + s[i]-'0';
        if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1) {
            if (sign == '-')
                myStack.push(-tmp);
            else if (sign == '+')
                myStack.push(tmp);
            else {
                int num;
                if (sign == '*' )
                    num = myStack.top()*tmp;
                else
                    num = myStack.top()/tmp;
                myStack.pop();
                myStack.push(num);
            }
            sign = s[i];
            tmp = 0;
        }
    }
    while (!myStack.empty()) {
        res += myStack.top();
        myStack.pop();
    }
    return res;
*/
	stack<int> st;
	int res = 0, tmp = 0;
	char sign = '+';
	for(int i = 0; i < s.size(); i++) {
		if(isdigit(s[i])) {
			tmp = tmp * 10 + s[i] - '0';
		}
		if(!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1) {
			if(sign == '-') {
				st.push(-tmp);
			} else if(sign == '+') {
				st.push(tmp);
			} else {
				int num;
				if(sign == '*')
					num = st.top() * tmp;
				else
					num = st.top() / tmp;
				st.pop();
				st.push(num);
			}
			sign = s[i];
			tmp = 0;
		}
	}
	while(!st.empty()) {
		res += st.top();
		st.pop();
	}
	return res;
}
/*
int main() {
	cout << calculateBasicOptimal(" 3+5 / 2 ") << endl;
	cout << calculateBasic(" 3+5 / 2 ") << endl;
	return 0;
}*/
