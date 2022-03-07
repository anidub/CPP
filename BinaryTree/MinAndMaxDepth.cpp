#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>

using namespace std;
// Get min amd max height of binary tree. Ask for clarification and examples like when just root node, or one child then height 1 or 2 ?
//https://www.educative.io/edpresso/finding-the-maximum-depth-of-a-binary-tree
//https://www.bogotobogo.com/cplusplus/files/BinaryTree.cpp
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

int getMaxDepth(BNode *root) {
	if(root == NULL)
		return 0;
	int leftDepth = getMaxDepth(root->left);
	int rightDepth = getMaxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int getMinDepth(BNode *root) {
	if(root == NULL)
		return 0;
	int leftDepth = getMinDepth(root->left);
	int rightDepth = getMinDepth(root->right);

	return leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1;
}

/*
int main() {
	BNode* root = new BNode(1);
	root->left = new BNode(2);
	root->right = new BNode(3);
	root->left->left = new BNode(4);
	root->right->left = new BNode(5);
	root->right->right = new BNode(6);
	root->right->right->left = new BNode(8);
	root->right->left->right = new BNode(7);

    cout << getMaxDepth(root) << endl;
    cout << getMinDepth(root) << endl;

    delete root;
	return 0;
}*/
