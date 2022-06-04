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
/*https://www.educative.io/courses/grokking-the-coding-interview/m2N6GwARL8r
 * Given a binary tree, populate an array to represent its level-by-level traversal in reverse order, i.e., the lowest level comes first.
 *  You should populate the values of all nodes in each level from left to right in separate sub-arrays.
 */
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

class ReverseLevelOrderTraversal {
public:
	//TC:O(N), SC:O(N)
 deque<vector<int>> reverseLevelOrder(TreeNode *root) {
	 deque<vector<int>> result = deque<vector<int>>();
	 queue<TreeNode*> q;
	 q.push(root);

	 while(!q.empty()) {
		 vector<int> curLevel;
		 int sz = q.size();
		 for(int i = 0; i < sz; i++) {
			 TreeNode *tmp = q.front(); q.pop();
			 curLevel.push_back(tmp->val);
			 if(tmp->left) q.push(tmp->left);
			 if(tmp->right) q.push(tmp->right);
		 }
		 result.push_front(curLevel);
	 }
	 return result;
 }
};
/*
int main() {
	ReverseLevelOrderTraversal rl;
	  TreeNode *root = new TreeNode(12);
	  root->left = new TreeNode(7);
	  root->right = new TreeNode(1);
	  root->left->left = new TreeNode(9);
	  root->right->left = new TreeNode(10);
	  root->right->right = new TreeNode(5);
	  auto result = rl.reverseLevelOrder(root);

	  cout << "Reverse level order traversal: ";
	  for (auto que : result) {
	    for (auto num : que) {
	      cout << num << " ";
	    }
	    cout << endl;
	  }
}*/
