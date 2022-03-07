#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/delete-nodes-and-return-forest/
 * Given the root of a binary tree, each node in the tree has a distinct value.
After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
Return the roots of the trees in the remaining forest. You may return the result in any order.
Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

https://leetcode.com/problems/delete-nodes-and-return-forest/discuss/1170157/Approach-%3A-Simple-BFS-or-C%2B%2B-or-Queue

https://leetcode.com/problems/delete-nodes-and-return-forest/discuss/330647/Recursive-C%2B%2B-Solution : comments
 */
class BNode {
public:
	int data;
	BNode* left;
	BNode* right;

	BNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

vector<BNode*> deleteNodesDFS(BNode* root, vector<int>& to_delete);
BNode* deleteNodesDFSUtil(BNode* root, vector<BNode*>& res, unordered_set<int>& to_delete, bool is_root);
vector<BNode*> deleteNodesBFS(BNode* root, vector<int>& to_delete);

vector<BNode*> deleteNodesDFS(BNode* root, vector<int>& to_delete) {
	if(!root) return {};
	vector<BNode*> result;
	unordered_set<int> s(to_delete.begin(), to_delete.end());
	deleteNodesDFSUtil(root, result, s, true);
}

BNode* deleteNodesDFSUtil(BNode* node, vector<BNode*>& res, unordered_set<int>& to_delete, bool is_root) {
	if(!node) return NULL;
	bool deleted = to_delete.count(node->data);
	if(is_root && !deleted)
		res.push_back(node);

	node->left = deleteNodesDFSUtil(node->left, res, to_delete, deleted);
	node->right = deleteNodesDFSUtil(node->right, res, to_delete, deleted);

	return deleted ? nullptr : node;
}

vector<BNode*> deleteNodesBFS(BNode* root, vector<int>& to_delete) {
	vector<BNode*> result;
	if(!root) return result;

	queue<BNode*> queue;
	queue.push(root);

	unordered_set<int> st(to_delete.begin(), to_delete.end());
	if(!st.count(root->data))
		result.push_back(root);

	while(!queue.empty()) {
		BNode* node = queue.front();
		queue.pop();

		if(node->left) queue.push(node->left);
		if(node->right) queue.push(node->right);

		if(node->left && st.count(node->left->data))
			node->left = NULL;
		if(node->right && st.count(node->right->data))
			node->right = NULL;

		if(st.count(node->data)){
			if(node->left) result.push_back(node->left);
			if(node->right) result.push_back(node->right);
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
	vector<int> to_delete = {3,5};
	deleteNodesBFS(root, to_delete);
	deleteNodesBFS(root, to_delete);

	delete root;
}*/
