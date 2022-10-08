#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/q2YmVjQMMr3
 * There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’. Each task can have some prerequisite tasks which need to be completed
 *  before it can be scheduled. Given the number of tasks and a list
 *  of prerequisite pairs, write a method to print all possible ordering of tasks meeting all prerequisites.
 *  Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
Output: [0, 1, 2]
Explanation: There is only possible ordering of the tasks.

Input: Tasks=4, Prerequisites=[3, 2], [3, 0], [2, 0], [2, 1]
Output:
1) [3, 2, 0, 1]
2) [3, 2, 1, 0]
Explanation: There are two possible orderings of the tasks meeting all prerequisites.
 */
class AllTasksSchedulingOrder {
public:
	//TC: O(V! + E), SC:O(V! + E)where ‘V’ is the total number of tasks and ‘E’ is the total prerequisites.
	//We need the ‘E’ part because in each recursive call, at max, we remove (and add back) all the edges.
	void printOrders(int tasks, vector<vector<int>> &prerequisites) {
		if(tasks <= 0) return;
	/*	vector<int> sortedOrder;

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

		vector<int> sources;
		for(auto entry : inDegree) {
			if(entry.second == 0)
				sources.push_back(entry.first);
		}

		printAllTopoligicalSortBacktrack(inDegree, graph, sources, sortedOrder); */
		vector<int> sortedOrder;
		unordered_map<int, int> indegree;
		unordered_map<int, vector<int>> graph;

		for(int i = 0; i < tasks; i++) {
			indegree[i] = 0;
			graph[i] = vector<int>();
		}

		for(int i = 0; i < prerequisites.size(); i++) {
			int parent = prerequisites[i][0], child = prerequisites[i][1];
			graph[parent].push_back(child);
			indegree[child]++;
		}

		vector<int> sources;
		for(auto entry : indegree) {
			if(entry.second == 0) sources.push_back(entry.first);
		}
		printAllTopoligicalSortBacktrack(indegree, graph, sources, sortedOrder);
	}

private:
	void printAllTopoligicalSortBacktrack(unordered_map<int, int> &inDegree, unordered_map<int, vector<int>> &graph,
			vector<int> &sources, vector<int> &sortedOrder) {
		if(! sources.empty()) {

			for(int vertex : sources) {
				sortedOrder.push_back(vertex);
				vector<int> sourcesForNextCall = sources;

				 // only remove the current source, all other sources should remain in the queue for the next call
				sourcesForNextCall.erase(find(sourcesForNextCall.begin(), sourcesForNextCall.end(), vertex));

				vector<int> children = graph[vertex];// get the node's children to decrement their in-degrees
				for(auto child : children) {
					inDegree[child]--;
					if(inDegree[child] == 0)
						sourcesForNextCall.push_back(child);// save the new source for the next call
				}

				// recursive call to print other orderings from the remaining (and new) sources
				printAllTopoligicalSortBacktrack(inDegree, graph, sourcesForNextCall, sortedOrder);

				// backtrack, remove the vertex from the sorted order and put all of its children back to consider the next source instead of the current vertex
				sortedOrder.erase(find(sortedOrder.begin(), sortedOrder.end(), vertex));
				for(auto child : children) {
					inDegree[child]++;
				}
			}
		}
		  // if sortedOrder doesn't contain all tasks, either we've a cyclic dependency between tasks, or
		    // we have not processed all the tasks in this recursive call
		if(sortedOrder.size() == inDegree.size()) {
			for(auto num : sortedOrder) {
				cout << num << " ";
			}
			cout << endl;
		}
	}
};

/*
int main(int argc, char *argv[]) {
	AllTasksSchedulingOrder atso;
  vector<vector<int>> vec = {{0, 1}, {1, 2}};
  atso.printOrders(3, vec);
  cout << endl;

  vec = {{3, 2}, {3, 0}, {2, 0}, {2, 1}};
  atso.printOrders(4, vec);
  cout << endl;

  vec = {{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1, 3}};
  atso.printOrders(6, vec);
  cout << endl;
}
*/
