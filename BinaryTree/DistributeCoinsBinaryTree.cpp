#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/distribute-coins-in-binary-tree/
 * You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal : good explanation, comments
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

int distributeCoinsUtil(BNode* root, int& moves);
int distributeCoins(BNode* root) {
	if(!root) return 0;
	int moves = 0;
	distributeCoinsUtil(root, moves);
	return moves;
}

int distributeCoinsUtil(BNode* root, int& moves) {
	if(!root) return 0;
	int left = distributeCoinsUtil(root->left, moves);
	int right = distributeCoinsUtil(root->right, moves);
	moves += abs(left) + abs(right);

	return root->data + left + right - 1;
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

    cout << distributeCoins(root) << endl;
    delete root;

	return 0;
}
*/
