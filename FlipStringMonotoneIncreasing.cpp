#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>

using namespace std;
/*
 * https://leetcode.com/problems/flip-string-to-monotone-increasing/
 * A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)
We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.
Return the minimum number of flips to make S monotone increasing.
Example 1:
Input: "00110"
Output: 1
Explanation: We flip the last digit to get 00111.

Example 2:
Input: "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/696839/C%2B%2B-or-O(1)-space-or-O(n)-Runtime-or-2-pass
https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/183889/C%2B%2B-time-O(n)-Just-keep-count-of-0's-and-1's
https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/183851/C%2B%2BJava-4-lines-O(n)-or-O(1)-DP
 */

int minFlipsMonoIncrOptimal(string S){
	int n = S.length();

	int result = 0, ones = 0;
	for(int i = 0; i < n; i++) {
		result = min(result, ones);
		if(S[i] == '0')
			result++;
		else
			ones++;
	}
	return min(result, ones);
}

int minFlipMonoIncr(string S) {
	int count1 = 0, count0 = 0;
	for(int i = 0; i < S.length(); i++){
		if(S[i] == '0')
			count0++;
	}

	int result = count0;
	for(int i = 0; i < S.length(); i++) {
		if(S[i] == '1')
			count1++;
		else
			count0--;
		result = min(result, count0 + count1);
	}
	return result;
}
/*
int main() {
	string S = "010110";
	cout << minFlipMonoIncr(S) << endl;
	cout << minFlipsMonoIncrOptimal(S) << endl;
}
*/
