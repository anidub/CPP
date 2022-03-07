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

void reverseOrderPrint(BNode* root);

void reverseOrderPrint(BNode* root) {
	if(root->left == NULL && root->right == NULL) {
		cout << root->data  << " ";
		return;
	}
	reverseOrderPrint(root->right);
	cout << root->data << " ";
	reverseOrderPrint(root->left);
}
/*
int main() {
	BNode* root = new BNode(15);
	root->left = new BNode(10);
	root->right = new BNode(20);
	root->right->left = new BNode(16);
	root->right->right = new BNode(25);

	reverseOrderPrint(root);
	delete root;
	return 0;
}*/
