#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;
/*https://leetcode.com/problems/balance-a-binary-search-tree/
 * Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct
https://leetcode.com/problems/balance-a-binary-search-tree/discuss/1604379/Easy-C%2B%2B-Solution
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

void getInorder(BNode* root, vector<int>& sortedArr);
BNode* getBalanceBST(vector<int>&sortedArr, int low, int high);
//Time & Space: O(n)
BNode* convertBSTtoBalanceBST(BNode* root) {
	if(!root) return NULL;
	vector<int> sortedArr;
	getInorder(root, sortedArr);
	return getBalanceBST(sortedArr, 0, sortedArr.size()-1);
}


void getInorder(BNode* root, vector<int>& sortedArr) {
	if(!root) return;
	getInorder(root->left, sortedArr);
	sortedArr.push_back(root->data);
	getInorder(root->right, sortedArr);
}



BNode* getBalanceBST(vector<int>&sortedArr, int low, int high) {
	if(low <= high) {
		int mid = low + (high - low)/2;
		BNode* node = new BNode(sortedArr[mid]);
		node->left = getBalanceBST(sortedArr, low, mid-1);
		node->right = getBalanceBST(sortedArr, mid+1, high);
		return node;
	}
	return NULL;
}
/*
int main() {
    BNode* root = new BNode(4);
    root->left = new BNode(2);
    root->left->left = new BNode(1);
    root->left->right = new BNode(3);
    root->right = new BNode(5);

    convertBSTtoBalanceBST(root);
    delete root;

	return 0;
}*/
