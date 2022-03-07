#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
//https://leetcode.com/problems/inorder-successor-in-bst/discuss/72741/C%2B%2B-iterative
/* https://leetcode.com/problems/inorder-successor-in-bst/
 * Given the root of a binary search tree and a node p in it, return the in-order successor of that node in the BST. If the given node has no in-order successor in the tree, return null.
The successor of a node p is the node with the smallest key greater than p.val.
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

BNode* inorderSuccessor(BNode* root, BNode* node) {
	BNode* successor = NULL;
	if(node-> right) {
		successor = node->right;
		while(successor->left != NULL) {
			successor = successor->left;
		}
		return successor;
	}
	while(root) {
		if(node->data < root->data) {
			successor = root;
			root = root->left;
		} else if(node->data > root->data)
			root = root->right;
		else
			break;
	}
	return successor;
}
/*
int main() {
	BNode* root = new BNode(5);
	root->left = new BNode(3);
	root->right = new BNode(6);
	root->left->left = new BNode(2);
	root->left->left->left = new BNode(1);
	root->left->right = new BNode(4);

	BNode* node = new BNode(3);
	BNode* n = inorderSuccessor(root, node);
    cout << n->data << endl;

    delete root;
    delete node;
	return 0;
}
*/
