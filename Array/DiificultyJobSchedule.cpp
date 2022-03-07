#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
 * You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the i-th job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done in that day.

Given an array of integers jobDifficulty and an integer d. The difficulty of the i-th job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.
Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7
https://www.youtube.com/watch?v=pmQAtRZ3CuE : to understand
https://www.tutorialspoint.com/minimum-difficulty-of-a-job-schedule-in-cplusplus
 */
int dfs_minDifficultyJobASchedule(vector<int>& jobs, int idx, int k, vector<vector<int>>& dp) {
	if(idx == jobs.size() && k == 0) return 0;
	if(k < 0 || idx == jobs.size() && k > 0) return 1e6;
	if(dp[idx][k] != -1) return dp[idx][k];

	int maxVal = 0;
	int result = INT_MAX;
	for(int i = idx; i < jobs.size(); i++) {
		maxVal = max(maxVal, jobs[i]);
		result = min(result, maxVal + dfs_minDifficultyJobASchedule(jobs, i+1, k-1, dp));
	}
	return dp[idx][k] = result;
}
//Time complexity O(nnd) Space complexity O(nd)
int minDifficultyJobASchedule(vector<int>& jobs, int d) {
	int n = jobs.size();
	if(d > n) return -1;
	vector<vector<int>> dp(n, vector<int>(d+1, -1));
	return dfs_minDifficultyJobASchedule(jobs, 0, d, dp);
}
/*
int main() {
	vector<int> jobs;
	jobs.push_back(6);jobs.push_back(5);jobs.push_back(4);
	jobs.push_back(3);jobs.push_back(2);jobs.push_back(1);
	cout << minDifficultyJobASchedule(jobs, 2) << endl;
	return 0;
}*/
