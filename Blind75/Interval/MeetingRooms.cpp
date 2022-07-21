#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/meeting-rooms/
 * Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.
 * Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
 */
class MeetingRooms{
public:
	//TC:O(NLOGN), SC:O(1)
    bool canAttendMeetings(vector<vector<int>>& intervals) {
    	if(intervals.empty()) return true;

    	sort(intervals.begin(), intervals.end());

    	int end = intervals[0][1];
    	for(int i = 1; i < intervals.size(); i++) {
    		if(intervals[i][0] < end)
    			return false;
    		end = intervals[i][1];
    	}
    	return true;
    }
};
/*
int main() {
	MeetingRooms mr;
	vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
	cout << mr.canAttendMeetings(intervals) << endl;
}
*/
