#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
 *You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that
 *You there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2

https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/solution/
 */
class NumberConnectedComponents {
public:
	//TC:O(V + E), SC:O(E + V) E : number of edges, v : number of vertices
     int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for(int i = 0; i < n; i++)
        	graph[i] = vector<int>();

        for(auto e : edges) {//both since given undirected in question
        	graph[e[0]].push_back(e[1]);
        	graph[e[1]].push_back(e[0]);
        }

        int components = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++) {
        	if(visited[i] == 0) {
        		components++;
        		dfs(i, graph, visited);
        	}
        }
        return components;
    }

private:
    void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited){
    	if(visited[u]) return;

    	visited[u] = true;

    	for(int v : graph[u]) {
    		dfs(v, graph, visited);
    	}
    }
};
/*
int main() {
	vector<vector<int>> edges = {{0,1}, {1,2}, {3,4}};
	NumberConnectedComponents ns;
	cout << ns.countComponents(5, edges) << endl;
}
*/
