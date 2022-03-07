#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
 * Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252232/JavaC%2B%2BPython-O(N)-Solution
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

BNode* bstFromPreorder(vector<int>& preorder);
BNode* buildBSTfromPreorder(vector<int>& preorder, int& i, int bound);

//Time O(N) Space O(H)
BNode* bstFromPreorder(vector<int>& preorder) {
	int i = 0;
	return buildBSTfromPreorder(preorder, i, INT_MAX);
}

BNode* buildBSTfromPreorder(vector<int>& preorder, int& i, int bound)  {
	if(i == preorder.size() || preorder[i] > bound) return NULL;

	BNode* root = new BNode(preorder[i++]);
	root->left = buildBSTfromPreorder(preorder, i, root->data);
	root->right = buildBSTfromPreorder(preorder, i, bound);
	return root;
}
/*
int main() {
	vector<int> preorder = {8,5,1,7,10,12};
	bstFromPreorder(preorder);
}*/
