#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;

/*https://www.techiedelight.com/find-inorder-predecessor-given-key-bst/
 * Given a BST, find the inorder predecessor of a given key in it.
 * If the key does not lie in the BST, return the previous greater node (if any) present in the BST.
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

BNode* findMaximumBST(BNode* root);
BNode* findPredecessor(BNode* root, BNode* pred, int key);
BNode* findPredecessorIterative(BNode* root, int key);

BNode* findPredecessor(BNode* root, BNode* pred, int key) {
	if(root == NULL) return pred;

	 // if a node with the desired value is found, the predecessor is the maximum value node in its left subtree (if any)
	if(key == root->data) {
		if(root->left != NULL)
			return findMaximumBST(root->left);
		// if the given key is less than the root node, recur for the left subtree
	} else if(key < root->data) {
		return findPredecessor(root->left, pred, key);
		// if the given key is more than the root node, recur for the right subtree
	} else {
		// update predecessor to the current node before recursing in the right subtree
		pred = root;
		return findPredecessor(root->right, pred, key);
	}
	return pred;
}

BNode* findMaximumBST(BNode* root) {
	while(root->right) {
		root = root->right;
	}
	return root;
}


BNode* findPredecessorIterative(BNode* root, int key) {
	if(root == NULL) return NULL;
	BNode* pred = NULL;

	while(true) {
		 // if the given key is less than the root node, visit the left subtree
		if(root->data < key) {
			root = root->left;

			// if the given key is more than the root node, visit the right subtree
		} else if(key > root->data) {
			pred = root;
			root = root->right;
		 // if a node with the desired value is found, the predecessor is the maximum value node in its left subtree (if any)
		} else {
			if(root->left) {
				pred = findMaximumBST(root->left);
			}
			break;
		}
		 // if the key doesn't exist in the binary tree, return previous greater node
		if(!root) return pred;
	}
	return pred;
}
/*
int main() {
	BNode* root = new BNode(15);
	root->left = new BNode(10);
	root->right = new BNode(20);
	root->right->left = new BNode(16);
	root->right->right = new BNode(25);
	int key = 15;
	BNode* pred = NULL;
	BNode* n = findPredecessor(root, pred, key);
	BNode* n1 = findPredecessorIterative(root, key);
	cout << n1->data;

	delete root;
	delete pred;
	delete n1;
	return 0;
}*/
