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
/*https://leetcode.com/problems/minimum-cost-to-cut-a-stick/submissions/
 * Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:
Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.
The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.
Return the minimum total cost of the cuts.

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
https://www.youtube.com/watch?v=b63rJUp767s
https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/1357746/Easy-C%2B%2B-solution-oror-commented
 */

//statInd is the starting index value in c
//endInd is the ending index value in c
//startVal is the current starting value in the stick
//endVal is the current ending value in the stick
int dfs_cuts(vector<int>& cuts, int startInd, int endInd, int startVal, int endVal, vector<vector<int>>& dp) {
	if(startInd > endInd)
		return 0;
	//if the  sub problem is already calculated , return it
	if(dp[startInd][endInd] != -1)
		return dp[startInd][endInd];

	int ans = INT_MAX;
	//the current len of the stick is the current cost
	int cur_cost = endVal - startVal;

	for(int i = startInd; i <= endInd; i++) {
		//perform a cut at c[i] and get the min cost among all those
		ans = min(ans, cur_cost + dfs_cuts(cuts, startInd, i-1, startVal, cuts[i], dp) + dfs_cuts(cuts, i+1, endInd, cuts[i], endVal, dp));
	}

	dp[startInd][endInd] = ans;
	return ans;
}
//Time O(N^3) Space O(N^2),
int minCostCutStick(int n, vector<int>& cuts) {
	if(cuts.empty()) return 0;
	//sort the cut values
	sort(cuts.begin(), cuts.end());

	int len = cuts.size();
	vector<vector<int>> dp(len, vector<int>(len, -1));
	dfs_cuts(cuts, 0, len-1, 0, n, dp);
	return dp[0][len-1];
}
/*
int main() {
	vector<int> cuts;
	cuts.push_back(5);cuts.push_back(6);cuts.push_back(1);cuts.push_back(4);cuts.push_back(2);
	cout << minCostCutStick(9, cuts) << endl;
	return 0;
}*/
