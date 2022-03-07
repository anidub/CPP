#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
/* change a tree so that the roles of the left
and right hand pointers are swapped at every node */

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

void swapLeftRightNodes(BNode* root) {
	if(root == NULL) return;

	swapLeftRightNodes(root->left);
	swapLeftRightNodes(root->right);

	BNode* tmp = root->right;
	root->right = root->left;
	root->left = tmp;
}
/*
int main() {
	BNode* root = new BNode(1);
    root->left = new BNode(2);
    root->right = new BNode(3);
    root->left->left = new BNode(4);
    root->left->right = new BNode(5);
    root->right->left = new BNode(6);
    root->right->right = new BNode(7);
    swapLeftRightNodes(root);
    delete root;
	return 0;
}*/
