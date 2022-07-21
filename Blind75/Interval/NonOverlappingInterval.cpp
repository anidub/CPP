#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/non-overlapping-intervals/
 *Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number
 *Given of intervals you need to remove to make the rest of the intervals non-overlapping.
 * Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

 */
class NonOverlappingInterval {
public:
	//TC:O(N), SC:O(1)
	int eraseOverlapIntervals(vector<vector<int>>& v) {
		if(v.empty()) return 0;
		sort(v.begin(), v.end());

		int count = 0, left = 0, right = 1, n = v.size();

		while(right < n) {
			if(v[left][1] <= v[right][0]) {
				left = right;
				right++;
			} else if(v[left][1] <= v[right][1]) {
				count++;
				right++;
			} else if(v[left][1] > v[right][1]) {
				left = right;
				count++;
				right++;
			}
		}
		return count;
	}
};
/*
int main() {
	NonOverlappingInterval noa;
	vector<vector<int>> intervals = {{1,2}, {2,3},{3,4},{1,3}};

	cout << noa.eraseOverlapIntervals(intervals) << endl;
}*/
