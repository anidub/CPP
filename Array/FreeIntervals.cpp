#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_set>
#include <queue>

using namespace std;
/*759. Employee Free Time Problem Solving Report
 * We are given a list schedule of employees, which represents the working time for each employee.
Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.
Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.
Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite
https://www.cnblogs.com/grandyang/p/8552586.html
 */
class Interval {
public:
	int start;
	int end;
	Interval() {start = 0; end = 0;}
	Interval(int s, int e) {start = s; end = e;}
};
//o(nlogn)
vector<Interval> getEmployeeFreeTime(vector<vector<Interval>>& schedule) {
	if(schedule.empty()) return {};
	vector<Interval> result, v;

	for(auto a : schedule) {
		v.insert(v.end(), a.begin(), a.end());
	}

	sort(v.begin(), v.end(), [](Interval& a, Interval& b) {return a.start < b.start;});
	Interval t = v[0];
	for(Interval i : v) {
		if(t.end < i.start) {
			result.push_back(Interval(t.end, i.start));
			t = i;
		} else {
			t = (t.end < i.end) ? i : t;
		}
	}
	return result;
}

/*
int main() {
	Interval i1 (1,2);Interval i2 (5,6);Interval i3 (1,3);Interval i4 (4,10);
	vector<Interval> intervals; intervals.push_back(i1);intervals.push_back(i2);
	intervals.push_back(i3);intervals.push_back(i4);
	vector<vector<Interval>> employees; employees.push_back(intervals);
	vector<Interval> result = getEmployeeFreeTime(employees);
	for(auto i : result) {
		cout << i.start << "-" << i.end << endl;
	}
	return 0;
}*/
