#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/invert-binary-tree/
 * Given the root of a binary tree, invert the tree, and return its root.
 * Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
 * https://leetcode.com/problems/invert-binary-tree/discuss/62934/C%2B%2B-Recursive-and-Iterative
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


BNode* invertTreeRecursive(BNode* root) {
	if(!root) return NULL;
	swap(root->left, root->right);
	invertTreeRecursive(root->left);
	invertTreeRecursive(root->right);
	return root;
}

BNode* invertTreeIterative(BNode* root) {
	if(!root) return NULL;
	queue<BNode*> q;
	q.push(root);

	while(!q.empty()) {
		BNode* node = q.front();
		q.pop();
		swap(node->left, node->right);
		if(node->left) q.push(node->left);
		if(node->right) q.push(node->right);
	}
	return root;
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
    invertTreeIterative(root);
    invertTreeRecursive(root);

    int a = 1, b = 2;
    swap(a, b);
    cout << "a:" << a << " b:" << b <<endl;
    delete root;

}*/
