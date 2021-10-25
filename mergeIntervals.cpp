#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/merge-intervals/
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
https://leetcode.com/problems/merge-intervals/discuss/608186/C%2B%2B-or-Easy-to-understand
https://leetcode.com/problems/merge-intervals/discuss/21488/My-easy-C%2B%2B-solution //comparator
 */
static bool comparator(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

vector<vector<int>> mergeInternals(vector<vector<int>>& intervals) {
	if(intervals.empty()) return {};

	vector<vector<int>> result;
	sort(intervals.begin(), intervals.end(), comparator);

	result.push_back(intervals[0]);

	for(int i = 1; i < intervals.size(); i++) {
		vector<int> v = result[result.size() - 1];
		if(v[1] >= intervals[i][0]) {
			v[0] = min(v[0], intervals[i][0]);
			v[1] = max(v[1], intervals[i][1]);
			result[result.size()-1] = v;
		} else {
			result.push_back(intervals[i]);
		}
	}
	return result;
}
/*
int main() {
	vector<vector<int>> intervals;
	vector<int> v1; v1.push_back(1); v1.push_back(3);
	vector<int> v2; v2.push_back(2); v2.push_back(6);
	vector<int> v3; v3.push_back(8); v3.push_back(10);
	vector<int> v4; v4.push_back(15); v4.push_back(18);
	intervals.push_back(v1); intervals.push_back(v2);
	intervals.push_back(v3);intervals.push_back(v4);
	mergeInternals(intervals);
	return 0;
}
*/
