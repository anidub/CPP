#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/maximum-width-of-binary-tree/
 * Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.
https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/726946/C%2B%2B-or-fastest-or-BFS : comments

read soln
https://www.youtube.com/watch?time_continue=496&v=qCAbp1f9T5o&feature=emb_logo : explained logic
 *https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/106654/JavaC%2B%2B-Very-simple-dfs-solution : dfs
 *We know that a binary tree can be represented by an array (assume the root begins from the position with index 1 in the array). If the index of a node is i, the indices of its two children are 2*i and 2*i + 1. The idea is to use two arrays (start[] and end[]) to record the the indices of the leftmost node and rightmost node in each level, respectively. For each level of the tree, the width is end[level] - start[level] + 1. Then, we just need to find the maximum width.
 */
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

int getMaxWidthBinaryTree(BNode* root) {
	if(!root) return 0;

	queue<pair<BNode*, unsigned long long int>> q; // unsigned long long int is to accomodate large array indexes, constraints of problem
	q.push({root, 1});
	int width = 0;

	while(!q.empty()) {
		auto left = q.front().second;
		auto right = left;
		int size = q.size();

		while(size-- > 0) {
			auto [node, index] = q.front(); q.pop(); // use pair<TreeNode*, unsigned long long int> instead of auto
			right = index;

			if(node->left) q.push({node->left, 2 * index});
			if(node->right) q.push({node->right, 2 * index + 1});
		}
		width = max(width, int(right- left + 1)); //casting to compare int vs int
	}
	return width;
}
/*
int main() {
    BNode* root = new BNode(20);
    root->left = new BNode(8);
    root->left->left = new BNode(4);
    root->left->right = new BNode(12);
    root->left->right->left = new BNode(10);
    root->left->right->right = new BNode(14);
    root->right = new BNode(22);
    root->right->right = new BNode(25);

    cout << getMaxWidthBinaryTree(root) << endl;

    delete root;

	return 0;
}*/
