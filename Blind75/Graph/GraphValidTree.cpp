#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/graph-valid-tree/
 * You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.
Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true


To tell whether a graph is a valid tree, we have to:

Make sure there is no cycle in the graph - this has to be a none-cyclic graph;
Make sure every node is reached - this has to be a connected graph;

https://leetcode.com/problems/graph-valid-tree/discuss/69036/16-lines-C%2B%2B-DFS
https://leetcode.com/problems/graph-valid-tree/solution/
 */
class GraphValidTree {
public:
	//TC:O(N), SC:O(N) FROM SOLUTION TAB
	bool validTree(int n, vector<pair<int, int>>& edges) {
		vector<vector<int>> neighbors(n);
		for(auto e : edges) {
			neighbors[e.first].push_back(e.second);
			neighbors[e.second].push_back(e.first);
		}

		vector<bool> visited(n, false);
		if(hasCycle(neighbors, 0, -1, visited))
			return false;

		for(auto v : visited)
			if(!v) return false;

		return true;
	}

private:
	bool hasCycle(vector<vector<int>> &neighbors, int child, int parent, vector<bool> &visited) {
		if(visited[child]) return true;

		visited[child] = true;

		for(auto neighbor : neighbors[child]) {
			if(neighbor != parent && hasCycle(neighbors, neighbor, child, visited))
				return true;
		}
		return false;
	}
};
/*
int main() {
	vector<pair<int, int>> edges = { {0,1}, {0,2}, {0,3}, {1,4}};
	GraphValidTree gvt;
	cout << gvt.validTree(5, edges) << endl;
}*/
