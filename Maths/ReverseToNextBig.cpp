#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/reverse-integer/
 *Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 */

int reverseToNextBig(int n) {
	long result = 0;

	while(n != 0) {
		result = result * 10 + n % 10;
		n = n / 10;
	}
	return (result > INT_MAX || result < INT_MIN) ? 0 : result;
}
/*
int main() {
	cout << reverseToNextBig(123) << endl;

	return 0;
}*/
