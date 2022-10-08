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
 TreeNode *next;

 TreeNode(int x) {
   val = x;
   left = right = next = nullptr;
 }
};
/*
https://www.educative.io/courses/grokking-the-coding-interview/m2YYxXDOJ03
Given a binary tree, connect each node with its level order successor. The last node of each level should point to the first node of the next level.
 */

class ConnectAllLevelOrderNodes {
public:
	//TC:O(N), SC:O(N)
	void connectAllLevelOrderNodes(TreeNode* root) {
		if(root == nullptr) return;
		queue<TreeNode*> queue;
		queue.push(root);

		TreeNode *previousNode = nullptr, *currentNode = nullptr;

		while(!queue.empty()) {
			currentNode = queue.front(); queue.pop();
			if(previousNode != nullptr)
				previousNode->next = currentNode;

			previousNode = currentNode;
			if(currentNode->left != nullptr)
				queue.push(currentNode->left);
			if(currentNode->right)
				queue.push(currentNode->right);
		}
	}

	  // level order traversal using 'next' pointer
	  void printTree(TreeNode *root) {
		    TreeNode *current = root;
		    cout << "Traversal using 'next' pointer: ";
		    while (current != nullptr) {
		      cout << current->val << " ";
		      current = current->next;
		    }
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
  ConnectAllLevelOrderNodes c;
  c.connectAllLevelOrderNodes(root);
  c.printTree(root);
}*/
