#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/sum-root-to-leaf-numbers/
 *You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

https://leetcode.com/problems/sum-root-to-leaf-numbers/discuss/1252790/C%2B%2B-Iterative-and-Recursive-Solution : iterative
https://leetcode.com/problems/sum-root-to-leaf-numbers/discuss/706028/C%2B%2B-or-Two-Solutions : dfs

Time Complexity: O(n), we visit each node exactly once.
Space Complexity:It's better to mention the space complexity as O(N), or better yet as O(H),
where H is the height of tree, which will work for both complete tree (O(H) = O(logN)) and skewed trees (O(H) = O(N)).
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

int sumRootToLeafNumbersDFS(BNode* root, int cur_sum);

int sumRootToLeafNumbers(BNode* root) {
	if(!root) return 0;
	return sumRootToLeafNumbersDFS(root, 0);
}

int sumRootToLeafNumbersDFS(BNode* root, int cur_sum) {
	if(!root) return 0;

	cur_sum = cur_sum * 10 + root->data;
	if(!root->left && !root->right)
		return cur_sum;

	return sumRootToLeafNumbersDFS(root->left, cur_sum) + sumRootToLeafNumbersDFS(root->right, cur_sum);
}

int sumRootToLeafNumbersBFS(BNode* root) {
	if(!root) return 0;

	int result = 0;
	queue<BNode*> q;
	q.push(root);

	while(!q.empty()) {
		BNode* node = q.front(); q.pop();
		if(!node->left && !node->right)
			result += node->data;
		else {
			if(node->left) {
				node->left->data += node->data * 10;
				q.push(node->left);
			}
			if(node->right) {
				node->right->data += node->data * 10;
				q.push(node->right);
			}
		}
	}
	return result;
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

    cout << sumRootToLeafNumbers(root) << endl;
    cout << sumRootToLeafNumbersBFS(root) << endl;
    delete root;

	return 0;
}
*/
