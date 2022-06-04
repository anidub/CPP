#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>

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

void reverseInOrderPrint(BNode* root);// right parent left

void reverseInOrderPrint(BNode* root) {// right parent left
	if(root->left == NULL && root->right == NULL) {
		cout << root->data  << " ";
		return;
	}
	reverseInOrderPrint(root->right);
	cout << root->data << " ";
	reverseInOrderPrint(root->left);
}
/*
int main() {
	BNode* root = new BNode(15);
	root->left = new BNode(10);
	root->right = new BNode(20);
	root->right->left = new BNode(16);
	root->right->right = new BNode(25);

	reverseInOrderPrint(root);
	delete root;
	return 0;
}*/
