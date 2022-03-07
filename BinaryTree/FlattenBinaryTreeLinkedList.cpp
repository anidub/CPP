#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/231417/C%2B%2B-Recursive-and-Iterative
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

void flattenRecursive(BNode* root) {
	if(!root) return;

	while(root) {
		if(root->left) {
			flattenRecursive(root->left);
			BNode* right = root->right;
			root->right = root->left;
			root->left = NULL;
			while(root->right) {
				root = root->right;
			}
			root->right = right;
		}
		root = root->right;
	}
}

void flattenIterative(BNode* root) {
	if(!root) return;

	while(root) {
		if(root->left) {
			BNode* pre = root->left;
			while(pre->right) {
				pre = pre->right;
			}
			pre->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
		root = root->right;
	}
}

/*
int main () {
    BNode* root = new BNode(20);
    root->left = new BNode(8);
    root->left->left = new BNode(4);
    root->left->right = new BNode(12);
    root->left->right->left = new BNode(10);
    root->left->right->right = new BNode(14);
    root->right = new BNode(22);
    root->right->right = new BNode(25);
    flattenIterative(root);
    flattenRecursive(root);
    delete root;

	return 0;
}*/
