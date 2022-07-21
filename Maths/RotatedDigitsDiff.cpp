#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/rotated-digits/
 * An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].
Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotatin
https://leetcode.com/problems/rotated-digits/discuss/383720/VERY-CLEAR-EXPLANATION-OF-QUESTION : to understand problem
https://leetcode.com/problems/rotated-digits/discuss/1286139/100-faster-or-Very-easy-or-C%2B%2B : used
https://leetcode.com/problems/rotated-digits/discuss/130681/simple-easy-C%2B%2B
 */

bool check(int n);

int rotatedDigits(int N) {
	int ans = 0;
	for(int i = 2; i <= N; i++) {
		ans += check(i);
	}
	return ans;
}

bool check(int n) {
	int t; bool flag = 0;
	while(n) {
		t = n % 10;
		if(t == 3 || t == 4 || t == 7) return 0;
		if(t == 2 || t == 5 || t == 6 || t == 9)
			flag = 1;
		n /= 10;
	}
	return flag;
}
/*
int main() {
	cout << rotatedDigits(10) << endl;

	return 0;
}*/
