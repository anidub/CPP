#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
 * You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.
https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/discuss/1614261/c%2B%2B-O(n)-solution-with-clear-code

https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/discuss/1611977/C%2B%2B-Solution.-find-LCA.
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

bool findStepPaths(BNode* root, string& ans, int& targetValue);
//TC: o(N)
string findStepByStepDirections(BNode* root, int startValue, int destValue) {
	if(!root) return "";

	string rStart = "";
	string rDest = "";

	findStepPaths(root, rStart, startValue);
	findStepPaths(root, rDest, destValue);

	// removing the common part
	while(rStart.size() > 0 && rDest.size() > 0 && rStart.back() == rDest.back()) {
		rStart.pop_back();
		rDest.pop_back();
	}

	//replacing rToStart with U
	for(int i = 0; i < rStart.size(); i++)
		rStart[i] = 'U';

	//reversing the rToDest
	reverse(rDest.begin(), rDest.end());

	return rStart + rDest;
}

bool findStepPaths(BNode* root, string& ans, int& targetValue) {
	if(root->data == targetValue) return true;

	if(root->left && findStepPaths(root->left, ans, targetValue)) {
		ans += "L";
		return true;
	}
	if(root->right && findStepPaths(root->right, ans, targetValue)) {
		ans += "R";
		return true;
	}
	return false;
}
//-----------------------------------------Using LCA, may start with this approach, above is easier-------O(N)-------------------------//
BNode* lcaSteps(BNode *root, int startValue, int destValue) {
    if(!root) return NULL;
    if(root->data == startValue) return root;
    if(root->data == destValue) return root;
    auto l = lcaSteps(root->left, startValue, destValue);
    auto r = lcaSteps(root->right, startValue, destValue);
    if(l && r) return root;
    return l ? l : r;
}
bool getPathSteps(BNode *root, int value, string &path) {
    if(!root) return false;
    if(root->data == value) return true;
    path += 'L';
    auto res = getPathSteps(root->left, value, path);
    if(res) return true;
    path.pop_back();
    path += 'R';
    res = getPathSteps(root->right, value, path);
    if(res) return true;
    path.pop_back();
    return false;
}
string getDirections(BNode* root, int startValue, int destValue) {
    root = lcaSteps(root, startValue, destValue);
    string p1, p2;
    getPathSteps(root, startValue, p1);
    getPathSteps(root, destValue, p2);
    for(auto &c : p1) c = 'U';
    return p1 + p2;
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

    cout << findStepByStepDirections(root, 8,25) << endl;
    delete root;

	return 0;
}*/
