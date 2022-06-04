#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
/* change a tree so that the roles of the left
and right hand pointers are swapped at every node
https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
 Worst-case Time complexity is O(n), SC:O(1)
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

void swapLeftRightNodes(BNode* root) {
	if(root == nullptr) return;
	swapLeftRightNodes(root->left);
	swapLeftRightNodes(root->right);

	BNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
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
