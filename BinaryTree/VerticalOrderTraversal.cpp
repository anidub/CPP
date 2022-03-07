#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>
#include <map>

using namespace std;
/*https://leetcode.com/problems/binary-tree-vertical-order-traversal/
 * Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

https://leetcode.com/problems/binary-tree-vertical-order-traversal/discuss/668240/C%2B%2B-or-DFS
https://leetcode.com/problems/binary-tree-vertical-order-traversal/discuss/76479/My-Solution-in-C%2B%2B : used
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
//time : O(NLOGN)
//space: O(N)
vector<vector<int>> verticalOrderTraversal(BNode* root) {
	vector<vector<int>> output;
	if(!root) return output;

	map<int, vector<int>> map;
	queue<pair<int, BNode*>> q;
	q.push(make_pair(0, root));

	while(!q.empty()) {
		int size = q.size();
		for(int i = 0; i < size; i++) {
			BNode* node = q.front().second;
			int tmp = q.front().first;
			q.pop();
			map[tmp].push_back(node->data);
			if(node->left)
				q.push(make_pair(tmp-1, node->left));
			if(node->right)
				q.push(make_pair(tmp+1, node->right));
		}
	}
	for(auto& v : map)
		output.push_back(v.second);

	return output;
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
	verticalOrderTraversal(root);

	return 0;
}*/
