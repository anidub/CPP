#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/minimum-cost-to-merge-stones/
 * There are n piles of stones arranged in a row. The ith pile has stones[i] stones.

A move consists of merging exactly k consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these k piles.

Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.
Input: stones = [3,2,4,1], k = 2
Output: 20
Explanation: We start with [3, 2, 4, 1].
We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
We merge [4, 1] for a cost of 5, and we are left with [5, 5].
We merge [5, 5] for a cost of 10, and we are left with [10].
The total cost was 20, and this is the minimum possible.
https://leetcode.com/problems/minimum-cost-to-merge-stones/discuss/1182484/C%2B%2B-Top-Down-DP-Solution
works
 */

class MinCostMergeStones {
private:
	vector<int> prefix;
	vector<vector<int>> dp;

public:

	int merge(int l, int r, int k) { //WORKS
		if(r - l + 1 < k) return 0;
		if(r - l + 1 == k) return prefix[r + 1] - prefix[l];
		if(dp[l][r] != -1) return dp[l][r];
		
		int res = INT_MAX;
		for(int i = l; i < r; i+= k-1)
			res = min(res, merge(l, i, k) + merge(i+1, r, k));
			
		if((r - l) % (k-1) == 0) res += prefix[r + 1] - prefix[l];
		
		cout << "res:" << res << endl;
		return dp[l][r] = res;
 	}
	
	int minimumCostMergeStones(vector<int>& stones, int K) {// WORKS
		int n = stones.size();
		/*if(stones.empty()) return -1;
		if((stones.size() - 1) % (K-1) != 0) return -1;
		

		prefix = vector(n+1, 0);
		dp = vector(n, vector<int>(n, -1));
		
		for(int i = 0; i < n; i++)
			prefix[i+1] = prefix[i] + stones[i];*/
 		return merge(0, n-1, K);
 	} 	
 	
};
/*
int main() {
	vector<int> stones; stones.push_back(3);stones.push_back(2);stones.push_back(4);stones.push_back(1);
	MinCostMergeStones mc;
	mc.minimumCostMergeStones(stones, 2);
	
	return 0;
}
*/
