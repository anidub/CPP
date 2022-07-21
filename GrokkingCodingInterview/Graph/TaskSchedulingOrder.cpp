#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/BnnArPGKolJ
 *There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’. Each task can have some prerequisite tasks which need to be completed
 *There  before it can be scheduled. Given the number of tasks and a list of prerequisite pairs,
 *There  write a method to find the ordering of tasks we should pick to finish all tasks.
 */
class TaskSchedulingOrder {
public:
	//TC: O(V + E), SC: O(V + E)
	vector<int> findOrder(int tasks, const vector<vector<int>>& prerequisites) {
		vector<int> sortedOrder;
		if(tasks <= 0) return sortedOrder;

		unordered_map<int, int> inDegree;
		unordered_map<int, vector<int>> graph;

		for(int i = 0; i < tasks; i++) {
			inDegree[i] = 0;
			graph[i] = vector<int>();
		}

		for(int i = 0; i < prerequisites.size(); i++) {
			int parent = prerequisites[i][0], child = prerequisites[i][1];
			graph[parent].push_back(child);
			inDegree[child]++;
		}

		queue<int> sources;
		for(auto entry : inDegree) {
			if(entry.second == 0)
				sources.push(entry.first);
		}

		while(!sources.empty()) {
			int vertex = sources.front(); sources.pop();
			sortedOrder.push_back(vertex);
			vector<int> children = graph[vertex];
			for(auto child : children) {
				inDegree[child]--;
				if(inDegree[child] == 0)
					sources.push(child);
			}
		}

		if(sortedOrder.size() != tasks)
			return vector<int>();

		return sortedOrder;
	}

};

/*
int main(int argc, char* argv[]) {
	TaskSchedulingOrder tso;
  vector<int> result =
		  tso.findOrder(3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = tso.findOrder(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{2, 0}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = tso.findOrder(
      6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5}, vector<int>{0, 4},
                             vector<int>{1, 4}, vector<int>{3, 2}, vector<int>{1, 3}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
*/
