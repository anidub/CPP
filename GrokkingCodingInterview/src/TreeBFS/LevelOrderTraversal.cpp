#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <utility>

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
/*
 * https://www.educative.io/courses/grokking-the-coding-interview/xV7E64m4lnz
 * Given a binary tree, populate an array to represent its level-by-level traversal. You should populate the values of all nodes of each level from left to right in separate sub-arrays.
 */
class LevelOrderTraversal {
public:
//TC:O(N), SC:O(N)
vector<vector<int>> traverseLevelOrder(TreeNode *root) {
	if(root == nullptr) return {};
	vector<vector<int>> result;
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()) {
		int sz = q.size();
		vector<int> curLevel;
		for(int i = 0; i < sz; i++) {
			TreeNode *tmp = q.front(); q.pop();
			curLevel.push_back(tmp->val);
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
		}
		result.push_back(curLevel);
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
  LevelOrderTraversal lp;
  vector<vector<int>> result = lp.traverseLevelOrder(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}*/
