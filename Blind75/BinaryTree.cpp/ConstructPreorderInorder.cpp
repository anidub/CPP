#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree
 * and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class ConstructPreorderInorder {
public:
	//TC:O(N), SC:O(N)
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int rootIndex = 0;
		return helper(preorder, rootIndex, inorder, 0, inorder.size() - 1);
	}

private:
	TreeNode* helper(vector<int>& preorder, int &rootIndex, vector<int>& inorder, int start, int end) {
		if(rootIndex >= preorder.size() || start > end) return nullptr;

		TreeNode* root = new TreeNode(preorder[rootIndex]);
		rootIndex++;

		int pos = findPosition(inorder, root->val, start, end);
		root->left = helper(preorder, rootIndex, inorder, start, pos - 1);
		root->right = helper(preorder, rootIndex, inorder, pos + 1, end);

		return root;
	}

	//CAN BUILD MAP FOR THIS FUNCTION FOR O(1) MAP of val and index
	int findPosition(vector<int>& inorder, int val, int left, int right) {
		for(int i = left; i <= right; i++) {
			if(val == inorder[i])
				return i;
		}
		return -1;
	}

};

/*
int main() {
	ConstructPreorderInorder cpi;
	vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
	cpi.buildTree(preorder, inorder);
}
*/
