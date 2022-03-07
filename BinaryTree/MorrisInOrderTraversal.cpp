#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
//https://www.educative.io/edpresso/what-is-morris-traversal
/*Algorithm
Initialize the root as the current node curr.

While curr is not NULL, check if curr has a left child.

If curr does not have a left child, print curr and update it to point to the node on the right of curr.

Else, make curr the right child of the rightmost node in curr's left subtree.

Update curr to this left node.
 *
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
//time : O(N) space : O(1)
void MorrisInorderTraversal(BNode* root) {
	if(root == NULL) return;
	BNode* cur = root;
	BNode* prev;

	while(cur != NULL) {
		if(cur->left == NULL) {
			cout << cur->data << " ";
			cur = cur->right;
		} else {
			prev = cur->left;
			while(prev->right != NULL && prev->right != cur) {
				prev = prev->right;
			}
			if(prev->right == NULL) {
				prev->right = cur;
				cur = cur->left;
			} else {
				prev->right = NULL;
				cout << cur->data << " ";
				cur = cur->right;
			}
		}
	}
}
/*
int main() {
	BNode* root = new BNode(4);
	root->left = new BNode(2);
	root->right = new BNode(5);
	root->left->left = new BNode(1);
	root->left->right = new BNode(3);
	MorrisInorderTraversal(root);
	delete root;

	return 0;
}
*/
