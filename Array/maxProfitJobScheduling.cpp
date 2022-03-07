#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/maximum-profit-in-job-scheduling/
 * We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/411535/C%2B%2B-DP-explained-with-an-example-...
 */

struct work{
	int start;
	int end;
	int profit;
};

static int sortFunction(work m, work n) { /* Sort by end time */
	return m.end < n.end;
}
// Time:O(n^2)
int maxProfitJobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
	if(startTime.empty()) return 0;
	 /* dp[i] holds the maximum profit from all includable (non-overlapping) items from 0 through i */
	int sz = startTime.size(), dp[sz];
	vector<work> works(sz);

	for(int i = 0; i < sz; i++) {
		works[i].start = startTime[i];
		works[i].end = endTime[i];
		works[i].profit = profit[i];
	}
	 /* Sort objects by end time */
	sort(works.begin(), works.end(), sortFunction);

	for(int i = 0; i < sz; i++) {
		if(!i) {
			dp[i] = works[i].profit;
			continue;
		}
		int f = 0;/* find last non-overlapping job that ends before start of this current job and record max profit up to j, dp[j] */
		for(int j = i-1; j >= 0; j--) {
			if(works[j].end <= works[i].start) {
				f = dp[j];
				break;
			}
		}
		dp[i] = max(dp[i-1], /* last max profit calculated from 0 .. i-1 */
				(f + works[i].profit)); /* current profit and max profit up to last non-overlapping job */
	}
	return dp[sz-1];
}
/*
int main() {
	vector<int> startTime; startTime.push_back(1);startTime.push_back(2);startTime.push_back(3);startTime.push_back(3);
	vector<int> endTime; endTime.push_back(3);endTime.push_back(4);endTime.push_back(5);endTime.push_back(6);
	vector<int> profit; profit.push_back(50);profit.push_back(10);profit.push_back(40);profit.push_back(70);
	cout << maxProfitJobScheduling(startTime, endTime, profit) << endl;
	return 0;
}*/
