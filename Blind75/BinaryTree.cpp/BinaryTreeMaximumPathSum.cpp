#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge
 *  connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
https://leetcode.com/problems/binary-tree-maximum-path-sum/solution/
https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/39873/recommend-for-beginnersclean-C%2B%2B-implementation-with-detailed-explanation
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class BinaryTreeMaxPathSum {
public:
	//TC:O(N), SC:O(H)
	int max_sum;
	int maxPathSum(TreeNode* root) {
		max_sum = INT_MIN;
		if(root == nullptr) return max_sum;
		helper(root);
		return max_sum;
	}

private:
	int helper(TreeNode* root) {
		if(root == nullptr) return 0;
		int left = max(0, helper(root->left));
		int right = max(0, helper(root->right));

		max_sum = max(max_sum, left + right + root->val);

		return max(left, right) + root->val;
	}
};

/*
int main() {
	BinaryTreeMaxPathSum btmps;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->right = new TreeNode(7);
	root->right->left = new TreeNode(15);
	cout << btmps.maxPathSum(root) << endl;

}
*/
