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

int camAns;
int minCameraCoverPostOrder(BNode* camRoot);

// Time: O(N) Space: O(logN)
int minCameraCover(BNode* root) {
	return minCameraCoverPostOrder(root)  == 0 ? camAns + 1 : camAns;
}

int minCameraCoverPostOrder(BNode* root) {
	if(root == nullptr) return 1;
	int left = minCameraCoverPostOrder(root->left);
	int right = minCameraCoverPostOrder(root->right);

	if(left == 0 || right == 0) {
		camAns++;
		return 2;
	} else return left == 2 || right == 2 ? 1 : 0;
}
/*
int main() {

	return 0;
}*/
