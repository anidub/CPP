#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/is-graph-bipartite/
 * There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
https://leetcode.com/problems/is-graph-bipartite/discuss/1065709/C%2B%2B-or-DFS-or-O(n)-8ms-Beats-100-or-Explanation
https://leetcode.com/problems/is-graph-bipartite/discuss/409594/Clean-C%2B%2B-BFS-with-explanation-and-comments : to understand
https://leetcode.com/problems/is-graph-bipartite/discuss/1065074/C%2B%2B-Super-Simple-Easy-BFS : used
 */
//TIME COMPLEXITY : O(N + E) N is number of nodes and E is number of edges
// SPACE COMPLEXITY: O(N)  : to store color
bool isBipartite(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<int> color(n, 0); // 0: uncolored; 1: color A; -1: color B
	queue<int> q;

	for(int i = 0; i < n; i++) {
		if(color[i]) continue;// skip already colored nodes
		color[i] = 1;  // color seed i to be A (doesn't matter A or B)
		q.push(i);// BFS with seed node i to color neighbors with opposite color

		while(!q.empty()) {
			int temp = q.front(); q.pop();
			for(auto neighbor : graph[temp]) {

				if(!color[neighbor]) {
					color[neighbor] = -color[temp];// Color neighbor with opposite color
					q.push(neighbor);
				} else if(color[neighbor] == color[temp])// If the neighbor has the same color - can't bipartite.
					return false;
			}
		}
		return true;
	}
}
/*
int main() {
	vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
	cout << isBipartite(graph) << endl;

	return 0;
}*/
