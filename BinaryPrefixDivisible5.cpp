#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/binary-prefix-divisible-by-5/
 *Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to A[i] interpreted as a binary number (from most-significant-bit to least-significant-bit.)
Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.\
Example 1:
Input: [0,1,1]
Output: [true,false,false]
Explanation:
The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.  Only the first number is divisible by 5, so answer[0] is true.
 https://leetcode.com/problems/binary-prefix-divisible-by-5/discuss/372134/Simple-C%2B%2B-Solution-beats-98-100
 https://leetcode.com/problems/binary-prefix-divisible-by-5/discuss/265541/C%2B%2B-4-lines
 */
vector<bool> prefixDivisibleBy5(vector<int>& A) {
	vector<bool> result;
	int num = 0;
	for(int i = 0; i < A.size(); i++) {
		num = num * 2 + A[i];
		cout << "num:" << num << endl;
		num = num % 5; //to prevent overflow for large input;
		result.push_back(num == 0);
	}
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(0);nums.push_back(1);nums.push_back(1);
	prefixDivisibleBy5(nums);

	return 0;
}
*/
