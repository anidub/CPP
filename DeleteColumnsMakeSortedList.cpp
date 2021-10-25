#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
 * You are given an array of n strings strs, all of the same length.
We may choose any deletion indices, and we delete all the characters in those indices for each string.
For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].
Suppose we chose a set of deletion indices answer such that after deletions, the final array has every string (row) in lexicographic order. (i.e., (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]), and (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]), and so on). Return the minimum possible value of answer.length.
Example 1:

Input: strs = ["babca","bbazb"]
Output: 3
Explanation: After deleting columns 0, 1, and 4, the final array is strs = ["bc", "az"].
Both these rows are individually in lexicographic order (ie. strs[0][0] <= strs[0][1] and strs[1][0] <= strs[1][1]).
Note that strs[0] > strs[1] - the array strs is not necessarily in lexicographic order.
https://leetcode.com/problems/delete-columns-to-make-sorted-iii/discuss/205679/JavaC%2B%2BPython-Maximum-Increasing-Subsequence
 *
 */
/*Complexity:
O(N^2) to find increasing subsequence
O(M) for comparing elements.
So Overall O(MN^2) time.
Space O(N) for dp.*/
int minDeletionSortedList(vector<string>& strs) {
	if(strs.empty()) return 0;
	int m = strs.size(), n = strs[0].size();
	int result = n-1, k;
	vector<int> dp(n, 1);

	for(int j = 0; j < n; j++) {
		for(int i = 0; i < j; i++) {
			for(k = 0; k < m; k++) {
				if(strs[k][i] > strs[k][j])
					break;
			}
			if(k == m && dp[i] + 1 > dp[j])
				dp[j] = dp[i] + 1;
		}
		result = min(result, n - dp[j]);
	}
	return result;
}
/*
int main() {
	vector<string> strs;
	strs.push_back("babca"); strs.push_back("bbazb");
	cout << minDeletionSortedList(strs) << endl;
	return 0;
}
*/
