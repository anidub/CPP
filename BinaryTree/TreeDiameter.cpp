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






int treeDiameterBetterDFS(vector<vector<int>> &adjacencyList, vector<bool> &visited, int node);
int max_count;
//https://leetcode.com/problems/tree-diameter/discuss/465080/C%2B%2B%3A-DFS-O(n)-Easy-to-understand
//Soln tab used
//TC:O(N), SC:O(N)
int treeDiameterBetter(vector<vector<int>> &edges) {
	if(edges.empty()) return 0;
	max_count = 0;
	int n = edges.size();
	vector<bool> visited(n + 1, false);

	vector<vector<int>> adjacencyList(n + 1, vector<int> ());

	for(int i = 0; i < n; i++) {
		adjacencyList[edges[i][0]].push_back(edges[i][1]);
		adjacencyList[edges[i][1]].push_back(edges[i][0]);
	}

	treeDiameterBetterDFS(adjacencyList, visited, 0);
	return max_count;
}

int treeDiameterBetterDFS(vector<vector<int>> &adjacencyList, vector<bool> &visited, int node) {
	visited[node] = true;

	int first_max = 0, second_max = 0;

	for(int i : adjacencyList[node]) {
		if(visited[i]) continue;
		int len = 1 + treeDiameterBetterDFS(adjacencyList, visited, i);
		if(len > first_max) {
			second_max = first_max;
			first_max = len;
		} else if(len > second_max) {
			second_max = len;
		}
	}
	max_count = max(max_count, first_max + second_max);
	return first_max;
}
/*
int main() {
	vector<vector<int>> edges = {{0,1},{0,2}};
	cout << treeDiameter(edges) << endl;
	return 0;
}*/

