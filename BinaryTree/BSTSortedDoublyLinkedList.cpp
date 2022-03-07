#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
 * Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and s
uccessor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first
element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation, the left pointer of the tree node should
 point to its predecessor, and the right pointer
 should point to its successor. You should return the pointer to the smallest element of the linked list.
 https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/discuss/231396/C%2B%2B-Recursive-and-Iterative
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

BNode* BSTToDoublyLL(BNode* root) {
	if(!root) return NULL;

	stack<BNode*> stk;
	BNode *first = NULL, *last = NULL;

	while(root || !stk.empty()) {
		while(root) {
			stk.push(root);
			root = root->left;
		}
		root = stk.top();
		stk.pop();
		if(!first) {
			first = root;
		}
		if(last) {
			last->right = root;
			root->left = last;
		}
		last = root;
		root = root->right;
	}
	first->left = last;
	last->right = first;
	return first;
}
/*
int main() {
	BNode* root = new BNode(20);
	root->left = new BNode(8);
	root->left->left = new BNode(4);
	root->left->right = new BNode(12);
	root->left->right->left = new BNode(10);
	root->left->right->right = new BNode(14);
	BSTToDoublyLL(root);
	delete root;
	return 0;
}*/
