#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>
#include <map>

using namespace std;
/*https://leetcode.com/problems/binary-tree-right-side-view/
 * Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
https://leetcode.com/problems/binary-tree-right-side-view/discuss/56241/C%2B%2B-BFSDFS
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

vector<int> rightViewTreeDFS(BNode* root) {
	if(root == NULL) return {};
	vector<int> result;
	queue<BNode*> q;
	q.push(root);

	while(!q.empty()) {
		int n = q.size();
		for(int i = 0; i < n; i++) {
			BNode* node = q.front();
			q.pop();
			if(i == n-1)
				result.push_back(node->data);
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
		}
	}
	return result;
}
vector<int> rightViewTreeBFS(BNode* root);
void rightViewTreeBFSUtil(BNode* root, vector<int>& result, int level);

vector<int> rightViewTreeBFS(BNode* root) {
	if(root == NULL) return {};
	vector<int> result;
	rightViewTreeBFSUtil(root, result, 0);
	return result;
}

void rightViewTreeBFSUtil(BNode* root, vector<int>& result, int level) {
	if(root == NULL) return;
	if(result.size() == level)
		result.push_back(root->data);
	rightViewTreeBFSUtil(root->right, result, level+1);
	rightViewTreeBFSUtil(root->left, result, level+1);
}
/*
int main() {
	BNode* root = new BNode(20);
	root->left = new BNode(8);
	root->left->left = new BNode(4);
	root->left->right = new BNode(12);
	root->left->right->left = new BNode(10);
	root->left->right->right = new BNode(14);
	rightViewTreeDFS(root);

	return 0;
}*/
