#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) {
		val = x;
		left = right = nullptr;
	}
};
/*https://www.educative.io/courses/grokking-the-coding-interview/RMlGwgpoKKY
 * Given a binary tree and a number ‘S’, find if the tree has a path from root-to-leaf such that the sum of all the node values of that path equals ‘S’.
 *
 */
class RootToLeafPath{
public:
	//TC:O(N), SC:O(N)
	bool rootToLeafPathExists(TreeNode* root, int sum) {
		if(root == nullptr) return false;

		if(root->val == sum && root->left == nullptr && root->right == nullptr)
			return true;

		return rootToLeafPathExists(root->left, sum - root->val) || rootToLeafPathExists(root->right, sum - root->val);
	}
};

/*
int main() {
	  TreeNode *root = new TreeNode(12);
	  root->left = new TreeNode(7);
	  root->right = new TreeNode(1);
	  root->left->left = new TreeNode(9);
	  root->right->left = new TreeNode(10);
	  root->right->right = new TreeNode(5);
	  RootToLeafPath rtp;
	  cout << "Tree has path: " << rtp.rootToLeafPathExists(root, 23) << endl;
	  cout << "Tree has path: " << rtp.rootToLeafPathExists(root, 16) << endl;
}
*/
