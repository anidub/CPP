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
/*https://leetcode.com/problems/divide-two-integers/
 *Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
https://leetcode.com/problems/divide-two-integers/discuss/13407/C%2B%2B-bit-manipulations : well explained
https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/

 left shifting an integer “x” with an integer “y” denoted as ‘(x<<y)’ is equivalent to multiplying x with 2^y (2 raised to power y)
 right shifting an integer “x” with an integer “y” denoted as ‘(x>>y)‘ is equivalent to dividing x with 2^y.
 */
// WORKS !!!
/*
int divideTwoIntegers(int dividend, int divisor) {
	if(dividend == INT_MIN && divisor == -1) return INT_MAX;

	long dvd = labs(dividend), dvs = labs(divisor), ans = 0;

	int sign = (dividend > 0 ^ divisor > 0) ? -1 : 1;

	while(dvd >= dvs) {
		long temp = dvs, m = 1;
		while(temp << 1 <= dvd) {
			temp <<= 1;
			m <<= 1;
		}
		dvd -= temp;
		ans += m;
	}
	return sign * ans;
} */
/*
int main() {
	cout << divideTwoIntegers(10, 3) << endl;

	return 0;
}*/

