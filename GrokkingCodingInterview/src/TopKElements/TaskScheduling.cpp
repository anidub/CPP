#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/JYB20zgR32o
 * You are given a list of tasks that need to be run, in any order, on a server.
 * Each task will take one CPU interval to execute but once a task has finished, it has a cooling period
 * during which it can’t be run again
 If the cooling period for all tasks is ‘K’ intervals, find the minimum number of CPU intervals that the server needs to finish all tasks.

If at any time the server can’t execute any task then it must stay idle.
https://www.youtube.com/watch?v=tGw5GbDekTU : USED
https://leetcode.com/problems/task-scheduler/
 */
class TaskScheduler {
public:
	//TC:O(NLOGN) SC:O(N)
	int scheduleTasks(vector<char> &tasks, int n) {
		if(tasks.empty()) return 0;
		unordered_map<char, int> count;
		for(char t : tasks)
			count[t]++;

		priority_queue<int> maxHeap;
		int result = 0;

		for(auto entry : count)
			maxHeap.push(entry.second);

		while(!maxHeap.empty()) {
			int time = 0;
			vector<int> temp;
			for(int i = 0; i < n + 1; i++) {// try to execute as many as 'k+1' tasks from the max-heap
				if(!maxHeap.empty()) {
					temp.push_back(maxHeap.top() - 1);
					maxHeap.pop();
					time++;
				}
			}
			for(auto t : temp) {
				if(t)
					maxHeap.push(t);
			}
			result += maxHeap.empty() ? time : n + 1; //if queue is empty then actual tasks  that ran
		}
		return result;
	}
};
/*
int main(int argc, char *argv[]) {
	TaskScheduler ts;
  vector<char> tasks = {'a', 'a', 'a', 'b', 'c', 'c'};
  cout << "Minimum intervals needed to execute all tasks: "
       << ts.scheduleTasks(tasks, 2) << endl;

  tasks = vector<char>{'a', 'b', 'a'};
  cout << "Minimum intervals needed to execute all tasks: "
       << ts.scheduleTasks(tasks, 3) << endl;
}
*/
