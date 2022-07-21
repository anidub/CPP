#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/subtree-of-another-tree/
 * Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same
 *  structure and node values of subRoot and false otherwise.
 *  Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
 *
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class SubtreeAnotherTree {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if(s == nullptr) return false;
		if(isSame(s, t)) return true;

		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}

private:
	bool isSame(TreeNode* s, TreeNode *t) {
		if(s == nullptr && t == nullptr) return true;
		if(s == nullptr || t == nullptr) return false;

		if(s->val != t->val) return false;
		return isSame(s->left, t->left) && isSame(s->right, t->right);
	}
};
/*
int main() {
	SubtreeAnotherTree btmps;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->right = new TreeNode(7);
	root->right->left = new TreeNode(15);
	cout << btmps.isSubtree(root, root) << endl;
}
*/
