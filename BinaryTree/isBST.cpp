#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <set>
#include <stack>

using namespace std;
//is BST //https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

class BNode {
public:
	int data;
	BNode* left;
	BNode* right;

	BNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};


bool isBstUtil(BNode *root, int min, int max) {
	if(root == NULL) return true;

	if(root->data <= min || root->data >= max)
		return false;

	return isBstUtil(root->left, min, root->data) && isBstUtil(root->right, root->data, max);
}

bool isBst(BNode *root) {
	return isBstUtil(root, INT_MIN, INT_MAX);
}
///https://leetcode.com/problems/validate-binary-search-tree/discuss/234410/C%2B%2B-recursive-and-iterative
bool isBSTIterative(BNode* root) {
	long prev = LONG_MIN;
	stack<BNode*> stk;

	while(root || !stk.empty()) {
		while(root) {
			stk.push(root);
			root = root->left;
		}
		root = stk.top(); stk.pop();
		if(root->data <= prev) return false;

		prev = root->data;
		root = root->right;
	}
	return true;
}
/*
int main() {
	BNode *root = new BNode(4);
    root->left = new BNode(2);
    root->right = new BNode(5);
    root->left->left = new BNode(1);
    root->left->right = new BNode(3);

    if(isBst(root))
        cout<<"Is BST";
    else
        cout<<"Not a BST";

    delete root;
    return 0;
}*/
