#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/recover-binary-search-tree/
 * You are given the root of a binary search tree (BST), where the values of exactly two nodes of
 * the tree were swapped by mistake. Recover the tree without changing its structure.
 * Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

https://leetcode.com/problems/recover-binary-search-tree/discuss/32580/recommend-for-beginnersclean-C%2B%2B-implementation-with-detailed-explaination :comments

 https://leetcode.com/problems/recover-binary-search-tree/solution/ : morris traversal optimal
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

BNode* first = NULL;
BNode* second = NULL;
BNode* previous = new BNode(20);

BNode* recoverTree(BNode* root);
void recoverTreeUtil(BNode* root);

BNode* recoverTree(BNode* root) {
	recoverTreeUtil(root);
	//swap(first->data, second->data); //works
}

void recoverTreeUtil(BNode* root) {
	if(!root) return;
	recoverTreeUtil(root->left);

	if(first == NULL && previous->data > root->data) first = previous;
	if(first != NULL && previous->data > root->data) second = root;

	previous = root;
	recoverTreeUtil(root->right);
}
//https://leetcode.com/problems/recover-binary-search-tree/discuss/926903/C-Solution-Morris-inorder-traversal
void recoverTreeOptimalMorris(BNode* root) {
	if(root == nullptr) return;
	BNode* fnode = nullptr, *snode = nullptr, *pnode = nullptr, *pred = nullptr;
	BNode* cur = root;

	while(cur != nullptr) {
		if(cur->left == nullptr) {
			if(pnode != nullptr && cur->data <= pnode->data) {
				if(fnode == nullptr)
					fnode = pnode;
				snode = cur;
			}
			pnode = cur;
			cur = cur->right;
		} else {
			pred = cur->left;
			while(pred->right != nullptr && pred->right != cur){
				pred = pred = pred->right;
			}
			if(pred->right == nullptr) {
				pred->right = cur;
				cur = cur->left;
			} else {
				if(pnode != nullptr && cur->data <= pnode->data) {
					if(fnode == nullptr)
						fnode = pnode;
					snode = cur;
				}
				pnode = cur;
				pred->right = nullptr;
				cur = cur->right;
			}
		}
	}
	int t = fnode->data;
	fnode->data = snode->data;
	snode->data = t;

	return;
}
/*
int main() {
	BNode* root = new BNode(20);
	root->left = new BNode(8);
	root->left->left = new BNode(4);
	root->left->right = new BNode(12);
	root->left->right->left = new BNode(14);
	root->left->right->right = new BNode(10);

	delete root;
	return 0;
}*/
