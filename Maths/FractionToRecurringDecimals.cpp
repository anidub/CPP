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
/*https://leetcode.com/problems/fraction-to-recurring-decimal/
 * Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
Input: numerator = 4, denominator = 333
Output: "0.(012)"

https://leetcode.com/problems/fraction-to-recurring-decimal/discuss/51160/C%2B%2B-unordered_map
 */
string fractionToDecimal(int numerator, int denominator) {
	if(!numerator) return "0";
	string ans;

	if(numerator < 0 || denominator < 0) ans += '-';
	if(numerator < 0 && denominator < 0) ans = "";

	long n = labs(numerator), d = labs(denominator), r = n % d;

	ans += to_string(n / d);
	if(r == 0) return ans;

	ans += '.';
	unordered_map<long, int> rs;
	while(r) {
		if(rs.find(r) != rs.end()) {
			ans.insert(rs[r], "(");
			ans += ')';
			break;
		}
		rs[r] = ans.size();
		r *= 10;
		ans += to_string(r / d);
		r %= d;
	}
	return ans;
}
/*
int main() {
	cout << fractionToDecimal(4, 333) << endl;
	return 0;
}*/
