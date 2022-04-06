#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

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
/*https://leetcode.com/problems/maximum-average-subtree/
 * Given the root of a binary tree, return the maximum average value of a subtree of that tree. Answers within 10-5 of the actual answer will be accepted.

A subtree of a tree is any node of that tree plus all its descendants.

The average value of a tree is the sum of its values, divided by the number of nodes.
Input: root = [5,6,1]
Output: 6.00000
Explanation:
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.

https://leetcode.com/problems/maximum-average-subtree/discuss/371653/C%2B%2B-Bottom-up
 */
pair<double, int> maximumAverageSubtreeHelper(BNode* root, double &maxm);
/*Time complexity : O(N), where N is the number of nodes in the tree.
This is because we visit each and every node only once, as we do in postorder traversal.
Space complexity : O(N)O(N), because we will create NN states for each of the nodes in the tree.
Also, in cases where we have a skewed tree, we will implicitly maintain a recursion stack of size N,
hence space complexity from this will also be O(N)
*/
double maximumAverageSubtree(BNode* root) {
	double result = 0;
	maximumAverageSubtreeHelper(root, result);
	return result;
}

pair<double, int> maximumAverageSubtreeHelper(BNode* root, double &maxm) {
	if(!root) return {0, 0};

	pair<double, int> sum; //double is for sum, int is for count;

	auto left = maximumAverageSubtreeHelper(root->left, maxm);
	auto right = maximumAverageSubtreeHelper(root->right, maxm);

	sum.first = root->data + left.first + right.first;
	sum.second = 1 + left.second + right.second;

	auto res = sum.first / sum.second;
	maxm = max(maxm, res);
	return sum;
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

    cout << maximumAverageSubtree(root) << endl;;
    delete root;
	return 0;
}*/
