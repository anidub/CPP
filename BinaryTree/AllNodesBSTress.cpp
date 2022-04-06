#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/all-elements-in-two-binary-search-trees/discuss/1719941/C%2B%2B-oror-Best-Explanation-oror-Naive-and-Optimal
 * Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.
 * Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
https://leetcode.com/problems/all-elements-in-two-binary-search-trees/discuss/1719941/C%2B%2B-oror-Best-Explanation-oror-Naive-and-Optimal
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//Time Complexity : O(N + M), N and M are tree size
//Space Complexity : O(N + M): size of vector (tree1 + tree2)

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
	vector<int> result;
	stack<TreeNode*> s1, s2;

	while(root1 || root2 || !s1.empty() || !s2.empty()) {
		while(root1 != nullptr) {
			s1.push(root1);
			root1 = root1->left;
		}
		while(root2 != nullptr) {
			s2.push(root2);
			root2 = root2->left;
		}

		if(s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val) ) {
			root1 = s1.top();s1.pop();
			result.push_back(root1->val);
			root1 = root1->right;
		} else {
			root2 = s2.top(); s2.pop();
			result.push_back(root2->val);
			root2 = root2->right;
		}
	}
	return result;
}
/*
int main() {

	return 0;
}*/
