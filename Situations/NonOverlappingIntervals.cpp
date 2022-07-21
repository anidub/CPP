#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_set>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/non-overlapping-intervals/
 *Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

https://leetcode.com/problems/non-overlapping-intervals/discuss/1157602/Easy-C%2B%2B-solution-with-drawing
 */
//TC: O(NLOGN) due to sort, SC : 1
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
			count++;
			left = right;
			right++;
		}
	}
	return count;
}

/*
int main() {
	vector<vector<int>> intervals = {{1,2},{1,2},{1,2}};
	cout << eraseOverlapIntervals(intervals) << endl;

	return 0;
}*/
