#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/path-sum-iii/
 * Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
https://leetcode.com/problems/path-sum-iii/discuss/91908/C%2B%2B-solution-with-prefix-sum-stored-in-hash-table
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

class CountPathsTargetSum {

unordered_map<int, int> seen;
int sum, res = 0;

public:
	//TC:O(N), SC:O(N)
	int countPathsTargetSum(TreeNode* root, int s) {
		if(root == nullptr) return 0;
		sum = s;
		seen[0] = 1;
		countPathsTargetSumUtil(root, 0);
		return res;
	}

	void countPathsTargetSumUtil(TreeNode *root, int cur_sum) {
		if(root == nullptr) return;

		cur_sum += root->val;

		if(seen.find(cur_sum - sum) != seen.end())
			res += seen[cur_sum - sum];

		seen[cur_sum]++;
		if(root->left != nullptr) countPathsTargetSumUtil(root->left, cur_sum);
		if(root->right != nullptr) countPathsTargetSumUtil(root->right, cur_sum);
		seen[cur_sum]--;
	}
};
/*
int main(int argc, char *argv[]) {
  CountPathsTargetSum cpts;
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << cpts.countPathsTargetSum(root, 11) << endl;
}*/
