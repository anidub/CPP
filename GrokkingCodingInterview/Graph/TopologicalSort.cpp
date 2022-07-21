#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/m25rBmwLV00
 * Topological Sort of a directed graph (a graph with unidirectional edges) is
 *  a linear ordering of its vertices such that for every directed edge (U, V) from vertex U to vertex V, U comes before V in the ordering.

Given a directed graph, find the topological ordering of its vertices.
Input: Vertices=4, Edges=[3, 2], [3, 0], [2, 0], [2, 1]
Output: Following are the two valid topological sorts for the given graph:
1) 3, 2, 0, 1
2) 3, 2, 1, 0

https://www.youtube.com/watch?v=ddTC4Zovtbc : what is topological sort


SAME PROBLEM FOR DETECT CYCLE IN DAG
 */
class TopologicalSort {
public:
	//TC: O(V + E), SC: O(V + E)
	vector<int> topologicalSort(int vertices, const vector<vector<int>>& edges) {
		vector<int> sortedOrder;
		if(vertices <= 0) return sortedOrder;

		unordered_map<int, int> inDegree;
		unordered_map<int, vector<int>> graph;

		for(int i = 0; i < vertices; i++){
			inDegree[i] = 0;
			graph[i] = vector<int>();
		}

		for(int i = 0; i < edges.size(); i++) {
			int parent = edges[i][0], child = edges[i][1];
			inDegree[child]++;
			graph[parent].push_back(child);
		}

		queue<int> sources;
		for(auto entry : inDegree) {
			if(entry.second == 0)
				sources.push(entry.first);
		}

		while(!sources.empty()) {
			int vertex = sources.front();
			sources.pop();
			sortedOrder.push_back(vertex);
			vector<int> children = graph[vertex];
			for(auto child : children) {
				inDegree[child]--;
				if(inDegree[child] == 0) {
					sources.push(child);
				}
			}
		}
		if(sortedOrder.size() != vertices) //SAME PROBLEM FOR DETECT CYCLE IN DAG
			return vector<int>();

		return sortedOrder;
	}
};

/*
int main(int argc, char* argv[]) {
	TopologicalSort ts;
  vector<int> result =
		  ts.topologicalSort(4, vector<vector<int>>{vector<int>{3, 2}, vector<int>{3, 0},
                                                   vector<int>{2, 0}, vector<int>{2, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = ts.topologicalSort(
      5, vector<vector<int>>{vector<int>{4, 2}, vector<int>{4, 3}, vector<int>{2, 0},
                             vector<int>{2, 1}, vector<int>{3, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = ts.topologicalSort(
      7, vector<vector<int>>{vector<int>{6, 4}, vector<int>{6, 2}, vector<int>{5, 3},
                             vector<int>{5, 4}, vector<int>{3, 0}, vector<int>{3, 1},
                             vector<int>{3, 2}, vector<int>{4, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
*/
