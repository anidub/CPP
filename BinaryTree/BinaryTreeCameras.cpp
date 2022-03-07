#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/binary-tree-cameras/
 * You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
https://leetcode.com/problems/binary-tree-cameras/discuss/214149/C%2B%2B-postorder-with-detailed-explanation
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

BNode* camRoot;
int minCameraCoverPostOrder(BNode* camRoot);

// Time: O(N) Space: O(logN)
int minCameraCover(BNode* root) {
	camRoot = root;
	return minCameraCoverPostOrder(camRoot);
}

int minCameraCoverPostOrder(BNode* root) {
	if(!root) return 0;
	int ans = minCameraCoverPostOrder(root->left) + minCameraCoverPostOrder(root->right);
    int left = root->left ? root->left->data : 1;
    int right = root->right ? root->right->data : 1;

	if(left == 0 || right == 0) {
		root->data = 2;
		return ans+1;
	} else if(left == 2 || right == 2) {
		root->data = 1;
		return ans;
	} else return camRoot == root ? ans + 1 : ans;
}
/*
int main() {

	return 0;
}*/
