#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/diameter-of-binary-tree/
 * Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
https://leetcode.com/problems/diameter-of-binary-tree/discuss/234397/C%2B%2B-recursive-and-iterative
As this is a relatively easy recursive solution, if time allowed, the interviewer may still ask for an iterative solution
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
//TC:O(N), SC:O(N)
int diameterTreeIterative(BNode* root) {
	if(root == NULL) return 0;
	unordered_map<BNode*, int> depths;
	stack<BNode*> todo;
	todo.push(root);
	int diameter = 0;

	while(!todo.empty()) {
		BNode* node = todo.top();
		if(node->left != NULL && depths.find(node->left) == depths.end())
			todo.push(node->left);
		else if(node->right != NULL && depths.find(node->right) == depths.end())
			todo.push(node->right);
		else {
			todo.pop();
			int l = depths[node->left], r = depths[node->right];
			depths[node] = max(l, r) + 1;
			diameter = max(diameter, l+r);
		}
	}
	return diameter;
}
int diameterBinaryTreeRecursive(BNode* root);
int diameterBinaryTreeUtil(BNode* root, int& diameter);

//TC:O(N), SC:O(N)
int diameterBinaryTreeRecursive(BNode* root) {
	int diameter = 0;
	diameterBinaryTreeUtil(root, diameter);
	return diameter;
}

int diameterBinaryTreeUtil(BNode* root, int& diameter) {
	if(!root) return 0;

	int l = diameterBinaryTreeUtil(root->left, diameter);
	int r = diameterBinaryTreeUtil(root->right, diameter);
	diameter = max(diameter, l+r);
	return max(l, r) + 1;
}
/*
int main() {
	BNode* root = new BNode(20);
	root->left = new BNode(8);
	root->left->left = new BNode(4);
	root->left->right = new BNode(12);
	root->left->right->left = new BNode(10);
	root->left->right->right = new BNode(14);
	cout << diameterTreeIterative(root) << endl;
	cout << diameterBinaryTreeRecursive(root) << endl;

	delete root;
	return 0;
}*/

