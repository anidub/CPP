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
/*https://www.educative.io/courses/grokking-the-coding-interview/B8nj5RB1LJo
 * Given a binary tree, return an array containing nodes in its right view. The right view of a binary tree is the set of nodes visible when the tree is seen from the right side.
 */
class RightSideView {
public:
	//TC:O(N), SC:O(N)
	vector<TreeNode*> rightSideView(TreeNode *root) {
		vector<TreeNode*> result;
		if(root == nullptr) return result;

		queue<TreeNode*> queue; queue.push(root);

		while(!queue.empty()) {
			int levelSize = queue.size();
			for(int i = 0; i < levelSize; i++) {
				TreeNode *node = queue.front(); queue.pop();
				if(i == levelSize - 1)
					result.push_back(node);
				if(node->left != nullptr)
					queue.push(node->left);
				if(node->right != nullptr)
					queue.push(node->right);
			}
		}
		return result;
	}
	//TC:O(N), SC:O(N)
	vector<TreeNode*> leftSideView(TreeNode *root) {
		vector<TreeNode*> result;
		if(root == nullptr) return result;

		queue<TreeNode*> queue; queue.push(root);

		while(!queue.empty()) {
			int levelSize = queue.size();
			for(int i = 0; i < levelSize; i++) {
				TreeNode *node = queue.front(); queue.pop();
				if(i == 0)
					result.push_back(node);
				if(node->left != nullptr)
					queue.push(node->left);
				if(node->right != nullptr)
					queue.push(node->right);
			}
		}
		return result;
	}
};
/*
int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->left->left->left = new TreeNode(3);
  RightSideView rsv;
  vector<TreeNode *> result = rsv.rightSideView(root);
  for (auto node : result) {
    cout << node->val << " ";
  }
  cout << endl;
  result = rsv.leftSideView(root);
  for (auto node : result) {
    cout << node->val << " ";
  }
}*/
