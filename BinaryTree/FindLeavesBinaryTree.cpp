#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/find-leaves-of-binary-tree/
 * Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.
Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level
it does not matter the order on which elements are returned.
https://leetcode.com/problems/find-leaves-of-binary-tree/discuss/660947/C%2B%2B-or-Easy-solution
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

 vector<vector<int>> res;

BNode* findLeavesBinaryTreeUtil(BNode* root, vector<int>& v);
vector<vector<int>> findLeavesBinaryTree(BNode* root);

vector<vector<int>> findLeavesBinaryTree(BNode* root) {
	if(root == NULL) return {};
	while(root != NULL) {
		vector<int> v;
		root = findLeavesBinaryTreeUtil(root, v);
		res.push_back(v);
	}
	return res;
}

BNode* findLeavesBinaryTreeUtil(BNode* root, vector<int>& v) {
	if(root == NULL) return NULL;
	if(root->left == NULL && root->right == NULL) {
		v.push_back(root->data);
		return NULL;
	}
	root->left = findLeavesBinaryTreeUtil(root->left, v);
	root->right = findLeavesBinaryTreeUtil(root->right, v);
	return root;
}
/*
int main() {
	BNode* root = new BNode(20);
	root->left = new BNode(8);
	root->left->left = new BNode(4);
	root->left->right = new BNode(12);
	root->left->right->left = new BNode(10);
	root->left->right->right = new BNode(14);
	delete root;

	return 0;
}*/
