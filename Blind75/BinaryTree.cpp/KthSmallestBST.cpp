#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 Input: root = [3,1,4,null,2], k = 1
Output: 1
https://leetcode.com/problems/kth-smallest-element-in-a-bst/discuss/1960046/Multiple-C%2B%2B-solutions-with-explanations-and-time-complexity!
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class KthSmallestBST {
public:
	//TC:O(N), SC:O(N)
    vector<int> store;
	int kthSmallestVector(TreeNode* root, int k) {
		if(root == nullptr) return INT_MIN;
		inorder(root);
		int ans = store[k - 1];
		return ans;
    }

	//TC:O(N), SC:O(N)
	int ans;
	int kthSmallestRecursive(TreeNode* root, int k) {
		inorderRecursive(root, k);
		return ans;
	}


private:
	void inorder(TreeNode* root)  {
		if(root == nullptr) return;
		inorder(root->left);
		store.push_back(root->val);
		inorder(root->right);
	}

	void inorderRecursive(TreeNode* root, int &k) {
		if(root == nullptr) return;
		inorderRecursive(root ->left, k);
		k--;
		if(k == 0){
			ans = root->val;
			return;
		}
		inorderRecursive(root->right, k);
	}
};
/*
int main() {
	KthSmallestBST ksb;	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->right = new TreeNode(7);
	root->right->left = new TreeNode(15);
	cout << ksb.kthSmallestVector(root, 1) << endl;
	cout << ksb.kthSmallestRecursive(root, 1) << endl;

}
*/
