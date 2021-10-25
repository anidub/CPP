#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/448995/Easy-to-understand-C%2B%2B-Solution
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34557/My-neat-C%2B%2B-solution ..comments
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

int findPosition(vector<int>& inorder, int val, int left, int right) {
	for(int i = left; i <= right; i++) {
		if(inorder[i] == val)
			return i;
	}
	return -1;
}
TreeNode* helper(vector<int>& preorder, int& rootIndex, vector<int>& inorder, int start, int end) {
	if(rootIndex >= preorder.size() || start > end) return nullptr;

	TreeNode* root = new TreeNode(preorder[rootIndex]);

	int pos = findPosition(inorder, root->val, start, end);
	rootIndex++;

	root->left = helper(preorder, rootIndex, inorder, start, pos-1);
	root->right = helper(preorder, rootIndex, inorder, pos+1, end);
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int rootIndex = 0;
	return helper(preorder, rootIndex, inorder, 0, inorder.size() - 1);
}
/*
int main() {
	vector<int>& preorder;
	preorder.push_back(3);preorder.push_back(9);preorder.push_back(20);preorder.push_back(15);preorder.push_back(7);
	vector<int>& inorder;
	inorder.push_back(9);inorder.push_back(3);inorder.push_back(15);inorder.push_back(20);inorder.push_back(7);

	buildTree(preorder, inorder);
	return 0;
}
*/
