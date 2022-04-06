#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/clone-graph/
 * Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
https://leetcode.com/problems/clone-graph/discuss/42313/C%2B%2B-BFSDFS

 */
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node*, Node*> copies;
//TC: O(N + M), SC : O(N). N : number of nodes, M : number of edges
Node *cloneGraph(Node *node) {
	if(!node) return nullptr;

	Node *copy = new Node(node->val, {});
	copies[node] = copy;

	queue<Node*> todo;
	todo.push(node);

	while(!todo.empty()) {
		Node *cur = todo.front(); todo.pop();
		for(Node* neighbor : cur->neighbors){
			if(copies.find(neighbor) == copies.end()) {
				copies[neighbor] = new Node(neighbor->val, {});
				todo.push(neighbor);
			}
			copies[cur] -> neighbors.push_back(copies[neighbor]);
		}
	}
	return copy;
}
/*
int main() {

	return 0;
}*/
