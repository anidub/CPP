#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
//https://www.bogotobogo.com/cplusplus/files/BinaryTree.cpp
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
//print-nodes-end-odd-levels-tree
//https://www.geeksforgeeks.org/print-nodes-odd-levels-tree/
void getEvenOddLevelElements(BNode* root) {
	if(root == NULL) return;
	queue<BNode*> q;
	q.push(root);
	bool isOdd = true;
	vector<int> even; vector<int> odd;
	while(true) {
		int size = q.size();
		if(size == 0) break;
		while(size > 0) {
			BNode* node = q.front();
			q.pop();
			if(isOdd)
				odd.push_back(node->data);
			else
				even.push_back(node->data);
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
			size--;
		}
		isOdd = !isOdd;
	}

	for(auto& i : even)
		cout << i << " ";
	cout << endl;
	cout << "now odd" << endl;
	for(auto& j : odd)
		cout << j << " ";
}
//https://leetcode.com/problems/even-odd-tree/discuss/877886/C%2B%2B-Level-order-traversal
//https://leetcode.com/problems/even-odd-tree/
/*A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.
 *
 */
bool isEvenOddTree(BNode* root) {
	if(root == NULL) return false;
	queue<BNode*> q;
	q.push(root);
	int level = 0;
	while(!q.empty()) {
		int count = q.size();
		int prev = level % 2 == 0 ? 0 : INT_MAX;
		while(count--) {
			BNode* node = q.front();
			q.pop();
			if(level % 2 == 0) {
				if(node->data % 2 == 0 || node->data <= prev) return false;
			} else {
				if(node->data % 2 != 0  || node->data >= prev) return false;
			}
			prev = node->data;
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
		++level;
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
	getEvenOddLevelElements(root);
	cout << endl;
	cout << isEvenOddTree(root) << endl;
	delete root;

	return 0;
}*/
