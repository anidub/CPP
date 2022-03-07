#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/maximum-length-of-repeated-subarray/
 * Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
Example 1:
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/259890/C%2B%2B-linear-space-DP
 *https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/109071/C%2B%2B-Easy-solution-with-explanation
https://www.youtube.com/watch?v=BysNXJHzCEs
 */

int findLengthLongestCommon(vector<int>& A, vector<int>& B) {
	if(A.empty() || B.empty()) return 0;
	int result = 0;
	int m = A.size(), n = B.size();
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j < n; j++) {
			if(A[i-1] == B[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				result = max(result, dp[i][j]);
			}
		}
	}
	return result;
}

int findLengthLongestOptimal(vector<int>& A, vector<int>& B) {
	if(A.empty() || B.empty()) return 0;
	int result = 0;
	int m = A.size(), n = B.size();
	vector<int> cur(n+1, 0);

	for(int i = 1; i <= m; i++) {
		int pre = cur[0];
		for(int j = 1; j <= n; j++) {
			int temp = cur[j];
			if(A[i-1] == B[j-1]) {
				cur[j] = pre + 1;
				result = max(result, cur[j]);
			}else {
				cur[j] = 0;
			}
			pre = temp;
		}
	}
	return result;
}

int findLengthNonDPHelper(vector<int>& A, vector<int>& B, int i, int j){
	int len = 0, count = 0;
	for(; i < A.size() && j < B.size(); i++, j++) {
		if(A[i] == B[j]){
			count++;
			len = max(len, count);
		} else
			count = 0;
	}
	return len;
}

int findLengthNonDP(vector<int>& A, vector<int>& B) {
	if(A.empty() || B.empty()) return 0;
	int result = 0, m = A.size(), n = B.size();
	for(int i = 0; i < m; i++)
		result = max(result, findLengthNonDPHelper(A, B, i, 0));

	for(int j = 0; j < n; j++)
		result = max(result, findLengthNonDPHelper(B, A, 0, j));

	return result;
}

/*
int main() {
	vector<int> A;
	A.push_back(1);A.push_back(2);A.push_back(3);A.push_back(2);A.push_back(1);
	vector<int> B;
	B.push_back(3);B.push_back(2);B.push_back(1);B.push_back(4);B.push_back(7);
	cout << findLengthLongestCommon(A, B) << endl;
	cout << findLengthLongestOptimal(A, B) << endl;
	cout << findLengthNonDP(A, B) << endl;

	return 0;
}
*/
