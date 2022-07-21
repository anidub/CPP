#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/xVPgnOvWVJq
 * Find the path with the maximum sum in a given binary tree. Write a function that returns the maximum sum.

A path can be defined as a sequence of nodes between any two nodes and doesn’t necessarily pass through the root. The path must contain at least one node.
 */
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

class PathMaximumSum {
public:
	//TC:O(N), SC:O(N)
	int findPathMaximumSum(TreeNode* root) {
		if(root == nullptr) return INT_MIN;
		int globalSum = INT_MIN;
		findPathMaximumSumUtil(root, globalSum);
		return globalSum;
	}

	int findPathMaximumSumUtil(TreeNode *root, int &globalSum) {
		if(root == nullptr) return 0;

		int leftPathSum = findPathMaximumSumUtil(root->left, globalSum);
		int rightPathSum = findPathMaximumSumUtil(root->right, globalSum);

		leftPathSum = max(leftPathSum, 0);
		rightPathSum = max(rightPathSum, 0);

		int curSum = leftPathSum + rightPathSum + root->val;

		globalSum = max(globalSum, curSum);

		return max(leftPathSum, rightPathSum) + root->val;
	}
};
/*
int main(int argc, char *argv[]) {
	PathMaximumSum pms;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << "Maximum Path Sum: " << pms.findPathMaximumSum(root) << endl;

  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  cout << "Maximum Path Sum: " << pms.findPathMaximumSum(root) << endl;

  root = new TreeNode(-1);
  root->left = new TreeNode(-3);
  cout << "Maximum Path Sum: " << pms.findPathMaximumSum(root) << endl;
}*/
