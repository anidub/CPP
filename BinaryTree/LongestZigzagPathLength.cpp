#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
 * You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/discuss/1159847/C%2B%2B-EASY-oror-Simple-Traversal
https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/discuss/534418/JavaC%2B%2B-DFS-Solution-with-comment-O(N)-Clean-code
State of Node A:

l : max zigag length where A is reached by moving left from parent
r : max zigag length where A is reached by moving right from parent
Usually, one of them is always 0, bec at a time only one type of pattern exists either R->L or L->R so other becomes 0.
At a node if we reached it by moving LEFT from parent then its params would be(l=0,r=XYZ). We need to go RIGHT from there to continue current pattern so now we send the l=r+1. Similarly when reached A by RIGHT move.
** Basically we should move in LEFT if l>0 OR RIGHT if r>0 for pattern to continue, and send in r=prevL+1 OR l=prevR+1 respectively telling next recursion what pattern to continue.
l>0 : tells last pattern formed has moved RIGHT to reach current node, thus we should move LEFT for continuing pattern.
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
//Time: O(n), it will visit all the nodes and each node once.Space: O(h)
int zigzagLength(BNode *root, bool left, int& ans);
int longestZigZagLenth(BNode *root) {
	if(root == nullptr) return 0;
	int ans = 0;
	zigzagLength(root, false, ans);
	return ans;
}

int zigzagLength(BNode *root, bool left, int& ans){
	if(!root) return -1;
	int l = zigzagLength(root->left, false, ans);
	int r = zigzagLength(root->right, true, ans);

	ans = max(ans, max(l + 1, r + 1));

	return l ? l + 1 : r + 1;
}
/*
int main() {

	return 0;
}*/
