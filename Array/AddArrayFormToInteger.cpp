#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/add-to-array-form-of-integer/
 * For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].
Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.
Example 1:
Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
https://leetcode.com/problems/add-to-array-form-of-integer/discuss/955987/C%2B%2B%3A-Faster-than-91-of-C%2B%2B
 */

vector<int> addToArrayForm(vector<int>& A, int K) {
	for(int i = A.size() - 1; i >= 0 && K > 0; i--) {
		K = K + A[i];
		A[i] = K % 10;
		K = K/10;
	}

	while( K > 0) {
		A.insert(A.begin(), K % 10);
		K = K / 10;
	}
	return A;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(0);nums.push_back(0);
	addToArrayForm(nums, 34);

	return 0;
}*/

