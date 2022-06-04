#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
 * Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
 * Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/106063/C%2B%2B-Clean-Code-O(n)-time-O(lg-n)-space-BinaryTree-Iterator : used
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/1420711/C%2B%2BJavaPython-3-solutions%3A-HashSet-Stack-Python-yield-Solutions-O(H)-space : while loop
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {

stack<TreeNode*> st;
TreeNode* node;
bool forward;

public:

BSTIterator(TreeNode *root, bool forward) : node(root), forward(forward) {};

int hasNext() {
	return node != nullptr && !st.empty();
}

int peak() {
	if(st.empty()) return -1;
	return st.top()->val;
}

int next() {
	while(node || !st.empty()) {
		if(node) {
			st.push(node);
			node = forward ? node->left : node->right;
		} else {
			node = st.top(); st.pop();
			int nextVal = node->val;
			node = forward ? node->right : node->left;
			return nextVal;
		}
	}
	return -1;
}

};
//TC: O(N), SC: O(H)
bool findTargetFourSum(TreeNode *root, int target) {
	if(!root) return false;

	BSTIterator leftItr(root, true);
	BSTIterator rightItr(root, false);

	int left = leftItr.next(), right = rightItr.next();

	while(left < right) {
		if(left + right == target) return true;
		else if(left + right < target)
			left = leftItr.next();
		else
			right = rightItr.next();
	}
	return false;
}
/*
int main() {
	TreeNode* root = new TreeNode(15);
	root->left = new TreeNode(10);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(16);
	root->right->right = new TreeNode(25);

	cout << findTargetFourSum(root, 36) << endl;
	delete root;
	return 0;
}*/
