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
/*https://leetcode.com/problems/integer-to-roman/
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
https://leetcode.com/problems/integer-to-roman/discuss/1422472/c%2B%2B-solution
 */
//Time complexity : O(1)
string intToRoman(int num) {
	int intCode[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	string code[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX",  "V", "IV", "I"};
	string s;
	for(int i = 0; i < 13; i++) {
		while(num >= intCode[i]) {
			s.append(code[i]);
			num -= intCode[i];
		}
	}
	return s;
}
/*
int main() {
	cout <<  intToRoman(3) << endl;
	return 0;
}*/
