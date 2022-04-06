#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/average-of-levels-in-binary-tree/
 * Given the root of a binary tree, return the average value of the nodes on each level in the form of an array
 Answers within 10-5 of the actual answer will be accepted.
 * Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

 *https://leetcode.com/problems/average-of-levels-in-binary-tree/discuss/1094405/JS-Python-Java-C%2B%2B-or-Easy-BFS-Solution-w-Explanation
 */

class BNode{
public:
	char val;
	BNode *left;
	BNode *right;

	BNode(char val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};
//TC: O(N) where N is the number of nodes in the given Tree. SC: O(M), where M is the maximum number of nodes at any level in the binary tree.
vector<double> averageOfLevels(BNode* root) {
	if(root == nullptr) return {};
	vector<double> ans;
	queue<BNode*> q;
	q.push(root);

	while(!q.empty()) {
		int sz = q.size(); double row = 0;
		for(int i = 0; i < sz; i++) {
			BNode *cur = q.front(); q.pop();
			row += cur->val;
			if(cur->left) q.push(cur->left);
			if(cur->right) q.push(cur->right);
		}
		ans.push_back(row / sz);
	}
	return ans;
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
	vector<double> result = averageOfLevels(root);
	for(auto & i : result)
		cout << i << " ";

	delete root;
	return 0;
}
*/
