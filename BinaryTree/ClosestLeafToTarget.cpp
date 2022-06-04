#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/closest-leaf-in-a-binary-tree/
 * Given the root of a binary tree where every node has a unique value and a target integer k, return the value of the nearest leaf node to the target k in the tree.

Nearest to a leaf means the least number of edges traveled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it
 has no children.
 * https://leetcode.com/problems/closest-leaf-in-a-binary-tree/discuss/291155/Simple-C%2B%2B-recursive-beats-100-in-both-time-and-space
 */
class BNode{
public:
	int data;
	BNode *left;
	BNode *right;

	BNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

int min_Dist = INT_MAX;
int min_val;

int findNode(BNode *root, int k);
void traverseDown(BNode* root, int level);

int findClosestLeaf(BNode *root, int k) {
	findNode(root, k);
	return min_val;
}

int findNode(BNode *root, int k) {
	if(!root) return -1;

	if(root->data == k) {
		traverseDown(root, 0);
		return 0;
	}

	int left = findNode(root->left, k);
	int right = findNode(root->right, k);

	if(left != -1) {
		traverseDown(root->right, left + 2);
		return left + 1;
	}

	if(right != -1) {
		traverseDown(root->left, right + 2);
		return right + 1;
	}
	return -1;
}

void traverseDown(BNode *root, int level) {
	if(!root) return;
	if(!root->left && !root->right) {
		if(level < min_Dist) {
			min_Dist = level;
			min_val = root->data;
		}
	}
	traverseDown(root->left, level + 1);
	traverseDown(root->right, level + 1);
}

BNode* findClosestLeafGraphDFS(BNode* root, unordered_map<BNode*, BNode*> &edges, int k) {
	if(root == nullptr) return nullptr;
	if(root->data == k) return root;

	if(root->left != nullptr) {
		edges[root->left] = root;
		auto l_node = findClosestLeafGraphDFS(root->left, edges, k);
		if(l_node != nullptr) return l_node;
	}
	if(root->right != nullptr) {
		edges[root->right] = root;
		auto r_node = findClosestLeafGraphDFS(root->right, edges, k);
		if(r_node != nullptr) return r_node;
	}
	return nullptr;
}

/*Use this
 * TC:O(N), SC:O(N)
 * https://hao-fu-1.gitbook.io/oj/binary_tree_and_divide_conquer/order-traversal/742.-closest-leaf-in-a-binary-tree
 */
int findClosestLeafGraph(BNode* root, int k) {
	if(root == nullptr) return -1;
	unordered_map<BNode*, BNode*> edges;
	auto k_node = findClosestLeafGraphDFS(root, edges, k);
	if(k_node == nullptr) return -1;

	queue<BNode*> q; q.push(k_node);
	unordered_set<BNode*> visited;

	while(!q.empty()) {
		for(int i = q.size(); i >= 0; i--) {
			BNode* node = q.front(); q.pop();
			if(node->left == nullptr && node->right == nullptr) return node->data;
			if(visited.count(node)) continue;
			visited.insert(node);
			if(node->left != nullptr) q.push(node->left);
			if(node->right != nullptr) q.push(node->right);
			if(edges.count(node)) q.push(edges[node]);
		}
	}
	return -1;
}

/*
int main() {
    BNode* root = new BNode(4);
    root->left = new BNode(2);
    root->left->left = new BNode(1);
    root->left->right = new BNode(3);
    root->right = new BNode(5);

    cout << findClosestLeaf(root, 2) << endl;

    delete root;
	return 0;
} */
