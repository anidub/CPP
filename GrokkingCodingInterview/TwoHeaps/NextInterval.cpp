#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <map>
#include <queue>
#include <utility>

using namespace std;
/*Next Interval (hard)#
Given an array of intervals, find the next interval of each interval. In a list of intervals, for an interval ‘i’ its next interval ‘j’ will have the smallest ‘start’ greater than or equal to the ‘end’ of ‘i’.

Write a function to return an array containing indices of the next interval of each input interval. If there is no next interval of a given interval, return -1. It is given that none of the intervals have the same start point.
 *Input: Intervals [[2,3], [3,4], [5,6]]
Output: [1, 2, -1]
Explanation: The next interval of [2,3] is [3,4] having index ‘1’. Similarly, the next interval of [3,4] is [5,6] having index ‘2’. There is no next interval for [5,6] hence we have ‘-1’.
https://leetcode.com/problems/find-right-interval/
https://leetcode.com/problems/find-right-interval/discuss/91819/C%2B%2B-map-solution
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

class NextInterval {
 public:
	//TC:O(NLOGN), SC:O(N)
  vector<int> findNextInterval(const vector<Interval> &intervals) {
    int n = intervals.size();
    vector<int> result;
    map<int, int> mp;
    for(int i = 0; i < n; i++)
      mp[intervals[i].start] = i;

    for(auto intr : intervals) {
      auto itr = mp.lower_bound(intr.end);
      if(itr == mp.end()) result.push_back(-1);
      else result.push_back(itr->second);
    }
    return result;
  }
};

/*
int main(int argc, char *argv[]) {
  vector<Interval> intervals = {{2, 3}, {3, 4}, {5, 6}};
  NextInterval ni;
  vector<int> result = ni.findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
  cout << endl;

  intervals = {{3, 4}, {1, 5}, {4, 6}};
  result = ni.findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
} */
