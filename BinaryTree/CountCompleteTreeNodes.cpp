#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <math.h>       /* pow */

using namespace std;
/*https://leetcode.com/problems/count-complete-tree-nodes/
 *Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree,
 and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
Input: root = [1,2,3,4,5,6]
Output: 6

https://leetcode.com/problems/count-complete-tree-nodes/discuss/62026/O(logN*logN)-C%2B%2B-implementation

https://leetcode.com/problems/count-complete-tree-nodes/discuss/619064/C%2B%2B-or-Easy-approach
https://leetcode.com/problems/count-complete-tree-nodes/discuss/404932/Easy-to-understand-C%2B%2B-Solution-using-BFS-20ms-beats-99
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

int countCompleteTreeNodes(BNode* root) {
	if(!root) return 0;

	BNode* left = root; BNode* right = root;
	int left_height = 0; int right_height = 0;

	while(left) {
		left_height++;
		left = left->left;
	}
	while(right) {
		right_height++;
		right = right->right;
	}
	if(left_height == right_height) return pow(2, left_height) - 1;
	return 1 + countCompleteTreeNodes(root->left) + countCompleteTreeNodes(root->right);
}

int countNodes(BNode* root) {
	if(!root) return 0;
	if (!root->left && !root->right) return 1;
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int countNodesBFS(BNode* root) {
	if(!root) return 0;
	queue<BNode*> q;
	q.push(root);
	int count = 0;

	while(!q.empty()) {
		int n = q.size();
		count += n;
		while(n--) {
			BNode* node = q.front(); q.pop();
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
	}
	return count;
}
/*
int main() {
    BNode* root = new BNode(1);
  	root->left =  new BNode(2);
 	root->right =  new BNode(3);
    root->left->left =  new BNode(4);
    root->left->right =  new BNode(5);
    root->right->left =  new BNode(6);

    cout << countNodes(root) << endl;
    cout << countNodesBFS(root) << endl;
    cout << countCompleteTreeNodes(root) << endl;

    delete root;
	return 0;
}*/
