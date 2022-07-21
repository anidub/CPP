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
/*https://leetcode.com/problems/employee-free-time/
 * We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).  Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.
Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation: There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.

https://leetcode.com/problems/employee-free-time/discuss/1316550/C%2B%2B-O(N-log-K)-with-priority-queue-O(K)-is-memory-better-than-fastest-submitted-solutions

For merging K sorted interval to get a sorted interval, you need to do just O(N logK) work, and with priority queue, you can do it with O(K) space, as here you actually don't need to store the sorted intervals.
 */
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
//TC: O(N log K), SC: O(K)
vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
	vector<Interval> ans;
	if(schedule.empty()) return ans;

	using PQ_Node = pair<int, pair<int, int>>;
	priority_queue<PQ_Node, vector<PQ_Node>, greater<>> pq; //greater means smallest on top

	for(int i = 0; i < schedule.size(); i++) {
		if(schedule[i].size())
			pq.push({schedule[i][0].start , {i, 0}});
	}

	int end = schedule[pq.top().second.first][0].end;

	while(!pq.empty()) {
		auto p = pq.top(); pq.pop();
		int intervalIndex = p.second.second;
		int employeeIndex = p.second.first;

		if(p.first > end) {
			ans.push_back(Interval{end, p.first});
			end = schedule[employeeIndex][intervalIndex].end;
		} else {
			end = max(end, schedule[employeeIndex][intervalIndex].end);
		}
		intervalIndex++;
		if(intervalIndex < schedule[employeeIndex].size()) {
			pq.push({schedule[employeeIndex][intervalIndex].start , {employeeIndex, intervalIndex}});
		}
	}
	return ans;
}
/*
int main() {
	Interval i1(1,2);Interval i2(5,6);Interval i3(1,3);Interval i4(4,10);
	vector<Interval> sch; sch.push_back(i1);sch.push_back(i2);sch.push_back(i3);sch.push_back(i4);
	vector<vector<Interval>> schedule; schedule.push_back(sch);

	employeeFreeTime(schedule);
	return 0;
}*/
