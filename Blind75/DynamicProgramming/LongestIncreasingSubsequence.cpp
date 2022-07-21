#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/longest-increasing-subsequence/
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.
 For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326552/Optimization-From-Brute-Force-to-Dynamic-Programming-Explained!

https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation
 */
class LongestIncreasingSubsequence {
public:
	//YC:O(N^2), SC:O(N^2)
	int lengthOfLIS_DP(vector<int> &nums) {
		if(nums.empty()) return -1;
		int ans = 1, n = nums.size();

		vector<int> dp(n, 1);

		for(int i = 0; i < nums.size(); i++) {
			for(int j = 0; j < i; j++) {
				if(nums[i] > nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
					ans = max(ans, dp[i]);
				}
			}
		}
		return ans;
	}

	//TC:O(NLOGN), SC:O(N)
	int lengthOfLIS_Binary(vector<int> &nums) {
		int n = nums.size();
		vector<int> tails(n);
		int size = 0;

		for(int x : nums) {
			int i = 0, j = size;
			while(i != j) {
				int mid = (i + j) / 2;
				if(tails[mid] < x)
					i = mid + 1;
				else
					j = mid;
			}
			tails[i] = x;
			if(i == size) size++;
		}
		return size;
	}
};

/*
int main() {
	LongestIncreasingSubsequence lis;
	vector<int> nums = {10,9,2,5,3,7,101,18};
	cout << lis.lengthOfLIS_DP(nums) << endl;

	cout << lis.lengthOfLIS_Binary(nums) << endl;

	return 0;
}
*/
