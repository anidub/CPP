#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/validate-binary-tree-nodes/
 * You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true

https://leetcode.com/problems/validate-binary-tree-nodes/discuss/517557/C%2B%2B-Find-Root-%2B-DFS : comments; ezpzm9
A tree has a single root node (in-degree = 0) and all other nodes have in-degree = 1. We can use this observation to find the root.
 We can then traverse the tree using that root to check if all nodes have been visited exactly once.
 */
int countNodes(vector<int>& left, vector<int>& right, int root) { // DFS from root to validate that all nodes are visited.
	if(root == -1) return 0;
	return 1 + countNodes(left, right, left[root]) + countNodes(left, right, right[root]);
}

// Time: O(n). Space: O(n).
bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
	vector<int> inDegree(n, 0);

	for(int i = 0; i < n; i++) {
		if(leftChild[i] != -1) inDegree[leftChild[i]]++;
		if(rightChild[i] != -1) inDegree[rightChild[i]]++;
	}
	int root = -1;// Here we check that there is exactly one node with in-degree == 0 (the root) and that all other nodes have in-degree == 1.
	for(int i = 0; i < n; i++) {
		if(inDegree[i] == 0) {
			if(root == -1)
				root = i;
			else
				return false;// Found more than one root. There must be exactly one node with inDegree == 0.
		} else if(inDegree[i] != 1)
			return false;// All nodes except the root must have in-degree == 1.
	}
	if(root == -1) return false;// No root found.
	return countNodes(leftChild, rightChild, root) == n;
}
/*
int main() {
	vector<int> leftChild = {1,-1,3,-1};
	vector<int> rightChild = {2,-1,-1,-1};
	cout << validateBinaryTreeNodes(4, leftChild, rightChild) << endl;

	return 0;
}*/
