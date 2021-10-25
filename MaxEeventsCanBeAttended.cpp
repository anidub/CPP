#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
 * You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.
Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2 : use diagram on leetcode to better understand
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.

Now start traversing the events, at each event we have two options:

Skip this event and move to next event, no change in profit.
Attend this event add its profit and move to next such event whose starting time is greater than the ending time of this event.
Compare the profits made by these two choices and return the maximum value of the two.

https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/discuss/1052442/Simple-DP-Solution-or-Recursion-%2B-Memoization-or-C%2B%2B
Note:
for(i = pos + 1; i < n; i++)
            if(events[i][0] > events[pos][1])
                break;
This can be O(n) atmax hence we can optimise it by using binary search.

vector<int> temp = {events[pos][1],INT_MAX,INT_MAX};
i = upper_bound(events.begin()+pos+1, events.end(), temp)-events.begin();
 */

int solveMaxValueRecursion(vector<vector<int>>& events, int n, int pos, int k) {
	int i;
	if(pos >= n || k == 0)
		return 0;

	for(i = pos+1; i < n; i++) {
		if(events[i][0] > events[pos][1])
			break;
	}

	return max(solveMaxValueRecursion(events, n, pos+1, k), events[pos][2] + solveMaxValueRecursion(events, n, i, k-1));
}
// works but TLE
int maxValueEventsCanAttend(vector<vector<int>>& events, int k) {
	if(events.empty()) return 0;
	int n = events.size();
	sort(events.begin(), events.end());
	return solveMaxValueRecursion(events, n, 0, k);
}

int maxValueEventsCanAttendDPHelper(vector<vector<int>>& dp,vector<vector<int>>& events, int n, int pos, int k) {
	int i;
	if(pos >= n || k == 0) return 0;

	if(dp[pos][k] != -1) return dp[pos][k];

	for(i = pos+1; i < n; i++) {
		if(events[i][0] > events[pos][1])
			break;
	}

	return dp[pos][k] = max(maxValueEventsCanAttendDPHelper(dp, events, n, pos+1, k), events[pos][2] + maxValueEventsCanAttendDPHelper(dp, events, n, i, k-1));
}

int maxValueEventsCanAttendDP(vector<vector<int>> events, int k) {
	if(events.empty()) return 0;
	int n = events.size();
	sort(events.begin(), events.end());
	vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

	return maxValueEventsCanAttendDPHelper(dp,events,  n, 0, k);
}
/*
int main() {

	vector<vector<int>> events;
	vector<int> e1; e1.push_back(1);e1.push_back(2);e1.push_back(4);
	vector<int> e2; e2.push_back(3);e2.push_back(4);e2.push_back(3);
	vector<int> e3; e3.push_back(2);e3.push_back(3);e3.push_back(1);
	events.push_back(e1);events.push_back(e2);events.push_back(e3);
	cout << maxValueEventsCanAttend(events, 2) << endl;
	cout << maxValueEventsCanAttendDP(events, 2) << endl;
	return 0;
}*/
