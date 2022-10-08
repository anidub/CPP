#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};
/*https://www.educative.io/courses/grokking-the-coding-interview/3jwVx84OMkO
 * Find the minimum depth of a binary tree. The minimum depth is the number of nodes along the shortest path from the root node to the nearest leaf node.
 *
 */

class MinDepth_MaxDepth {
public:
	//TC:O(N), SC:O(N)
	int minDepthOfTree(TreeNode *root) {
		if(!root) return 0;
		queue<TreeNode*> queue;
		queue.push(root);
		int minDepth = 0;

		while(!queue.empty()) {
			minDepth++;
			int sz = queue.size();
			for(int i = 0; i < sz; i++) {
				TreeNode *node = queue.front();
				queue.pop();

				if(node->left == nullptr && node->right == nullptr)
					return minDepth;
				if(node->left)
					queue.push(node->left);
				if(node->right)
					queue.push(node->right);
			}
		}
		return minDepth;
	}

	//TC:O(N), SC:O(N)
	int maxDepthOfTree(TreeNode *root) {
		if(!root) return 0;
		queue<TreeNode*> queue;
		queue.push(root);
		int maxDepth = 0;
		while(!queue.empty()) {
			maxDepth++;
			int sz = queue.size();
			for(int i = 0; i < sz; i++) {
				TreeNode* node = queue.front(); queue.pop();
				if(node->left) queue.push(node->left);
				if(node->right) queue.push(node->right);
			}
		}
		return maxDepth;
	}
};
/*
int main(int argc, char *argv[]) {
  MinDepth_MaxDepth minMaxDepth;
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree Minimum Depth: " << minMaxDepth.minDepthOfTree(root) << endl;
  root->left->left = new TreeNode(9);
  root->right->left->left = new TreeNode(11);
  cout << "Tree Minimum Depth: " << minMaxDepth.maxDepthOfTree(root) << endl;
}
*/
