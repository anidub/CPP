#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
 * Share
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/discuss/360973/C%2B%2B-track-level-sum : comments
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
//TC: O(N), Space: O(n) to process all nodes in the level. . The max number of nodes on one level is (N + 1)/2, in the case of perfect tree.
int maxLevelSumBTree(BNode* root) {
	if(root == nullptr) return -1;

	queue<BNode*> q; q.push(root);
	int level = 1, sum = root->data, cur_level = 1;

	while(!q.empty()) {
		int sz = q.size(), cur_sum = 0;
		for(int i = 0; i < sz; i++) {
			BNode *tmp = q.front(); q.pop();
			cur_sum += tmp->data;
			if(tmp->left != nullptr) q.push(tmp->left);
			if(tmp->right != nullptr) q.push(tmp->right);
		}
		if(cur_sum > sum) {
			sum = cur_sum;
			level = cur_level;
		}
		cur_level++;
	}
	return level;
}
/*
int main () {
	BNode* root = new BNode(1);
    root->left = new BNode(2);
    root->right = new BNode(3);
    root->left->left = new BNode(4);
    root->left->right = new BNode(5);
    root->right->left = new BNode(6);
    root->right->right = new BNode(7);

    cout << maxLevelSumBTree(root) << endl;

	delete root;
	return 0;
}
*/
