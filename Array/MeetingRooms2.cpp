#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>

using namespace std;
/*https://leetcode.com/problems/meeting-rooms-ii/
 * Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
 https://leetcode.com/problems/meeting-rooms-ii/discuss/67996/C%2B%2B-O(n-log-n)-584%2B-ms-3-solutions

 */
//TC:O(NLOGN), space : O(N)
int minMeetingRoomsMap(vector<vector<int>> intervals) {
	if(intervals.empty()) return 0;
	map<int, int> changes;

	for(auto &interval : intervals) {
		changes[interval[0]]++;
		changes[interval[1]]--;
	}

	int cur = 0, res = 0;
	for(auto &it : changes) {
		res = max(res, cur += it.second);
	}
	return res;
}
/*
 * static bool cmpStart(Interval x, Interval y){
    return x.start < y.start;
}
int minMeetingRooms(vector<Interval>& intervals) {
    if(intervals.size() == 0) return 0;
    sort(intervals.begin(), intervals.end(), cmpStart);
    int cnt = 1;
    priority_queue<int, vector<int>, std::greater<int>> pq;
    pq.push(intervals[0].end);
    for(int i = 1; i < intervals.size(); ++i){
        if(pq.top() <= intervals[i].start)
            pq.pop();
        pq.push(intervals[i].end);
        cnt = max(cnt, (int)pq.size());
    }
    return cnt;
}
 */
/*
int main() {
	vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};

	cout << minMeetingRoomsMap(intervals) << endl;

	return 0;
}*/
