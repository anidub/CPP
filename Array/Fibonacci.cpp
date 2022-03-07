#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode.com/problems/fibonacci-number/
 * https://leetcode.com/problems/fibonacci-number/discuss/776129/C%2B%2B-recursive-solution-from-cpprefrence
 * https://leetcode.com/problems/fibonacci-number/discuss/306822/C%2B%2B-solution // use this
 *
 * F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).
Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
 */
int fibonacci(int n) {
	if(n < 2)
		return n;
	return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacciIterative(int n) {
	if(n < 2)
		return n;
	int result = 0;
	int a = 0; int b = 1;
	for(int i = 2; i <= n; i++) {
		result = a + b;
		a = b;
		b = result;
	}

	return result;
}

/*
int main() {
	cout << fibonacci(4) << endl;
	cout << fibonacciIterative(4) << endl;

	return 0;
} */
