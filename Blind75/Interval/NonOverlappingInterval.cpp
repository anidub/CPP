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
https://leetcode.com/problems/non-overlapping-intervals/discuss/1157602/Easy-C%2B%2B-solution-with-drawing
// Case 1:-
// ------------------   -----------------
// |   Interval 1   |   |   Interval 2  |
// ------------------   -----------------

//Case 2:-
// ------------------
// |   Interval 1   |
// ------------------
//            ------------------
//            |    Interval 2  |
//            ------------------

//Case 3:-
//  --------------------
//  |    Interval 1    |
//  --------------------
//     --------------
//     | Interval 2 |
//
 */
class NonOverlappingInterval {
public:
	//TC:O(N), SC:O(1)
	int eraseOverlapIntervals(vector<vector<int>>& v) {
		if(v.empty()) return 0;
		sort(v.begin(), v.end());

		int count = 0, left = 0, right = 1, n = v.size();//move left = right only when no overlap or full overlap not for partial overlap

		while(right < n) {
			if(v[left][1] <= v[right][0]) {//prev end is before cur start
				left = right;
				right++;
			} else if(v[left][1] <= v[right][1]) {// prev end is before or equal cur end
				count++;
				right++;
			} else if(v[left][1] > v[right][1]) {//prev end is after cur start
				left = right;
				count++;
				right++;
			}
		}
		return count;
	}

	//https://leetcode.com/problems/non-overlapping-intervals/discuss/792726/C%2B%2B-Simple-O(NlogN)-solution-with-explanation
	bool comp(vector<int> &a,vector<int> &b) {
		return a[1]<b[1];
	}
	int eraseOverlapIntervalsOther(vector<vector<int>>& intervals) {
		int ans=-1;
		if(intervals.size()==0) return 0;
		sort(intervals.begin(),intervals.end(),comp);      //custom comperator is used.
		vector<int> prev= intervals[0];

		for(vector<int> i: intervals) {
			if(prev[1]>i[0]) {
				ans++;                //we dont update previous, because i[1] will be grater then prev[1]
			}else prev=i;           // we want the end point to be minimum
		}
		return ans;                 //ans was initially made -1 because our prev and intervals[0] will always match
	}
};
/*
int main() {
	NonOverlappingInterval noa;
	vector<vector<int>> intervals = {{1,2}, {2,3},{3,4},{1,3}};

	cout << noa.eraseOverlapIntervals(intervals) << endl;
}*/
