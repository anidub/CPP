#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/validate-binary-search-tree/
 *Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 *Given Input: root = [2,1,3]
Output: true

 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class ValidBST {
public:
	bool isValidBSTIterative(TreeNode* root) {
		long prev = LONG_MIN;
		stack<TreeNode*> st;

		while(root || !st.empty()) {
			while(root) {
				st.push(root);
				root = root->left;
			}
			root = st.top(); st.pop();
			if(root->val <= prev) return false;
			prev = root->val;
			root = root->right;
		}
		return true;
	}

	bool isValidRecursive(TreeNode* root) {
		if(root == nullptr) return false;
		return isValidRecursive(root, LONG_MIN, LONG_MAX);
	}

private:
	bool isValidRecursive(TreeNode* root, long min, long max) {
		if(root == nullptr) return true;
		if(root->val <= min || root->val >= max) return false;
		return isValidRecursive(root, min, root->val) && isValidRecursive(root, root->val, max);

	}
};
/*
int main() {
	ValidBST vb;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->right = new TreeNode(7);
	root->right->left = new TreeNode(15);

	cout << vb.isValidBSTIterative(root) << endl;
	cout << vb.isValidRecursive(root) << endl;
}
*/
