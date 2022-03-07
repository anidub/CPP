#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <deque>
#include <queue>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/binary-tree-level-order-traversal/
 * Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 * https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33753/C%2B%2B-BFS-and-DFS
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

vector<vector<int>> levelOrderStoreBFS(BNode* root) {
	if(root == NULL) return {};
	queue<BNode*> q;
	vector<vector<int>> levels;
	q.push(root);

	while(!q.empty()) {
		levels.push_back({});
		int n = q.size();
		for(int i = 0; i < n; i++) {
			BNode* temp = q.front();
			q.pop();
			levels.back().push_back(temp->data);
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
	return levels;
}
void levelOrderStoreDFSUtil(BNode* root, int l, vector<vector<int>>& levels);
vector<vector<int>> levelOrderStoreDFS(BNode* root);

vector<vector<int>> levelOrderStoreDFS(BNode* root) {
	if(!root) return {};
	vector<vector<int>> levels;
	levelOrderStoreDFSUtil(root, 0, levels);
	return levels;
}

void levelOrderStoreDFSUtil(BNode* root, int l, vector<vector<int>>& levels) {
	if(!root) return;
	if(levels.size() <= l)
		levels.push_back({});
	levels[l].push_back(root->data);
	levelOrderStoreDFSUtil(root->left, l+1, levels);
	levelOrderStoreDFSUtil(root->right, l+1, levels);
}
/*
int main() {
	BNode* root = new BNode(15);
	root->left = new BNode(10);
	root->right = new BNode(20);
	root->right->left = new BNode(16);
	root->right->right = new BNode(25);

	delete root;

	return 0;
}
*/
