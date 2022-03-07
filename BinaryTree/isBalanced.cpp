#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>

using namespace std;
//https://leetcode.com/problems/balanced-binary-tree/discuss/35854/C%2B%2B-DFS-solution
///To check if a tree is height-balanced, get the height of left and right subtrees.
//Return true if difference between heights is not more than 1 and left and right subtrees are balanced, otherwise return false.

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

bool isBalanced(BNode *root);
bool checkBalanced(BNode* root, int& height);

bool isBalanced(BNode* root) {
	int height = 0;
	return checkBalanced(root, height);
}

bool checkBalanced(BNode* root, int& height) {
	if(root == NULL){
		height = 0;
		return true;
	}

	int leftHeight = 0;
	int rightHeight = 0;
	if(!checkBalanced(root->left, leftHeight)) return false;
	if(!checkBalanced(root->right, rightHeight)) return false;

	if(abs(leftHeight - rightHeight) > 1) return false;
	height = max(leftHeight, rightHeight) + 1;
	return true;
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

    cout << isBalanced(root) << endl;

    delete root;
	return 0;
}*/
