#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/clone-graph/
 * Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
https://leetcode.com/problems/clone-graph/solution/
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

class CloneGraph {
public:
	//TC:O(N + M), SC:O(N)
	Node* cloneGraph(Node* node) {
		if(node == nullptr) return node;
		Node* copy = new Node(node->val, {});
		copies[node] = copy;
		queue<Node*> todo;
		todo.push(node);

		while(!todo.empty()) {
			Node* cur = todo.front();
			todo.pop();

			for(Node* neighbor : cur->neighbors) {
				if(copies.find(neighbor) == copies.end()) {
					copies[neighbor] = new Node(neighbor->val, {});// Clone the neighbor and put in the visited, if not present already
					todo.push(neighbor);// Add the newly encountered node to the queue.
				}
				copies[cur]->neighbors.push_back(copies[neighbor]); // Add the clone of the neighbor to the neighbors of the clone node "n".
			}
		}
		return copy;
	}

private:
	unordered_map<Node*, Node*> copies;
};

/*
int main() {
	CloneGraph cg;
}*/
