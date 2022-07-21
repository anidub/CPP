#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class LevelOrderTraversal {
public:
	//TC:O(N), SC:O(N)
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if(root == nullptr) return result;
		queue<TreeNode*> q; q.push(root);

		while(!q.empty()) {
			int sz = q.size();
			result.push_back({});
			for(int i = 0; i < sz; i++) {
				TreeNode* node = q.front(); q.pop();
				result.back().push_back(node->val);
				if(node->left) q.push(node->left);
				if(node->right) q.push(node->right);
			}
		}
		return result;

	}
};
/*
int main() {
	LevelOrderTraversal btmps;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->right = new TreeNode(7);
	root->right->left = new TreeNode(15);
	btmps.levelOrder(root);
}
*/
