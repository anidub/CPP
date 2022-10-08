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
/*https://www.educative.io/courses/grokking-the-coding-interview/7nO4VmA74Lr
 * Given a binary tree and a node, find the level order successor of the given node in the tree.
 *  The level order successor is the node that appears right after the given node in the level order traversal.
 */
class LevelOrderSuccessor {
public:
	//TC:O(N), SC:O(N)
	TreeNode * levelOrderSuccessor(TreeNode *root, int key) {
		if(root == nullptr) return root;
		queue<TreeNode*> queue; queue.push(root);

		while(!queue.empty()) {
			TreeNode *node = queue.front();
			queue.pop();

			if(node->left) queue.push(node->left);
			if(node->right) queue.push(node->right);

			if(node->val == key) break;
		}
		return queue.front();

	}
};
/*
int main() {
		LevelOrderSuccessor LOS;
	  TreeNode *root = new TreeNode(1);
	  root->left = new TreeNode(2);
	  root->right = new TreeNode(3);
	  root->left->left = new TreeNode(4);
	  root->left->right = new TreeNode(5);

	  TreeNode *result = LOS.levelOrderSuccessor(root, 3);
	  if (result != nullptr) {
	    cout << result->val << " " << endl;
	  }

	  root = new TreeNode(12);
	  root->left = new TreeNode(7);
	  root->right = new TreeNode(1);
	  root->left->left = new TreeNode(9);
	  root->right->left = new TreeNode(10);
	  root->right->right = new TreeNode(5);

	  result = LOS.levelOrderSuccessor(root, 9);
	  if (result != nullptr) {
	    cout << result->val << " " << endl;
	  }

	  result = LOS.levelOrderSuccessor(root, 12);
	  if (result != nullptr) {
	    cout << result->val << " " << endl;
	  }
}
*/
