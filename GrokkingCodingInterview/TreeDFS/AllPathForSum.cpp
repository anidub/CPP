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
 * https://www.educative.io/courses/grokking-the-coding-interview/B815A0y2Ajn
 * Given a binary tree and a number ‘S’, find all paths from root-to-leaf such that the sum of all the node values of each path equals ‘S’.
 *
 * The time complexity of the above algorithm is O(N^2), where ‘N’ is the total number of nodes in the tree.
 *  This is due to the fact that we traverse each node once (which will take O(N), and for every leaf node,
 *   we might have to store its path (by making a copy of the current path) which will take O(N)

 */

class AllPathsForSum {
public:
	//TC:O(N^2), SC:O(N) SC is O (n) because output space is not counted
	vector<vector<int>> getAllRootToLeafPaths(TreeNode *root, int sum) {
		vector<vector<int>> allPaths;
		if(root == nullptr) return allPaths;

		vector<int> currentPath;

		getAllRootToLeafPathsUtil(root, sum, allPaths, currentPath);

		return allPaths;
	}

	void getAllRootToLeafPathsUtil(TreeNode *root, int sum, vector<vector<int>> &allPaths, vector<int> &currentPath) {
		if(root == nullptr) return;

		currentPath.push_back(root->val);

		if(root->val == sum && root->left == nullptr && root->right == nullptr) {
			allPaths.push_back(currentPath);
		} else {
			getAllRootToLeafPathsUtil(root->left, sum - root->val, allPaths, currentPath);

			getAllRootToLeafPathsUtil(root->right, sum - root->val, allPaths, currentPath);
		}
		currentPath.pop_back();
	}
};
/*
int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int sum = 23;
  AllPathsForSum aps;
  vector<vector<int>> result = aps.getAllRootToLeafPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}*/
