#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
 * https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
 * A sequence X1, X2, ..., Xn is Fibonacci-like if:

n >= 3
Xi + Xi+1 = Xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.
A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].
Example 1:

Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].

optimal: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/discuss/152537/C%2B%2B-DP-solution comments O(N^2)
https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/discuss/152343/C%2B%2BJavaPython-Check-Pair Time Complexity:O(N^2logM), where M is the max(A).
 */

int lenLongestFiboSeq(vector<int>& arr) {
	if(arr.empty()) return 0;
	int n = arr.size();
	int result = 0;
	unordered_set<int> s(arr.begin(), arr.end());
	for(int i = 0 ; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			int a = arr[i]; int b = arr[j];
			int l = 2;
			while(s.count(a+b)) {
				b = b + a;
				a = b - a;
				l++;
			}
			result = max(result, l);
		}
	}
	return result > 2 ? result : 0;
}

int lenLongestFiboSeqOptimal(vector<int>& arr) {
	if(arr.empty()) return 0;
	int n = arr.size();
	int result = 0;
	unordered_map<int, int> m;
	for(int i = 0 ; i < n; i++)
		m[arr[i]] = i;

	vector<vector<int>> dp(n, vector<int>(n, 2));
	for(int r = 1; r < n; r++) {
		for(int l = 0; l < r; l++) {
			//X  + arr[l] = arr[r]
			// arr[r] - arr[l] = X
			int X = arr[r] - arr[l];
			if(m.find(X) != m.end() && m[X] < l) {
				dp[l][r] = max(dp[l][r], dp[m[X]][l] + 1);
			}
			result = max(result, dp[l][r]);
		}
	}
	return result;
}
/*
int main() {
	vector<int> arr;
	arr.push_back(1);arr.push_back(2);arr.push_back(3);arr.push_back(4);arr.push_back(5);arr.push_back(6);arr.push_back(7);arr.push_back(8);
	cout << lenLongestFiboSeq(arr) << endl;
	cout << lenLongestFiboSeqOptimal(arr) << endl;
	return 0;
}
*/
