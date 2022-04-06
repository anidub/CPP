#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
 * Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

 Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.

https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/discuss/146808/C%2B%2BJavaPython-One-Pass : DFS
https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/discuss/146765/C%2B%2B-Simple-O(n)-Solution-with-BFS%2BLCA-with-thought-process-explained : BFS
 *
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

pair<int, BNode*> subtreeDeepestNodesDFS(BNode* root);
//TC: O(N), SC: O(N)
BNode* subtreeDeepestNodes(BNode* root) {
	if(!root) return nullptr;

	return subtreeDeepestNodesDFS(root).second;
}

pair<int, BNode*> subtreeDeepestNodesDFS(BNode* root) {
	if(!root) return {0, nullptr};

	pair<int, BNode*> left = subtreeDeepestNodesDFS(root->left), right = subtreeDeepestNodesDFS(root->right);

	int d1 = left.first, d2 = right.first;

	int depth = max(d1, d2) + 1;

	return {depth, d1 == d2 ? root : d1 > d2 ? left.second : right.second};
}


BNode* findLCA(BNode* root, BNode* p, BNode* q);
/*Find all deepest nodes by traversing the tree using BFS. The required node is nothing but the LCA of all the deepest nodes.
Finding LCA of all nodes at the same level is equivalent to finding LCA of the leftMost and rightMost node. Keep track of leftMost and rightMost nodes while doing BFS and finally return their LCA.
 */
//TC: O(N), LC: O(N)
BNode* subtreeDeepestNodesBFS(BNode* root) {
	if(!root || !root->left && !root->right) return root;
	BNode* leftMost = nullptr;
	BNode* rightMost = nullptr;

	queue<BNode*> q;
	q.push(root);

	while(!q.empty()) {
		int levelSize = q.size();
		for(int level = 0; level < levelSize; level++) {
			BNode* node = q.front(); q.pop();
			if(level == 0) leftMost = node;
			if(level == levelSize - 1) rightMost = node;

			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
	}
	return findLCA(root, leftMost, rightMost);
}

BNode* findLCA(BNode* root, BNode* p, BNode* q) {
	if(!root || root == p || root == q) return root;
	BNode* left = findLCA(root->left, p, q);
	BNode* right = findLCA(root->right, p, q);

	return !left ? right : !right ? left : root;
}

/*
int main() {
	BNode* root = new BNode(15);
	root->left = new BNode(10);
	root->right = new BNode(20);
	root->right->left = new BNode(16);
	root->right->right = new BNode(25);

	subtreeDeepestNodes(root);
	delete root;
	return 0;
}*/
