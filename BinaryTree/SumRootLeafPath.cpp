#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;
/*https://leetcode.com/problems/path-sum-ii/
 * Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths
 *  where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
https://leetcode.com/problems/path-sum-ii/discuss/36685/12ms-11-lines-C%2B%2B-Solution

https://leetcode.com/problems/path-sum-ii/discuss/180804/Simple-BFS-solution-in-C%2B%2B : iterative : get<x> : get values from tuple
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

void findPathSumUtil(BNode* root, int sum, vector<vector<int>>& paths, vector<int>& path);
//TC:O(N^2), SC:O(N) SC is O (n) because output space is not counted
vector<vector<int>> findPathSum(BNode* root, int targetSum) {
	if(!root) return {};
	vector<vector<int>> paths;
	vector<int> path;
	findPathSumUtil(root, targetSum, paths, path);
	return paths;
}

void findPathSumUtil(BNode* node, int sum, vector<vector<int>>& paths, vector<int>& path) {
	if(!node) return;

	path.push_back(node->data);

	if(!(node->left) && !(node->right) && sum == node->data)
		paths.push_back(path);

	findPathSumUtil(node->left, sum - node->data, paths, path);
	findPathSumUtil(node->right, sum - node->data, paths, path);

	path.pop_back();
}

vector<vector<int>> pathSumIterative(BNode* root, int sum) {
	if (!root) return vector<vector<int>>{};
	vector<vector<int>> rc;
	queue<tuple<BNode*, vector<int>, int> > q;
	q.push({ root, vector<int>{}, sum });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		BNode *&curNode = get<0>(cur);
		get<1>(cur).push_back(curNode->data);
		if (curNode->data == get<2>(cur) && !curNode->left && !curNode->right)
			rc.push_back(get<1>(cur));
		if (curNode->left) q.push({ curNode->left, get<1>(cur), get<2>(cur) - curNode->data });
		if (curNode->right) q.push({ curNode->right, get<1>(cur), get<2>(cur) - curNode->data });
	}
	return rc;
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
    root->right->right = new BNode(25);

    findPathSum(root, 67);
    delete root;

	return 0;
}
*/
