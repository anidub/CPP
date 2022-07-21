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
		left = nullptr;
		right = nullptr;
	}
};
/*https://www.educative.io/courses/grokking-the-coding-interview/YQ5o5vEXP69
 * Given a binary tree where each node can only have a digit (0-9) value, each root-to-leaf path will represent a number.
 * Find the total sum of all the numbers represented by all paths.
 * Iterative code in binary tree folder
 */

class RootToLeafNumbers {
public:
	//TC:O(N), SC: O(N)
	int findSumOfPathNumbers(TreeNode *root) {
		if(root == nullptr) return 0;

		int totalPathSum = 0;

		return findSumOfPathNumbersUtil(root, totalPathSum);
	}

	int findSumOfPathNumbersUtil(TreeNode *root, int totalPathSum) {
		if(root == nullptr) return 0;

		totalPathSum = totalPathSum * 10 + root->val;

		if(root->left == nullptr && root->right == nullptr)
			return totalPathSum;

		return findSumOfPathNumbersUtil(root->left, totalPathSum) +
				findSumOfPathNumbersUtil(root->right, totalPathSum);
	}
};
/*
int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  RootToLeafNumbers rln;
  cout << "Total Sum of Path Numbers: " << rln.findSumOfPathNumbers(root) << endl;
}*/
