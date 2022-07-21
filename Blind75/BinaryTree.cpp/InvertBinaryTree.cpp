#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/invert-binary-tree/
 * Given the root of a binary tree, invert the tree, and return its root.
 * Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class InvertBinaryTree {
public:
	//TC:O(N), SC: O(H)
	TreeNode* invertTreeRecursive(TreeNode* root) {
		if(root == nullptr) return nullptr;
		swap(root->left, root->right);
		invertTreeRecursive(root->left);
		invertTreeRecursive(root->right);
		return root;
	}

	//TC:O(N), SC: O(N)
	TreeNode* invertTreeIterative(TreeNode* root) {
		if(root == nullptr) return nullptr;

		queue<TreeNode*> todo;
		todo.push(root);

		while(!todo.empty()) {
			TreeNode* node = todo.front();
			todo.pop();

			swap(node->left, node->right);
			if(node->left) todo.push(node->left);
			if(node->right) todo.push(node->right);
		}
		return root;
	}


};

/*
int main() {
	InvertBinaryTree ibt;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->right = new TreeNode(7);
	root->right->left = new TreeNode(15);

	ibt.invertTreeRecursive(root);
	ibt.invertTreeIterative(root);
}
*/
