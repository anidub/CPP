#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/JExVVqRAN9D
 * Given two lists of intervals, find the intersection of these two lists. Each list consists of disjoint intervals sorted on their start time.
 * Input: arr1=[[1, 3], [5, 6], [7, 9]], arr2=[[2, 3], [5, 7]]
Output: [2, 3], [5, 6], [7, 7]
Explanation: The output list contains the common intervals between the two lists.

Input: arr1=[[1, 3], [5, 7], [9, 12]], arr2=[[5, 10]]
Output: [5, 7], [9, 10]
Explanation: The output list contains the common intervals between the two lists

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

//TC:O(N + M), SC:(1)
vector<Interval> mergeIntervalsIntersections(const vector<Interval> &arr1, const vector<Interval> &arr2) {
	if(arr1.empty()) return arr2;
	if(arr2.empty()) return arr1;

	int  i = 0, j = 0;
	vector<Interval> result;

	while(i < arr1.size() && j < arr2.size()) {
		if( (arr1[i].start >= arr2[j].start && arr1[i].start <= arr2[j].end) ||
				(arr2[j].start >= arr1[i].start && arr2[j].start <= arr1[i].end) ) {
			result.push_back( { min(arr1[i].start, arr2[j].start), max(arr1[i].end, arr2[j].end)  } );
		}
		if(arr1[i].end < arr2[j].end)
			i++;
		else
			j++;
	}
	return result;
}
/*
int main(int argc, char *argv[]) {
  vector<Interval> input1 = {{1, 3}, {5, 6}, {7, 9}};
  vector<Interval> input2 = {{2, 3}, {5, 7}};
  vector<Interval> result = mergeIntervalsIntersections(input1, input2);
  cout << "Intervals Intersection: ";
  for (auto interval : result) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input1 = {{1, 3}, {5, 7}, {9, 12}};
  input2 = {{5, 10}};
  result = mergeIntervalsIntersections(input1, input2);
  cout << "Intervals Intersection: ";
  for (auto interval : result) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }

}
*/
