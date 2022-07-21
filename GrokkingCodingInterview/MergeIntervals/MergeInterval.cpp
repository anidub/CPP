#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;

/*https://www.educative.io/courses/grokking-the-coding-interview/3jyVPKRA8yx
 * Given a list of intervals, merge all the overlapping intervals to produce a list that has only mutually exclusive intervals.
 * Intervals: [[1,4], [2,5], [7,9]]
Output: [[1,5], [7,9]]
Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged them into
one [1,5].

 */

static bool comparator(vector<int> i1, vector<int> i2) {
	return i1[0] < i2[0];
}
//TC:O(NLOGN), SC:O(1)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	if(intervals.empty()) return {};
	vector<vector<int>> result;
	sort(intervals.begin(), intervals.end(), comparator);
	result.push_back(intervals[0]);

	for(int i = 1; i < intervals.size(); i++) {
		vector<int> v = result.back();
		if(v[1] >= intervals[i][0]) {
			v[0] = min(v[0], intervals[i][0]);
			v[1] = max(v[1], intervals[i][1]);
			result[result.size() - 1] = v;
		} else
			result.push_back(intervals[i]);
	}
	return result;
}
