#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/beautiful-arrangement-ii/
 * Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement:
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
If there are multiple answers, print any of them.
Example 1:
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
to understand example: https://www.youtube.com/watch?v=WLFXfcUVeeU
https://leetcode.com/problems/beautiful-arrangement-ii/discuss/155971/c%2B%2B-100-easy-to-explain-and-impl-in-13mins.-may-have-time-for-another-hard. : used
https://leetcode.com/problems/beautiful-arrangement-ii/discuss/106958/c%2B%2B-o(N)-with-comments
 */
vector<int> constructArrayBeautifulArrange(int n, int k) {
	vector<int> result;
	if(k > n-1) return result;

	int start = 1;
	int end = n;
	bool left = true;

	for(int i = 0; i < k; i++) {
		if(left) {
			result.push_back(start);
			start++;
			left = false;
		} else {
			result.push_back(end);
			end--;
			left = true;
		}
	}

	if(left) {
		for(int i = end; i >= start; i--) {
			result.push_back(i);
		}
	} else {
		for(int i = start; i <= end; i++) {
			result.push_back(i);
		}
	}
	return result;
}
/*
int main() {
	constructArrayBeautifulArrange(3,2);
	return 0;
}*/
