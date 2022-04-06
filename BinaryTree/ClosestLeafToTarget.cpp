#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/closest-leaf-in-a-binary-tree/
 * Given the root of a binary tree where every node has a unique value and a target integer k, return the value of the nearest leaf node to the target k in the tree.

Nearest to a leaf means the least number of edges traveled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.
 * https://leetcode.com/problems/closest-leaf-in-a-binary-tree/discuss/291155/Simple-C%2B%2B-recursive-beats-100-in-both-time-and-space
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

int min_Dist = INT_MAX;
int min_val;

int findNode(BNode *root, int k);
void traverseDown(BNode* root, int level);

int findClosestLeaf(BNode *root, int k) {
	findNode(root, k);
	return min_val;
}

int findNode(BNode *root, int k) {
	if(!root) return -1;

	if(root->data == k) {
		traverseDown(root, 0);
		return 0;
	}

	int left = findNode(root->left, k);
	int right = findNode(root->right, k);

	if(left != -1) {
		traverseDown(root->right, left + 2);
		return left + 1;
	}

	if(right != -1) {
		traverseDown(root->left, right + 2);
		return right + 1;
	}
	return -1;
}

void traverseDown(BNode *root, int level) {
	if(!root) return;
	if(!root->left && !root->right) {
		if(level < min_Dist) {
			min_Dist = level;
			min_val = root->data;
		}
	}
	traverseDown(root->left, level + 1);
	traverseDown(root->right, level + 1);
}
/*
int main() {
    BNode* root = new BNode(4);
    root->left = new BNode(2);
    root->left->left = new BNode(1);
    root->left->right = new BNode(3);
    root->right = new BNode(5);

    cout << findClosestLeaf(root, 2) << endl;

    delete root;
	return 0;
} */
