#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;
/*https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/37503/C%2B%2B-IterativeRecursive
 */
class BNodeNext{
public:
	int data;
	BNodeNext* next;
	BNodeNext *left;
	BNodeNext *right;

	BNodeNext(int data) {
		this->data = data;
		this->next = NULL;
		this->left = NULL;
		this->right = NULL;
	}
};

//TC: O(n) Space:O(1)
BNodeNext* connectNextNodesIterative(BNodeNext* root) {
	if(!root) return NULL;
    BNodeNext* pre = root; BNodeNext* cur;
    while(pre) {
    	cur = pre;
    	while(cur && cur->left) {
    		cur->left->next = cur->right;
    		if(cur->next)
    			cur->right->next = cur->next->left;
    		cur = cur->next;
    	}
    	pre = pre->left;
    }
    return root;
}

//TC: O(n) Space:O(1)
BNodeNext* connectNextNodesRecursive(BNodeNext* root) {
	if(!root) return NULL;

	if(root->left) {
		root->left->next = root->right;
		if(root->next)
			root->right->next = root->next->left;
		connectNextNodesRecursive(root->left);
		connectNextNodesRecursive(root->right);
	}
	return root;
}
/*
int main() {

	return 0;
}*/
