#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/insert-interval/
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

 */
class InsertInterval {
public:
	//TC:O(N), SC:O(N) Sc: O(N) for output else O(1)
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> result;
		if(intervals.size() == 0) {
			result.push_back(newInterval);
			return result;
		}
		int n = intervals.size();

		for(int i = 0; i < n; i++) {
			if(intervals[i][1] < newInterval[0]) {
				result.push_back(intervals[i]);
			} else if(newInterval[1] < intervals[i][0]) {
				result.push_back(newInterval);
				for(int j = i; j < n; j++)
					result.push_back(intervals[j]);
				return result;
			} else {
				newInterval = merge(newInterval, intervals[i]);
			}
		}
		result.push_back(newInterval);
		return result;
	}
private:
	vector<int> merge(vector<int> newInterval, vector<int> interval) {
		int start = min(newInterval[0], interval[1]);
		int end = max(newInterval[1], interval[1]);
		return {start, end};
	}
};

/*
int main() {
	vector<vector<int>> intervals = {{1, 3}, {6, 9}};
	vector<int> newInterval = {2, 5};
	InsertInterval ii;
	ii.insert(intervals, newInterval);
}
*/
