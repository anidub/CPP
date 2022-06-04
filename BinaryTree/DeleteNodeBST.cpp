#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/delete-node-in-a-bst/
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

In the above recursive code, we recursively call delete() for the successor. We can avoid recursive calls by keeping track of the parent node of the successor so that we can simply remove the successor
 by making the child of a parent NULL. We know that the successor would always be a leaf node.

 Iterative:https://leetcode.com/problems/delete-node-in-a-bst/discuss/1061984/C%2B%2B-iterative-solution

 https://leetcode.com/problems/delete-node-in-a-bst/solution/ : USED
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
//Time Complexity: The worst case time complexity of delete operation is O(h) where h is the height of the Binary Search Tree.
//In worst case, we may have to travel from the root to the deepest leaf node.
// The height of a skewed tree may become n and the time complexity of delete operation may become O(n)
BNode* deleteNodeBST(BNode* root, int key) {
	if(!root) return NULL;

	if(key < root->data) {
		root->left = deleteNodeBST(root->left, key);
		return root;
	} else if(key > root->data) {
		root->right = deleteNodeBST(root->right, key);
	} else {
		if(root->right == NULL) {
			BNode* left = root->left;
			delete root;
			return left;
		} else if(root->left == NULL) {
			BNode* right = root->right;
			delete root;
			return right;
		} else {
			BNode* pSucc = root;
			BNode* succ = root->right;
			while(succ->left != NULL) {
				pSucc = succ;
				succ = succ->left;
			}

			if(pSucc != root) {
				pSucc->left = succ->right;
			} else
				pSucc->right = succ->right;

			root->data = succ->data;
			delete succ;
			return root;
		}
	}
}

int successor(BNode* root) {
	root = root->right;
	while(root->left != nullptr)
		root = root->left;
	return root->data;
}

int predecessor(BNode* root) {
	root = root->left;
	while(root->right != nullptr)
		root = root->right;
	return root->data;
}
//USED
//TC: O(LOGN), SC:O(H) to keep recursion stack
BNode* deleteNodeInBST(BNode* root, int key) {
	if(root == nullptr) return root;
	if(key < root->data)
		root->left = deleteNodeBST(root->left, key);
	else if(key > root->data)
		root->right = deleteNodeBST(root->right, key);
	else{
		if(root->left == nullptr && root->right == nullptr) root = nullptr;
		else if(root->right != nullptr) {
			root->data = successor(root);
			root->right = deleteNodeInBST(root->right, root->data);
		} else {
			root->data = predecessor(root);
			root->left = deleteNodeInBST(root->left, root->data);
		}
	}
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
    root->right = new BNode(22);
    root->right->right = new BNode(25);
    deleteNodeBST(root, 12);
    delete root;

	return 0;
}*/
