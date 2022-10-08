#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/xVlyyv3rR93
 * Maximum CPU Load (hard)#
We are given a list of Jobs. Each job has a Start time, an End time, and a CPU load when it is running. Our goal is to find the maximum CPU load at any time if all the jobs are running on the same machine.

Example 1:

Jobs: [[1,4,3], [2,5,4], [7,9,6]]
Output: 7
Explanation: Since [1,4,3] and [2,5,4] overlap, their maximum CPU load (3+4=7) will be when both the
jobs are running at the same time i.e., during the time interval (2,4).

 */
class Job {
 public:
  int start = 0;
  int end = 0;
  int cpuLoad = 0;

  Job(int start, int end, int cpuLoad) {
    this->start = start;
    this->end = end;
    this->cpuLoad = cpuLoad;
  }
};

struct endCompare {
	bool operator()(const Job &x, const Job &y) {
		return x.end > y.end;
	}
};

static bool comparator(const Job &a, const Job &b) {
	return a.start < b.start;
}

//TC:O(NLOGN), SC: O(N)
int findMaxCPULoad(vector<Job> &jobs) {
	if(jobs.empty()) return 0;
	int maxLoad = 0;
	int curLoad = 0;

	sort(jobs.begin(), jobs.end(), comparator);//ascending order

	priority_queue<Job, vector<Job>, endCompare> minHeap;//end ascending order

	for(auto &job : jobs) {

		while(!minHeap.empty() && job.start > minHeap.top().end) {
			curLoad -= minHeap.top().cpuLoad;
			minHeap.pop();
		}

		minHeap.push(job);
		curLoad += job.cpuLoad;
		maxLoad = max(maxLoad, curLoad);
	}
	return maxLoad;

}
/*
int main() {
	  vector<Job> input = {{1, 4, 3}, {7, 9, 6}, {2, 5, 4}};
	  cout << "Maximum CPU load at any time: " << findMaxCPULoad(input) << endl;

	  input = {{6, 7, 10}, {8, 12, 15}, {2, 4, 11}};
	  cout << "Maximum CPU load at any time: " << findMaxCPULoad(input) << endl;

	  input = {{1, 4, 2}, {3, 6, 5}, {2, 4, 1}};
	  cout << "Maximum CPU load at any time: " << findMaxCPULoad(input) << endl;
}
*/
