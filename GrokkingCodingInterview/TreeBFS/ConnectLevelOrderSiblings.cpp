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
/*https://www.educative.io/courses/grokking-the-coding-interview/NE5109Jl02v
 * Given a binary tree, connect each node with its level order successor. The last node of each level should point to the first node of the next level.
 */
class LevelOrderSiblings {
public:
	//TC:O(N), SC:O(N)
	void connectLevelOrderSiblings(TreeNode *root) {
		if(root == nullptr) return;
		queue<TreeNode*> queue; queue.push(root);

		while(!queue.empty()) {
			int sz = queue.size();
			TreeNode* previousNode = nullptr;
			for(int i = 0; i < sz; i++) {
				TreeNode *currentNode = queue.front(); queue.pop();
				if(previousNode != nullptr)
					previousNode->next = currentNode;

				previousNode = currentNode;
				if(currentNode->left != nullptr)
					queue.push(currentNode->left);
				if(currentNode->right != nullptr)
					queue.push(currentNode->right);
			}
		}
	}

	  // level order traversal using 'next' pointer
	  void printLevelOrder(TreeNode *root) {
	    TreeNode *nextLevelRoot = root;
	    while (nextLevelRoot != nullptr) {
	    	TreeNode *current = nextLevelRoot;
	    	nextLevelRoot = nullptr;
	    	while (current != nullptr) {
	    		cout << current->val << " ";
	    		if (nextLevelRoot == nullptr) {
	    			if (current->left != nullptr) {
	    				nextLevelRoot = current->left;
	    			} else if (current->right != nullptr) {
	    				nextLevelRoot = current->right;
	    			}
	    		}
	    		current = current->next;
	    	}
	    	cout << endl;
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
  LevelOrderSiblings ls;
  ls.connectLevelOrderSiblings(root);
  cout << "Level order traversal using 'next' pointer: " << endl;
  ls.printLevelOrder(root);
}*/
