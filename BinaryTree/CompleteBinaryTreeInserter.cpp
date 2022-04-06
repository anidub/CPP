#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/complete-binary-tree-inserter/
 * A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.

Implement the CBTInserter class:

CBTInserter(TreeNode root) Initializes the data structure with the root of the complete binary tree.
int insert(int v) Inserts a TreeNode into the tree with value Node.val == val so that the tree remains complete, and returns the value of the parent of the inserted TreeNode.
TreeNode get_root() Returns the root node of the tree.
Input
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
Output
[null, 1, 2, [1, 2, 3, 4]]

Explanation
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // return 1
cBTInserter.insert(4);  // return 2
cBTInserter.get_root(); // return [1, 2, 3, 4]

https://leetcode.com/problems/complete-binary-tree-inserter/discuss/627736/C%2B%2B-Simple-BFS-solution-beats-100-in-memory.-Detailed-Explanation
    Idea is to to BFS and look for the first node that has 0/1 child, and
    make the input value as a new node for that parent.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Insert: TC: O(N), SC: O(1) get: TC: O(1)
class CBTInserter {
	TreeNode *root_;
public:
    CBTInserter(TreeNode* root) {
    	root_ = root;
    }

    int insert(int val) {
    	queue<TreeNode*> q;
    	q.push(root_);
    	TreeNode *cur = nullptr;

    	while(!q.empty()) {
    		cur = q.front(); q.pop();
    		if(!cur->left) {
    			cur->left = new TreeNode(val);
    			break;
    		}
    		if(!cur->right) {
    			cur->right = new TreeNode(val);
    			break;
    		}
    		if(cur->left) q.push(cur->left);
    		if(cur->right) q.push(cur->right);
    	}
    	return cur->val;
    }

    TreeNode* get_root() {
    	return root_;
    }
};
/*
int main() {

	return 0;
}*/
