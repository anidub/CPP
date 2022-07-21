#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/same-tree/
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
Input: p = [1,2,3], q = [1,2,3]
Output: true
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class SameTree {
public:
	//TC:O(N), SC:O(N)
	 bool isSameTreeRecursive(TreeNode* p, TreeNode* q) {
		 if(p == nullptr || q == nullptr) {
			 if(p == nullptr && q == nullptr)
				 return true;
			 return false;
		 }
		 if(p->val != q->val) return false;
		 return isSameTreeRecursive(p->left, q->left) && isSameTreeRecursive(p->right, q->right);
	 }

	 //TC:O(N), SC:O(N)
	 bool isSameIterative(TreeNode* p, TreeNode* q) {
		 queue<pair<TreeNode*, TreeNode*>> todo;
		 todo.push({p, q});

		 while(!todo.empty()) {
			 pair<TreeNode*, TreeNode*> entry = todo.front(); todo.pop();
			 if(entry.first == nullptr &&  entry.second == nullptr) continue;
			 else if(entry.first == nullptr || entry.second == nullptr) return false;
			 else {
				 if(entry.first->val != entry.second->val)
					 return false;
				 else {
					 todo.push({entry.first->left, entry.second->left});
					 todo.push({entry.first->right, entry.second->right});
				 }
			 }
		 }
		 return true;
	 }

};
/*
int main() {
	SameTree md;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->right = new TreeNode(7);
	root->right->left = new TreeNode(15);

	cout << md.isSameIterative(root, root) << endl;
	cout << md.isSameTreeRecursive(root, root) << endl;
}*/
