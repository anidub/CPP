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
/*https://leetcode.com/problems/roman-to-integer/
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M
 * Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

 * For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
 *
 * Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
https://leetcode.com/problems/roman-to-integer/discuss/6547/Clean-O(n)-c%2B%2B-solution : comments
 */
//Tc : O(N)
int romanToInteger(string s) {
	if(s.empty()) return 0;
	unordered_map<char, int> table = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
	};

	int num = 0;
	for(int i = 0; i < s.length() - 1; i++) {
		if(table[s[i]] < table[s[i+1]])
			num -= table[s[i]];
		else
			num += table[s[i]];
	}
	num += table[s.back()];

	return num;
}
/*
int main() {
	cout << romanToInteger("MCMXCIV") << endl;
	return 0;
}
*/
