#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
};
/*https://www.educative.io/courses/grokking-the-coding-interview/xVV1jA29YK9
 * Given a binary tree, find the length of its diameter. The diameter of a tree is the number of nodes on the longest path between any two leaf nodes. The diameter of a tree may or may not pass through the root.

Note: You can always assume that there are at least two leaf nodes in the given tree.
 *
 */
class TreeDiamter {
public:
	//TC:O(N), SC:O(N)
	int findTreeDiameter(TreeNode *root) {
		if(root == nullptr) return 0;
		int treeDiameter = 0;
		findTreeDiameterUtil(root, treeDiameter);
		return treeDiameter;
	}

	int findTreeDiameterUtil(TreeNode *root, int &treeDiameter) {
		if(root == nullptr) return 0;

		int leftTreeHeight = findTreeDiameterUtil(root->left, treeDiameter);
		int rightTreeHeight = findTreeDiameterUtil(root->right, treeDiameter);

		if(leftTreeHeight != 0 && rightTreeHeight != 0) {
			int diameter = leftTreeHeight + rightTreeHeight + 1;
			treeDiameter = max(treeDiameter, diameter);
		}

		return max(leftTreeHeight, rightTreeHeight) + 1;
	}
};
/*
int main(int argc, char *argv[]) {
	TreeDiamter td;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  cout << "Tree Diameter: " << td.findTreeDiameter(root) << endl;
  root->left->left = nullptr;
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  root->right->left->right->left = new TreeNode(10);
  root->right->right->left->left = new TreeNode(11);
  cout << "Tree Diameter: " << td.findTreeDiameter(root) << endl;
}
*/
