#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/insert-interval/
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.
Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
https://leetcode.com/problems/insert-interval/discuss/21815/Two-Easy-O(n)-C%2B%2B-Solutions-with-Explanations
 */
vector<int> merge(vector<int> interval, vector<int> newInterval) {
	int start = min(interval[0], newInterval[0]);
	int end = max(interval[1], newInterval[1]);
	return {start , end};
}

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
	vector<vector<int>> result;
	if(intervals.size() == 0) {
		result.push_back(newInterval);
		return result;
	}

	int n = intervals.size();

	for(int i = 0; i < n; i++) {
		if(intervals[i][1] < newInterval[0])
			result.push_back(intervals[i]);
		else if(newInterval[1] < intervals[i][0]){
			result.push_back(newInterval);
			for(int j = i; j < n; j++) {
				result.push_back(intervals[j]);
			}
			return result;
		} else
			newInterval = merge(intervals[i], newInterval);
	}
	result.push_back(newInterval);
	return result;
}
/*
int main() {
	vector<vector<int>> intervals;
	vector<int> i1; i1.push_back(1);i1.push_back(3);
	vector<int> i2; i2.push_back(6);i2.push_back(9);
	intervals.push_back(i1); intervals.push_back(i2);
	vector<int> newInterval; newInterval.push_back(2); newInterval.push_back(5);
	insertInterval(intervals, newInterval);
	return 0;
}*/
