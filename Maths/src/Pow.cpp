#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/powx-n/
 * Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
 * Input: x = 2.00000, n = 10
Output: 1024.00000
https://leetcode.com/problems/powx-n/discuss/739646/C%2B%2B-Iterative-vs.-Recursive-Bitwise-Solutions-Explained-100-Time-80-space
 */
// TC: O(LOGN)  :For each bit of n 's binary representation, we will at most multiply once. So the total time complexity is, SC : O(1)
double pow(double x, int n) {
	double res = 1;
	while(n) {
		if(n % 2)
			res = n > 0 ? res * x : res / x;
		x = x * x;
		n /= 2;
	}
	return res;
}

/*
int main() {
	cout << pow(2.000, 10) << endl;

	return 0;
}*/
