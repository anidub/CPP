#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/the-kth-factor-of-n/
 * You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
https://leetcode.com/problems/the-kth-factor-of-n/discuss/1662755/C%2B%2B-O(n)-greater-O(n2)-or-0ms-Easy-to-Understand

 */
//TC: O(n/2)
int kthFactor(int n, int k) {
	for(int i = 1; i <= n/2; i++ ){
		if(n % i == 0) k--;
		if(k == 0) return i;
	}
	if(k == 1) return n;
	return -1;
}
/*https://leetcode.com/problems/the-kth-factor-of-n/discuss/708099/C%2B%2BJava-Straightforward-%2B-Sqrt(n)
 */
//TC: O(sqrt n)
int kthFactorOptimal(int n, int k) {
    float root = sqrt(n);
    for (int i=1; i<root; i++) {
        if (n % i == 0 && --k == 0) return i;
    }

    for (int i=root; i>0; i--) {
        if (n % i == 0 && --k == 0) return n/i;
    }
    return -1;
}
/*
int main() {
	cout << kthFactor(12,3) << endl;

}*/
