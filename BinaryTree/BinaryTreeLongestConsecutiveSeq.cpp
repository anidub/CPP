#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
 * Given the root of a binary tree, return the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
The longest consecutive path needs to be from parent to child
Input: root = [1,null,3,2,4,null,null,null,5]
Output: 3
Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/discuss/74548/C%2B%2B-solution-in-4-lines
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

int searchLongestConsecutiveDFS(BNode* root, BNode* parent, int len);
//TC: O(N), SC: O(N)
int longestConsecutive(BNode* root) {
	if(!root) return 0;
	return searchLongestConsecutiveDFS(root, nullptr, 0);
}

int searchLongestConsecutiveDFS(BNode* root, BNode* parent, int len) {
	if(!root) return len;
	len = (parent && root->data == parent->data + 1) ? len + 1 : 1;
	return max(len, max(searchLongestConsecutiveDFS(root->left, root, len), searchLongestConsecutiveDFS(root->right, root, len)));
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
    cout << longestConsecutive(root) << endl;
    delete root;

	return 0;
}*/
