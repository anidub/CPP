#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/largest-bst-subtree/
 * Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.
 * Input: root = [10,5,15,1,8,null,7]
Output: 3
Explanation: The Largest BST Subtree in this case is the highlighted one. The return value is the subtree's size, which is 3.
https://leetcode.com/problems/largest-bst-subtree/discuss/78892/12ms-C%2B%2B-solution
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

bool isBSTsubtree(BNode* node, int& res, int& mini, int& maxi);
//TC: O(N) , SC: O(N)
int largestBSTsubtree(BNode* root) {
	int res = 0;
	int mini, maxi;
	bool b = isBSTsubtree(root, res, mini, maxi);
	return res;
}

bool isBSTsubtree(BNode* node, int& res, int& mini, int& maxi) {
	if(!node) return true;

	int left_size = 0, right_size = 0;
	int left_mini, left_maxi, right_mini, right_maxi;

	bool leftB = isBSTsubtree(node->left, left_size, left_mini, left_maxi);
	bool rightB = isBSTsubtree(node->right, right_size, right_mini, right_maxi);

	if(leftB && rightB) {
		if( (!node->left || node->data > left_maxi) && (!node->right || node->data < right_mini) ) {
			res = left_size + right_size + 1;
			mini = node->left ? left_mini : node->data;
			maxi = node->right ? right_maxi : node->data;
			return true;
		}
	}
	res = max(left_size, right_size);
	return false;
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

    cout << largestBSTsubtree(root) << endl;
    delete root;

	return 0;
}*/
