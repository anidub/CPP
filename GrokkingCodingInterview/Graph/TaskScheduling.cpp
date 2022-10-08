#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/gxJrM9goEMr
 *There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’. Each task can have some prerequisite tasks which need to be completed before it
 *There  can be scheduled. Given the number of tasks and a list of prerequisite pairs, find out if it is possible to schedule all the tasks.

Example 1:

Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
Output: true
Explanation: To execute task '1', task '0' needs to finish first. Similarly, task '1' needs
to finish before '2' can be scheduled. One possible scheduling of tasks is: [0, 1, 2]

Similar Problems#
Course Schedule: There are ‘N’ courses, labeled from ‘0’ to ‘N-1’. Each course can have some prerequisite courses which
need to be completed before it can be taken.
 Given the number of courses and a list of prerequisite pairs, find if it is possible for a student to take all the courses.

 SAME PROBLEM FOR DETECT CYCLE IN DAG
 */

class TaskScheduling {
public:
	//TC:O(V + E), SC:O(V + E)
	bool isSchedulingPossible(int tasks, const vector<vector<int>>& prerequisites) {
		if(tasks <= 0) return false;
		vector<int> sortedOrder; //can use just a variable instead of vector since we dont examine elements of vector anyways

		 // a. Initialize the graph
		unordered_map<int, int> inDegree;// count of incoming edges for every vertex
		unordered_map<int, vector<int>> graph;// adjacency list graph

		for(int i = 0; i < tasks; i++) {
			inDegree[i] = 0;
			graph[i] = vector<int>();
		}

		 // b. Build the graph
		for(int i = 0; i < prerequisites.size(); i++)  {
			int parent = prerequisites[i][0], child = prerequisites[i][1];
			inDegree[child]++;// increment child's inDegree
			graph[parent].push_back(child);// put the child into it's parent's list
		}

		// c. Find all sources i.e., all vertices with 0 in-degrees
		queue<int> sources;
		for(auto entry : inDegree) {
			if(entry.second == 0)
				sources.push(entry.first);
		}

	    // d. For each source, add it to the sortedOrder and subtract one from all of its children's
	    // in-degrees if a child's in-degree becomes zero, add it to the sources queue
		while(!sources.empty()) {
			int vertex = sources.front(); sources.pop();
			sortedOrder.push_back(vertex);
			vector<int> children = graph[vertex];// get the node's children to decrement their in-degrees
			for(auto child : children) {
				inDegree[child]--;
				if(inDegree[child] == 0)
					sources.push(child);
			}
		}
	    // if sortedOrder doesn't contain all tasks, there is a cyclic dependency between tasks, therefore, we will not be able to schedule all tasks
		return sortedOrder.size() == tasks;

	}
};

/*
int main(int argc, char* argv[]) {
	TaskScheduling tsch;
  bool result = tsch.isSchedulingPossible(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});
  cout << "Tasks execution possible: " << result << endl;

  result = tsch.isSchedulingPossible(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{2, 0}});
  cout << "Tasks execution possible: " << result << endl;

  result = tsch.isSchedulingPossible(
      6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5}, vector<int>{0, 4},
                             vector<int>{1, 4}, vector<int>{3, 2}, vector<int>{1, 3}});
  cout << "Tasks execution possible: " << result << endl;
}
*/
