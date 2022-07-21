#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/valid-number/
 * A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
One or more digits, followed by a dot '.'.
One or more digits, followed by a dot '.', followed by one or more digits.
A dot '.', followed by one or more digits.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One or more digits.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.
 *
 * https://leetcode.com/problems/valid-number/discuss/1209315/JS-Python-Java-C%2B%2B-or-Easy-Character-Conditional-Solution-w-Explanation
 */

//TC: O(N), SC : (1)
bool isValidNumber(string S) {
	if(S.empty()) return false;
	bool sign = false, exp = false, dec = false, num = false;

	for(auto c : S) {
		if(c >= '0' && c <= '9') num = true;
		else if (c == 'e' || c == 'E')
			if(exp || !num) return false;
			else exp = true, sign = false, num = false, dec = false;
		else if(c == '+' || c == '-')
			if(sign || num || dec) return false;
			else sign = true;
		else if(c == '.')
			if(dec || exp) return false;
			else dec = true;
		else
			return false;
	}
	return num;
}
/*
int main() {
	cout << isValidNumber("005047e+6");

	return 0;
}*/
