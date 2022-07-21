#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/3jKlyNMJPEM
 *Given a list of non-overlapping intervals sorted by their start time, insert a given interval at the correct position and merge all necessary intervals to produce a list that has only mutually exclusive intervals.
 *Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,6]
Output: [[1,3], [4,7], [8,12]]
Explanation: After insertion, since [4,6] overlaps with [5,7], we merged them into one [4,7].
 */
class Interval {
public:
	int start = 0;
	int end = 0;

	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

//TC:O(N), SC: O(N)
vector<Interval> insertInterval(vector<Interval> intervals, Interval newInterval) {
	if(intervals.empty()) return {newInterval};

	vector<Interval> mergedIntervals;
	int i = 0;

	while(i < intervals.size() && intervals[i].end < newInterval.start) {
		mergedIntervals.push_back(intervals[i]);
		i++;
	}

	while(i < intervals.size() && intervals[i].start <= newInterval.end) {
		newInterval.start = min(newInterval.start, intervals[i].start);
		newInterval.end = max(newInterval.end, intervals[i].end);
		i++;
	}
	mergedIntervals.push_back(newInterval);

	while(i < intervals.size()) {
		mergedIntervals.push_back(intervals[i]);
		i++;
	}
	return mergedIntervals;
}
/*
int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {5, 7}, {8, 12}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : insertInterval(input, {4, 6})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  cout << "Intervals after inserting the new interval: ";
  for (auto interval : insertInterval(input, {4, 10})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{2, 3}, {5, 7}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : insertInterval(input, {1, 4})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}*/
