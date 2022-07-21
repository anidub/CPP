#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;

class Interval{
public:
	int start;
	int end;

	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};
/*
 * https://www.educative.io/courses/grokking-the-coding-interview/qVV79nGVgAG
 * Given an array of intervals representing ‘N’ appointments, find out if a person can attend all the appointments.
 * Appointments: [[1,4], [2,5], [7,9]]
Output: false
Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.
 */
static bool comparator(Interval i1, Interval i2) {
	return i1.start < i2.start;
}
//TC:O(N), SC:O(1)
bool canAttendAllAppointments(vector<Interval> intervals) {
	if(intervals.empty()) return true;

	sort(intervals.begin(), intervals.end(), comparator);

	for(int i = 1; i < intervals.size(); i++) {
		if(intervals[i].start < intervals[i-1].end)
			return false;
	}
	return true;
}
/*
int main() {
	  vector<Interval> intervals = {{1, 4}, {2, 5}, {7, 9}};
	  bool result = canAttendAllAppointments(intervals);
	  cout << "Can attend all appointments: " << result << endl;

	  intervals = {{6, 7}, {2, 4}, {8, 12}};
	  result = canAttendAllAppointments(intervals);
	  cout << "Can attend all appointments: " << result << endl;

	  intervals = {{4, 5}, {2, 3}, {3, 6}};
	  result = canAttendAllAppointments(intervals);
	  cout << "Can attend all appointments: " << result << endl;

	return 0;
}*/
