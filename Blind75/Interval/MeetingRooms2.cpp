#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/meeting-rooms-ii/
 *Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.
 *Given Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
 */
class MeetingRooms2 {
public:
	 int minMeetingRooms(vector<vector<int>>& intervals) {
		 if(intervals.empty()) return 0;

		 map<int, int> changes; //keeps in sorted format!!
		 for(auto &interval : intervals) {
			 changes[interval[0]]++;
			 changes[interval[1]]--;
		 }

		 int cur = 0, res = 0;
		 for(auto entry : changes) {
			 cur += entry.second;
			 res = max(cur, res);
		 }
		 return res;
	 }
};

/*
int main() {
	MeetingRooms2 mr;
	vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
	cout << mr.minMeetingRooms(intervals) << endl;

	return 0;
}
*/
