#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class LowestCommonAncestor {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* cur = root;

		while(cur != nullptr) {
			if(p->val > cur->val && q->val > cur->val)
				cur = cur->right;
			else if(p->val < cur->val && q->val < cur->val)
				cur = cur->left;
			else
				return cur;
		}
		return nullptr;
	}
};

