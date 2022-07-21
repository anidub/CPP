#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/maximum-length-of-repeated-subarray/
 * Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
 * Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
https://www.youtube.com/watch?v=Zg3HBicw4LU
https://just4once.gitbooks.io/leetcode-notes/content/leetcode/binary-search/718-maximum-length-of-repeated-subarray.html : used
https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/1324248/C%2B%2BPython-DP-KMP-Hashing-Solutions-Clean-and-Concise-O(NlogN)
 */
//Time: O(M*N), where M <= 1000 is length of nums1, N <= 1000 is length of nums2.
//Space: O(M*N)
int findLengthLongestCommon(vector<int> &A, vector<int> &B) {
	if(A.empty() || B.empty()) return 0;
	int m = A.size(), n = B.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	int ans = 0;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(A[i] == B[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				ans = max(ans, dp[i + 1][j + 1]);
			}
		}
	}
	return ans;
}
/*
int main() {
	vector<int> A = {1, 2, 3 ,2 ,1};
	vector<int> B = {3, 2, 1, 4, 7};
	cout << findLengthLongestCommon(A, B) << endl;
}*/
