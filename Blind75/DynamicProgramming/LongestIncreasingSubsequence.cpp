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

https://segmentfault.com/a/1190000003819886 : optimal better
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

	//TC:O(NLOGN), SC:O(N)
	int lengthOfLIS_BinaryReadable(vector<int> &nums) {
		if(nums.empty()) return 0;
		int len = 0;
		int tails[nums.size()];
		tails[0] = nums[0];

		for(int i = 1; i < nums.size(); i++) {
			if(nums[i] < tails[0])
				tails[0] = nums[i];
			else if(nums[i] > tails[len])
				tails[++len] = nums[i];
			else
				tails[binarySearch(tails, 0, len, nums[i])] = nums[i];
		}
		return len + 1;
	}

private:
	 int binarySearch(int tails[], int left, int right, int target) {
		 while(left <= right) {
			 int mid = left + (right - left) / 2;
			 if(tails[mid] == target)
				 return mid;
			 if(target > tails[mid])
				 left = mid + 1;
			 if(target > tails[mid])
				 right = mid - 1;
		 }
		 return left;
	 }
	
public:
int binarySearch(int tails[], int left, int right, int target) {
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(tails[mid] == target) 
                return mid;
            if(tails[mid] < target)
                left = mid + 1;
            if(tails[mid] > target)
                right = mid - 1;
        }
        return left;
    }
    //https://leetcode.com/problems/coin-change/discuss/1371738/C%2B%2B-Recursion-greater-DP-Memoization-greater-DP-Tabulation
   // TC:O(2 ^ N), SC:O(N)
    int lengthOfLISBrute(vector<int>& nums) {
        return lengthOfLISBrute(nums, 0, INT_MIN);
    }
    
    int lengthOfLISBrute(vector<int>& nums, int i, int prev) {
        if(i >= nums.size()) return 0;
        int take = 0, doNotTake = lengthOfLISBrute(nums, i + 1, prev);
        if(nums[i] > prev) take = 1 + lengthOfLISBrute(nums, i + 1, prev);
        return max(take, doNotTake);
    }
    
    
     // TC:O(N ^ 2), SC:O(N ^ 2)
    vector<vector<int>> memo;
    int lengthOfLISMemo(vector<int>& nums) {
        memo.resize(nums.size(), vector<int>(nums.size() + 1, -1));
        return lengthOfLISMemo(nums, 0, -1);
    }
    
    int lengthOfLISMemo(vector<int>& nums, int i, int prev_i) {
        if(i >= nums.size()) return -1;
        if(memo[i][prev_i] != -1) return memo[i][prev_i];
        int take = 0, doNotTake = lengthOfLISMemo(nums, i + 1, prev_i);
        if(prev_i == -1 || nums[i] > prev_i) take = 1 + lengthOfLISMemo(nums, i + 1, prev_i);
        memo[i][prev_i] = max(take, doNotTake);
        return memo[i][prev_i];
    }
    
    
     // TC:O(N ^ 2), SC:O(N)
    int lengthOfLISDP(vector<int> &nums) {
        int ans = 1, n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};

/*
int main() {
	LongestIncreasingSubsequence lis;
	vector<int> nums = {10,9,2,5,3,7,101,18};
	cout << lis.lengthOfLIS_DP(nums) << endl;

	cout << lis.lengthOfLIS_Binary(nums) << endl;

	cout << lis.lengthOfLIS_BinaryReadable(nums) << endl;

	return 0;
}
*/
