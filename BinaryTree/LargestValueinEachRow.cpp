#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <deque>
#include <queue>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/find-largest-value-in-each-tree-row/
 * Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
 * Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

https://leetcode.com/problems/find-largest-value-in-each-tree-row/discuss/99006/C%2B%2B-Clean-Code-DFS-%3A-PreOrder-and-PostOrder
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

void findLargestValuesPreorder(BNode *node, int row, vector<int> max_values);
//TC:O(N), SC: O(N) due to stack
vector<int> largestValueRows(BNode *root) {
	if(root == nullptr) return {};
	vector<int> max_values;
	findLargestValuesPreorder(root, 0, max_values);
	return max_values;
}

void findLargestValuesPreorder(BNode *node, int row, vector<int> max_values) {
	if(!node) return;

	if(row >= max_values.size())
		max_values.push_back(node->data);
	else
		max_values[row] = max(max_values[row], node->data);

	findLargestValuesPreorder(node->left, row + 1, max_values);
	findLargestValuesPreorder(node->right, row + 1, max_values);
}
/*
int main() {
	BNode* root = new BNode(15);
	root->left = new BNode(10);
	root->right = new BNode(20);
	root->right->left = new BNode(16);
	root->right->right = new BNode(25);

	largestValueRows(root);

	delete root;
	return 0;
}*/
