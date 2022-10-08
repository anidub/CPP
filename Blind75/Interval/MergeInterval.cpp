#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/merge-intervals/
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an
 * array of the non-overlapping intervals that cover all the intervals in the input.
 *
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
 */
class MergeInterval {
public:
	static bool comparator(vector<int> i1, vector<int> i2) {
		return i1[0] < i2[0];
	}

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> result;
		if(intervals.empty()) return result;

		sort(intervals.begin(), intervals.end());
		result.push_back(intervals[0]);

		for(int i = 1; i < intervals.size(); i++) {
			vector<int> v = result[result.size() - 1];

			if(intervals[i][0] <= v[1]) {// cur start is before last end
				v[0] = min(v[0], intervals[i][0]);
				v[1] = max(v[1], intervals[i][1]);
				result[result.size() - 1] = v;
			} else // mean cur start in after last's end
				result.push_back(intervals[i]);
		}
		return result;
	}
};

/*
int main() {
	MergeInterval mi;
	vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
	mi.merge(intervals);
}
*/
