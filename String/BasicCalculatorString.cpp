#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>

using namespace std;
/*Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
s consists of digits, '+', '-', '(', ')', and ' '.
https://leetcode.com/problems/basic-calculator/discuss/1457045/C%2B%2B-oror-Explained-oror-Stacks-oror-Beginner-FriendlyEasy-To-Understand : well explained
 */
int calculateString(string s) {
	if(s.empty()) return 0;

	stack<pair<int, int>> st;// pair(prev_calc_value , sign before next bracket () )
	long long int sum = 0;
	int sign = +1;

	for(int i = 0; i < s.length(); i++) {
		char ch = s[i];

		if(isdigit(ch)) {
			long long int num = 0;
			while(i < s.length() && isdigit(s[i])) {
				num = (num * 10) + s[i] - '0';
				i++;
			}
			i--;// as for loop also increase i , so if we don't decrease i here a sign will be skipped
			sum += (num * sign);
			sign = +1;
		} else if(ch == '(') {
			st.push(make_pair(sum, sign));// Saving current state of (sum , sign) in stack
			sum = 0;// Reseting sum and sign for inner bracket calculation
			sign = +1;
		} else if(ch == ')') {
			sum = st.top().first + (st.top().second * sum);
			st.pop();
		} else if(ch == '-') {
			sign = (-1) * sign;// toggle sign
		}
 	}
	return sum;
}
/*
int main() {
	cout << calculateString("(1+(4+5+2)-3)+(6+8)");


	return 0;
}*/
