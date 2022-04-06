#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/closest-binary-search-tree-value/
 *Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target.

 *Input: root = [4,2,5,1,3], target = 3.714286
Output: 4
 *
 *https://leetcode.com/problems/closest-binary-search-tree-value/discuss/70401/C%2B%2B-recursive-and-iterative-solution
 */
class BNode {
public:
	int val;
	BNode *left;
	BNode *right;

	BNode(int val) {
		this->val = val;
		left = nullptr;
		right = nullptr;
	}
};
//Time complexity : O(H) since here one goes from root down to a leaf.SC: O(1)
int closestValueBST(BNode *root, double target) {
	int result = root->val;

	while(root) {
		if( (double)root->val == target) return root->val;
		if( abs((double) root->val - target) < abs((double)result - target) )
			result = root->val;
		if(root->val < target)
			root = root->right;
		else
			root = root->left;
	}
	return result;
}
/*
int main() {
	BNode* root = new BNode(20);
	root->left = new BNode(8);
	root->left->left = new BNode(4);
	root->left->right = new BNode(12);
	root->left->right->left = new BNode(10);
	root->left->right->right = new BNode(14);
	cout << closestValueBST(root, 3.75) << endl;

	return 0;
}*/
