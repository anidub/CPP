#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/tree-diameter/
 * The diameter of a tree is the number of edges in the longest path in that tree.

There is an undirected tree of n nodes labeled from 0 to n - 1. You are given a 2D array edges where edges.length == n - 1 and edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the tree.

Return the diameter of the tree.

Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
Output: 4
Explanation: The longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
https://leetcode.com/problems/tree-diameter/discuss/420452/C%2B%2B-with-picture-O(n)
Start from 0 node.
For every unvisited sibling, run DFS to get the depth of that route.
- Track the maximum of any two depth in the global diameter variable.
- Track the maximum depth among all directions, and return it.
The picture below shows depth returned from running DFS on each node, with two maximums in green.
 */

int treeDiameterDFS(vector<vector<int>> &nodes, int &diameter, vector<bool> &visited, int i) ;

//TC: O(N), SC:O(N) due to stack size
int treeDiameter(vector<vector<int>>& edges) {
	if(edges.empty()) return 0;
	int diameter = 0;

	vector<bool> visited(edges.size() + 1);
	vector<vector<int>> nodes(edges.size() + 1);

	for(auto &e : edges) {
		nodes[e[0]].push_back(e[1]);
		nodes[e[1]].push_back(e[0]);
	}
	return treeDiameterDFS(nodes, diameter, visited, 0);
}

int treeDiameterDFS(vector<vector<int>> &nodes, int &diameter, vector<bool> &visited, int i) {
	visited[i] = true;
	int max_depth = 0;

	for(auto j : nodes[i]) {
		if(!visited[j]) {
			int depth = treeDiameterDFS(nodes, diameter, visited, j);
			diameter = max(diameter, depth + max_depth);
			max_depth = max(max_depth, depth);
		}
	}
	return i == 0 ? diameter : max_depth + 1;
}
/*
int main() {
	vector<vector<int>> edges = {{0,1},{0,2}};
	cout << treeDiameter(edges) << endl;
	return 0;
}*/

