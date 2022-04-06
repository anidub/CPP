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
/*https://leetcode.com/problems/check-completeness-of-a-binary-tree/
 * Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
https://leetcode.com/problems/check-completeness-of-a-binary-tree/discuss/910868/BFS-%3A-Level-Order-Traversal.-C%2B%2B

//we traverse the tree level wise, whenever we encounter a null value we keep track of that.
//if our first null is last value in binary tree, then our tree is complete binary tree. else not complete binary tree.
 *
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
//Time O(N), Space O(N)
bool isCompleteTree(BNode* root) {
	if(root == nullptr) return true;
	bool nullFound = false;

	queue<BNode*> q;
	q.push(root);

	while(!q.empty()) {
		BNode *p = q.front();
		q.pop();

		if(p == nullptr) nullFound = true;
		else {
			if(nullFound) return false;
			q.push(p->left);
			q.push(p->right);
		}
	}
	return true;
}
/*
int main() {
    BNode* root = new BNode(4);
    root->left = new BNode(2);
    root->left->left = new BNode(1);
    root->left->right = new BNode(3);
    root->right = new BNode(5);

    cout << isCompleteTree(root) << endl;

    delete root;

	return 0;
}*/
