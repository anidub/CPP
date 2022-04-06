#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>

using namespace std;

class BNode{
public:
	int data;
	BNode *left;
	BNode *right;

	BNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
/*https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
 * Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/discuss/274610/JavaC%2B%2BPython-Top-Down
 */
int maxAncestorDiffDFS(BNode* root, int mn, int mx);

//Time Complexity : O(N)  Space Complexity : O(H)
int maxAncestorDiff(BNode* root) {
    if(root == nullptr) return 0;
    return maxAncestorDiffDFS(root, root->data, root->data);
}

int maxAncestorDiffDFS(BNode* root, int mn, int mx) {
	if(root == nullptr) return mx - mn;

	mx = max(mx, root->data);
	mn = min(mn, root->data);

	return max(maxAncestorDiffDFS(root->left, mn, mx), maxAncestorDiffDFS(root->right, mn, mx) );
}
/*
int main() {
	BNode* root = new BNode(1);
	root->left = new BNode(2);
	root->right = new BNode(3);
	root->left->left = new BNode(4);
	root->right->left = new BNode(5);
	root->right->right = new BNode(6);
	root->right->right->left = new BNode(8);
	root->right->left->right = new BNode(7);

    cout << maxAncestorDiff(root) << endl;

    delete root;
	return 0;
}*/
