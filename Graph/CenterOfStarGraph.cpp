#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/find-center-of-star-graph/
 * There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.
Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
https://leetcode.com/problems/find-center-of-star-graph/discuss/1108345/JavaC%2B%2BPython-Different-Ideas-1-line
 */
//Time O(1) Space O(1)
int findCenterStarGraph(vector<vector<int>> &e) {
	return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
}
/*
int main() {
	vector<vector<int>> e = {{1,2}, {2,3}, {4,2}};
	cout << findCenterStarGraph(e) << endl;

	return 0;
}*/
