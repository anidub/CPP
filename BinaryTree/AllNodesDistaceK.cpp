#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 *Given the root of a binary tree, the value of a target node target, and an integer k,
 *return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/143775/very-easy-to-understand-c%2B%2B-solution.

TC:O(N), SC:O(N)
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
vector<int> ans;
unordered_map<BNode*, BNode*> parent;
unordered_set<BNode*> visited;


void findParent(BNode* root);
vector<int> distanceKNodes(BNode* root, BNode target, int k);
void distanceKNodesDFS(BNode* root, int k);


void findParent(BNode* root) {
	if(!root) return;
	if(root->left) {
		parent[root->left] = root;
		findParent(root->left);
	}
	if(root->right) {
		parent[root->right] = root;
		findParent(root->right);
	}
}

vector<int> distanceKNodes(BNode* root, BNode* target, int k) {
	if(!root) return ans;
	findParent(root);
	distanceKNodesDFS(root, k);
	return ans;
}

void distanceKNodesDFS(BNode* node, int k) {
	if(visited.find(node) != visited.end())
		return;
	visited.insert(node);
	if(k == 0) {
		ans.push_back(node->data);
		return;
	}

	if(node->left) {
		distanceKNodesDFS(node->left, k-1);
	}

	if(node->right) {
		distanceKNodesDFS(node->right, k-1);
	}
	BNode* p = parent[node];
	if(p)
		distanceKNodesDFS(p, k-1);
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
	BNode* target = new BNode(8);
	 distanceKNodes(root, target, 2);
	//   cout << rangeSumBSTIterative(root, 8, 14) << endl;

	return 0;
}*/
