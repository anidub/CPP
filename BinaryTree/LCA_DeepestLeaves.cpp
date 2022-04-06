#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

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
/*https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
 * Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
 * The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/discuss/334577/JavaC%2B%2BPython-Two-Recursive-Solution
 */
pair<BNode*, int> lcaDeepestLeavesHelper(BNode* root);
//TC: O(N) for one pass, Space O(H) for recursion management
BNode* lcaDeepestLeaves(BNode* root) {
	if(root == nullptr) return root;
	return lcaDeepestLeavesHelper(root).first;
}

pair<BNode*, int> lcaDeepestLeavesHelper(BNode* root) {
	if(!root) return {nullptr, 0};

	auto left = lcaDeepestLeavesHelper(root->left);
	auto right = lcaDeepestLeavesHelper(root->right);

	if(left.second > right.second)
		return {left.first, left.second + 1};
	if(right.second > left.second)
		return {right.first, right.second + 1};

	return {root, left.second + 1};
}
/*
int main() {
	BNode* root = new BNode(20);
	root->left = new BNode(8);
	root->left->left = new BNode(4);
	root->left->right = new BNode(12);
	root->left->right->left = new BNode(10);
	root->left->right->right = new BNode(14);
	root->right = new BNode(22);
	lcaDeepestLeaves(root);

	delete root;

	return 0;
}*/
