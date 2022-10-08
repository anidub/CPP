#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/7nDN8y7JKVA
 * We are given an undirected graph that has characteristics of a k-ary tree.
 * In such a graph, we can choose any node as the root to make a k-ary tree. The root (or the tree)
 * with the minimum height will be called Minimum Height Tree (MHT). There can be multiple MHTs for a graph.
 * In this problem, we need to find all those roots which give us MHTs. Write a method to find all MHTs of the given graph
 *  and return a list of their roots.
 * Input: vertices: 5, Edges: [[0, 1], [1, 2], [1, 3], [2, 4]]
Output:[1, 2]
Explanation: Choosing '1' or '2' as roots give us MHTs. In the below diagram, we can see that the
height of the trees with roots '1' or '2' is three which is minimum.
 */
class MinimumHeightTrees {
public:
	//TC:O(V + E), SC:O(V + E)
	vector<int> findTrees(int nodes, vector<vector<int>>& edges) {
		vector<int> minHeightTrees;
		if(nodes <= 0) return minHeightTrees;

		if(nodes == 1) {// with only one node, since its in-degree will be 0, therefore, we need to handle it separately
			minHeightTrees.push_back(0);
			return minHeightTrees;
		}

		unordered_map<int, int> inDegree;
		unordered_map<int, vector<int>> graph;

		for(int i = 0; i < nodes; i++) {
			inDegree[i] = 0;
			graph[i] = vector<int>();
		}

		for(int i = 0; i < edges.size(); i++) {
			int n1 = edges[i][0], n2 = edges[i][1];
			// since this is an undirected graph, therefore, add a link for both the nodes
			graph[n1].push_back(n2);
			graph[n2].push_back(n1);
			 // increment the in-degrees of both the nodes
			inDegree[n1]++;
			inDegree[n2]++;
		}

	    // c. Find all leaves i.e., all nodes with only 1 in-degree
		deque<int> leaves;
		for(auto entry : inDegree) {
			if(entry.second == 1)
				leaves.push_back(entry.first);
		}
	    // d. Remove leaves level by level and subtract each leave's children's in-degrees.
		//Repeat this until we are left with 1 or 2 nodes, which will be our answer.
	    // Any node that has already been a leaf cannot be the root of a minimum height tree, because
	    // its adjacent non-leaf node will always be a better candidate.
		int totalNodes = nodes;
		while(totalNodes > 2) {// we will never have more than 2 as our answer as in even then 2 and in odd then 1//https://youtu.be/ZfzVig8UqBQ?t=593
			int leavesSize = leaves.size();
			totalNodes -= leavesSize;
			for(int i = 0; i < leavesSize; i++) {
				int vertex = leaves.front(); leaves.pop_front();
				vector<int> children = graph[vertex];
				for(auto child : children) {
					inDegree[child]--;
					if(inDegree[child] == 1)// if the child has become a leaf
						leaves.push_back(child);
				}
			}
		}
		move(begin(leaves), end(leaves), back_inserter(minHeightTrees));

		return minHeightTrees;
	 }
};

/*
int main(int argc, char* argv[]) {
	MinimumHeightTrees mht;
  	vector<vector<int>> vec = {{0, 1}, {1, 2}, {1, 3}, {2, 4}};
  vector<int> result = mht.findTrees(5, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  vec = {{0, 1}, {0, 2}, {2, 3}};
  result = mht.findTrees(4, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  vec = {{0, 1}, {1, 2}, {1, 3}};
  result = mht.findTrees(4, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
*/
