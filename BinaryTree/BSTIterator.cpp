#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/binary-search-tree-iterator/
 * Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.


https://leetcode.com/problems/binary-search-tree-iterator/discuss/52703/C%2B%2B.-using-stack. : comments
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

class BSTIterator {
public:
	stack<BNode*> stk;
	BSTIterator(BNode* root) {
		while(root) {
			stk.push(root);
			root = root->left;
		}
	}

	bool hasNext() {
		return !stk.empty();
	}

	int next() {
		if(!hasNext())
			return INT_MIN;
		int res = stk.top()->data;
		BNode* node = stk.top();
		stk.pop();

		if(node->right != NULL) {
			node = node->right;
			stk.push(node);
			while(node->left != NULL) {
				node = node->left;
				stk.push(node);
			}
		}
		return res;
	}
};
/*
int main() {

	return 0;
}
*/
