#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/happy-number/
 * Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
https://leetcode.com/problems/happy-number/solution/
 */

int getNext(int n);
//TC:O(LOGN), SC:O(1)
bool isHappy(int n) {
	int slow = n;
	int fast = getNext(n);

	while(fast != 1 && slow != fast) {
		slow = getNext(slow);
		fast = getNext(getNext(fast));
	}
	return fast == 1;
}

int getNext(int n) {
	int total = 0;
	while(n > 0) {
		int d = n % 10;
		n /= 10;
		total += d * d;
	}
	return total;
}
/*
int main() {
	cout << isHappy(19) << endl;

	return 0;
}*/
