#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 * Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
You may only use constant extra space.
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
 The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.


It's a BFS traversal. now pointer is the current level traveler and head is the left most element at next level and the tail is the right most element at next level till now. We move now pointer at current level and populate the the next-link at its children level.
 (Here the gist is we can move now to its next because this relationship was already populated in the previous round).

 https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/38015/Simple-40ms-c%2B%2B-o(n)-o(1)-solution-with-only-one-while-loop
 */
class TreeLinkNode{
public:
	int data;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;

	TreeLinkNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->next = NULL;
	}
};

//TC:O(N), SC: O(1)
TreeLinkNode* connect(TreeLinkNode* root) {
	if(!root) return NULL;
	TreeLinkNode *cur, *head, *tail;
	cur = root;
	head = tail = NULL;

	while(cur) {
		if(cur->left) {
			if(tail) tail = tail->next = cur->left;
			else head = tail = cur->left;
		}
		if(cur->right) {
			if(tail) tail = tail->next = cur->right;
			else head = tail = cur->right;
		}
		if(!(cur = cur->next)) {
			cur = head;
			head = tail = NULL;
		}
	}
	return root;
}

/*
int main() {
	TreeLinkNode* root = new TreeLinkNode(1);

	return 0;
}
*/
