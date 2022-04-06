#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
 * Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root. The boundary includes left boundary, leaves,
 * and right boundary in order without duplicate nodes. (The values of the nodes may still be duplicates.)
 *
 * https://www.programmerall.com/article/3114249653/ : soln
 *
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

vector<int> boundaryTraversalOfTree(BNode* root);
void leftBoundary(BNode* root, vector<int>& result);
void addLeaves(BNode* root, vector<int>& result);
void rightBoundary(BNode* root, vector<int>& result);

vector<int> boundaryTraversalOfTree(BNode* root) {
	vector<int> result;
	if(!root) return result;

	if(root->left || root->right) result.push_back(root->data);
	leftBoundary(root->left, result);
	addLeaves(root, result);
	rightBoundary(root->right, result);
	return result;
}

void leftBoundary(BNode* node, vector<int>& result) {
	if(!node || (!node->left && !node->right)) return;
	result.push_back(node->data);
	if(node->left) leftBoundary(node->left, result);
	else leftBoundary(node->right, result);
}

void rightBoundary(BNode* node, vector<int>& result) {
	if(!node || (!node->left && !node->right)) return;
	if(node->right) rightBoundary(node->right, result);
	else rightBoundary(node->left, result);
	result.push_back(node->data);
}

void addLeaves(BNode* node, vector<int>& result) {
	if(!node) return;
	if(!node->left && !node->right)
		result.push_back(node->data);
	addLeaves(node->left, result);
	addLeaves(node->right, result);
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
	vector<int> result = boundaryTraversalOfTree(root);
	for(int& i : result)
		cout << i << " ";

	delete root;

	return 0;
}
*/
