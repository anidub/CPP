#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/evaluate-division/
 * You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation:
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

https://www.youtube.com/watch?v=UcDZM6Ap5P4 : to understand

https://leetcode.com/problems/evaluate-division/discuss/88310/C%2B%2B-0ms-23-lines-DFS-solution-with-comments
//Time Complexity: O(M.N)
 //Space Complexity : O(N)
 */

double calcEquationsDFS(unordered_map<string, unordered_map<string, double>> &graph, string a, string &b, unordered_set<string> &visited);
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
	vector<double> result;
	unordered_map<string, unordered_map<string, double>> graph;

	for(int i = 0; i < equations.size(); i++) {
		string a = equations[i][0], b = equations[i][1];
		double val = values[i];
		graph[a][b] = val;
		graph[b][a] = (double) 1 / val;
	}

	for(int i = 0; i < queries.size(); i++) {
		unordered_set<string> visited;
		double val = calcEquationsDFS(graph, queries[i][0], queries[i][1], visited);
		if(!val)
			result.push_back((double) -1.0);
		else
			result.push_back(val);
	}
	return result;
}

double calcEquationsDFS(unordered_map<string, unordered_map<string, double>> &graph, string a, string &b, unordered_set<string> &visited) {
	if(graph[a].find(b) != graph[a].end())
		return graph[a][b];

	for(auto v : graph[a]) {
		if(visited.find(v.first) == visited.end()) {
			visited.insert(v.first);
			double dist = calcEquationsDFS(graph, v.first, b, visited);
			if(dist) {
				graph[a][b] = v.second * dist;
				return graph[a][b];
			}
		}
	}
	return 0;
}
/*
int main() {
	vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
	vector<double> values = {2.0, 3.0};
	vector<vector<string>> queries = {{"a","c"}, {"b","a"}, {"a","e"}, {"a","a"}, {"x","x"}};

	calcEquation(equations, values, queries);
	return 0;
}
*/
