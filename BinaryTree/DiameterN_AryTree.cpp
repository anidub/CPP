#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/diameter-of-n-ary-tree/
 * Given a root of an N-ary tree, you need to compute the length of the diameter of the tree.

The diameter of an N-ary tree is the length of the longest path between any two nodes in the tree. This path may or may not pass through the root.

(Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value.)
 *https://leetcode.com/problems/diameter-of-n-ary-tree/discuss/1599202/C%2B%2B-DFS
 */
class N_aryNode {
public:
    int val;
    vector<N_aryNode*> children;

    N_aryNode() {}

    N_aryNode(int _val) {
        val = _val;
    }

    N_aryNode(int _val, vector<N_aryNode*> _children) {
        val = _val;
        children = _children;
    }
};
int diameterN_AryTreeDFS(N_aryNode* currrent, int maxDiameter);

int diameterN_AryTree(N_aryNode* root) {
	if(root == nullptr)  return 0;
	int diameter = 0;
	diameterN_AryTreeDFS(root, diameter);
	return diameter;
}
//TC: O(N), SC; O(N)
int diameterN_AryTreeDFS(N_aryNode* current, int maxDiameter) {
	if(current->children.empty()) return 0;// Base case: Node has no children

	int largestChildPath = 0;// Store the first and second largest child paths (initially 0)
	int secondLargestChildPath = 0;

	for(N_aryNode *child : current->children) {
		int childPath = diameterN_AryTreeDFS(child, maxDiameter) + 1;// Find the child's max path

		if(childPath > largestChildPath) {// Update largest or second largest if appropriate
			secondLargestChildPath = largestChildPath;
			largestChildPath = childPath;
		} else if(childPath > secondLargestChildPath) {
			secondLargestChildPath = childPath;
		}
	}
	maxDiameter = max(maxDiameter, largestChildPath + secondLargestChildPath);// Update the maxDiameter with the sum of the largest and second largest children paths
	return largestChildPath; // Return the largest child path
}
/*
int main() {

	return 0;
}*/
