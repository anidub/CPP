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
/*
 * Given a binary tree, find the root-to-leaf path with the maximum sum.
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/39873/recommend-for-beginnersclean-C%2B%2B-implementation-with-detailed-explanation
 */
class MaxPathSum {
	int max_path_sum;
public:
	//TC:O(N), SC:O(H) where H is a tree height, to keep the recursion stack.
	int maxPathSum(TreeNode* root) {
		max_path_sum = INT_MIN;
		if(root == nullptr) return max_path_sum;
		maxPathSumHelper(root);
		return max_path_sum;
	}

	int maxPathSumHelper(TreeNode *root) {
		if(root == nullptr) return 0;

		int left = max(0, maxPathSumHelper(root->left)); // could use INT_MIN instead of 0 if all negative values in tree
		int right = max(0, maxPathSumHelper(root->right));

		max_path_sum = max(max_path_sum, left + right + root->val);

		return max(left, right) + root->val;
	}
};

//https://makeinjava.com/find-maximum-sum-root-leaf-path-binary-tree-java-recursive-example/
//Max sum path from root to leaf
class MaxPathRootToLeafPath{
public:
	int maxSum = INT_MIN;
	vector<int> getMaxRootToLeafSumPath(TreeNode* root) {
		vector<int> result;
		vector<int> curPath;
		getMaxRootToLeafSumPathHelper(root, curPath, result, 0, 0);
		return result;
	}

	void getMaxRootToLeafSumPathHelper(TreeNode* root, vector<int> curPath, vector<int> result, int index, int sum) {
		if(root == nullptr) return;

		sum += root->val;
		curPath[index++] = root->val;

		if(root->left == nullptr && root->right == nullptr) {
			if(sum > maxSum) {
				maxSum = sum;
				result = curPath.begin() + index;
			}
			return ;
		}
		getMaxRootToLeafSumPathHelper(root->left, curPath, result, index, sum);
		getMaxRootToLeafSumPathHelper(root->right, curPath, result, index, sum);
	}
};

/*
int main() {
	  TreeNode *root = new TreeNode(12);
	  root->left = new TreeNode(7);
	  root->right = new TreeNode(1);
	  root->left->left = new TreeNode(4);
	  root->right->left = new TreeNode(10);
	  root->right->right = new TreeNode(5);

	  MaxPathSum mxps;
	  cout << mxps.maxPathSum(root) << endl;

	return 0;
}*/
