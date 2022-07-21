#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Input: root = [3,9,20,null,null,15,7]
Output: 3

https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/1769344/Java-C%2B%2B-Easy-to-go-Explanation-and-Solution : recursion
https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/1504208/Maximum-Depth-of-Binary-Tree-C%2B%2B-or-Recursive-and-Iterative-Solution
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class MaxDepth {
public:
	//TC:O(N), SC:O(N) when unbalaced tree but avg : O(log(N))
	int maxDepth(TreeNode* root) {
		if(root == nullptr) return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);

		return 1 + max(left, right);
	}

	//TC:O(N), SC:O(N) when unbalaced tree but avg : O(log(N))
	int maxDepthIterative(TreeNode* root) {
		if(root == nullptr) return 0;
		queue<TreeNode*> q; q.push(root);
		int depth = 0;

		while(!q.empty()) {
			depth++;
			int sz = q.size();
			for(int i = 0; i < sz; i++) {
				TreeNode* cur = q.front(); q.pop();
				if(cur->left) q.push(cur->left);
				if(cur->right) q.push(cur->right);
			}
		}
		return depth;
	}
};
/*
int main() {
	MaxDepth md;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->right = new TreeNode(7);
	root->right->left = new TreeNode(15);

	cout << md.maxDepth(root) << endl;
	cout << md.maxDepthIterative(root) << endl;

}
*/
