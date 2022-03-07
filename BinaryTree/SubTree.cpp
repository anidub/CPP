#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/subtree-of-another-tree/
https://leetcode.com/problems/subtree-of-another-tree/discuss/102767/c%2B%2B-recursive
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
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

bool isSubTree(BNode*r1, BNode* r2);
bool isSame(BNode* r1, BNode* r2);

//Time worst-case complexity of above solution is O(mn) where m and n are number of nodes in given two trees.
bool isSubtree(BNode* s, BNode* t) {

    if(!s) return false;
    if (isSame(s,t)) return true;

    return isSubtree(s->left,t) || isSubtree(s->right,t);

}
bool isSame(BNode *s, BNode *t)
{
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s->data != t->data) return false;

    return isSame(s->left, t->left) && isSame(s->right, t->right);

}
/*
int main() {

	return 0;
}
*/
