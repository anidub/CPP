#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/max-dot-product-of-two-subsequences/
 * Given two arrays nums1 and nums2.
Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

Example 1:

Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.
https://leetcode.com/problems/max-dot-product-of-two-subsequences/discuss/648420/JavaC%2B%2BPython-the-Longest-Common-Sequence : comments
 */
//Time O(MN) Space O(MN)
int maxDotProductTwoSubsequences(vector<int>& nums1, vector<int>& nums2) {
	if(nums1.empty() || nums2.empty()) return 0;
	int a = nums1.size(); int b = nums2.size();

	vector<vector<int>> dp(a, vector<int>(b, 0));

	for(int i = 0; i < a; i++) {
		for(int j = 0; j < b; j++) {
			dp[i][j] = nums1[i] * nums2[j];
			if(i && j)
				dp[i][j] += max(0, dp[i-1][j-1]);
			if(i)
				dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if(j)
				dp[i][j] = max(dp[i][j], dp[i][j-1]);
		}
	}
	return dp[a-1][b-1];
}
/*
int main() {
	vector<int> nums1; nums1.push_back(2);nums1.push_back(1);nums1.push_back(-2);nums1.push_back(5);
	vector<int> nums2; nums2.push_back(3);nums2.push_back(0);nums2.push_back(-6);
	cout << maxDotProductTwoSubsequences(nums1, nums2) << endl;

	return 0;
}*/
