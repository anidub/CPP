#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/basic-calculator-iii/
 * Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

https://leetcode.com/problems/basic-calculator-iii/discuss/757809/C%2B%2B-Explained-Template-for-Basic-Calculator-I-II-III
https://leetcode.com/problems/basic-calculator-iii/discuss/202979/A-generic-solution-for-Basic-Calculator-I-II-III
https://leetcode.com/problems/basic-calculator-iii/discuss/113593/C%2B%2B-Consise-Solution : comments

Use sign to remember the lasted operator we have met
Use number for the number we are operating
Use stack to track the number we have meet
 */
int parseString(string &s, int &i);
long parseNum(string &s, int& i);

int basicCalculator3(string s) {
	int i = 0;
	return parseString(s, i);
}

int parseString(string &s, int &i) {
	vector<int> nums;
	char op = '+';

	for(; i < s.length() && op != ')'; i++) {
		if(s[i] == ' ') continue;
		long n = s[i] == '(' ? parseString(s, ++i) : parseNum(s, i);
		switch(op) {
			case '+' : nums.push_back(n); break;
			case '-' : nums.push_back(-n); break;
			case '*' : nums.back() *= n; break;
			case '/' : nums.back() /= n; break;
		}
		if(i < s.length())// handle over flow of i in cases like "1 + 1"
			op = s[i];
	}
	return accumulate(nums.begin(), nums.end(), 0);
}

long parseNum(string &s, int &i) {
	long n = 0;
	while(i < s.length() && isdigit(s[i])) {
		n = s[i++] - '0' + 10 * n;
	}
	return n;
}
/*
int main() {
	cout << basicCalculator3("2*(5+5*2)/3+(6/2+8)") << endl;

	return 0;
}
*/
