#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
 * Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times
 * Input: k = 7
Output: 2
Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ...
For k = 7 we can use 2 + 5 = 7.

https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/discuss/712255/C%2B%2B-simple-greedy-solution
https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/discuss/585577/C%2B%2B-Greedy
https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/discuss/585632/JavaC%2B%2BPython-Easy-Prove
 */

int findMinFibOptimal(int k) {
	int f1 = 0, f2 = 1;
	while(f2 <= k) {
		//swap(f1, f2); // works
		f2 += f1;
	}
	return 1 + (k == f1 ? 0 : findMinFibOptimal(k - f1));
}

int finMinFib(int k) {
	vector<int> fiboNumbers{1,1};
	int count = 0;
	while(fiboNumbers.back() < k)
		fiboNumbers.push_back(fiboNumbers[fiboNumbers.size() - 1] + fiboNumbers[fiboNumbers.size() - 2]);

	while(k) {
		if(fiboNumbers.back() <= k) {
			k = k - fiboNumbers.back();
			count++;
		}
		fiboNumbers.pop_back();
	}
	return count;
}
/*
int main() {
	cout << finMinFib(7) << endl;
	//cout << findMinFibOptimal(7) << endl;
	return 0;
}
*/
