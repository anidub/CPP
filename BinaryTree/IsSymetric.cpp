#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/symmetric-tree/
 * Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 https://leetcode.com/problems/symmetric-tree/discuss/493499/C%2B%2B-iterative-code.
 https://leetcode.com/problems/symmetric-tree/discuss/33243/C%2B%2B-recursive-solution
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


bool isSymmetricRecursive(BNode* root);
bool isSymmetricRecursiveUtil(BNode* t1, BNode* t2);
bool isSymmetricIterative(BNode* root);

bool isSymmetricRecursive(BNode* root) {
	if(!root) return true;
	return isSymmetricRecursiveUtil(root->left, root->right);
}

bool isSymmetricRecursiveUtil(BNode* t1, BNode* t2) {
	if(t1 == NULL && t2 == NULL) return true;
	if(t1 == NULL || t2 == NULL) return false;

	return t1->data == t2->data && isSymmetricRecursiveUtil(t1->left, t2->right) && isSymmetricRecursiveUtil(t1->right, t2->left);
}

bool isSymmetricIterative(BNode* root) {
	if(!root) return false;
	queue<BNode*> q;
	q.push(root);
	q.push(root);

	while(!q.empty()) {
		BNode* t1 = q.front(); q.pop();
		BNode* t2 = q.front(); q.pop();

		if(t1 == NULL && t2 == NULL) continue;
		if(t1 == NULL || t2 == NULL) return false;
		if(t1->data != t2->data) return false;

		q.push(t1->left); q.push(t2->right);
		q.push(t1->right); q.push(t2->left);
	}
	return true;
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
    cout << isSymmetricRecursive(root) << endl;
    cout << isSymmetricIterative(root) << endl;
    delete root;

	return 0;
}*/
