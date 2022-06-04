#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/range-sum-of-bst/
 * https://leetcode.com/problems/range-sum-of-bst/discuss/1628229/C%2B%2BPython-Simple-Solution-w-Explanation-or-DFS-%2B-BFS-w-Optimizations-%2B-O(1)-Morris
 Given the root node of a binary search tree and two integers low and high,
  return the sum of values of all nodes with a value in the inclusive range [low, high].
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
//Time Complexity : O(N), more specifically, this solution would only iterate the nodes which lie within the range [L, H]
//Space Complexity : O(H)
int rangeSumBSTRecursive(BNode* root, int L, int H) {
	if(root == NULL) return 0;
	int ans = root->data >= L && root->data <= H ? root->data : 0;
	if(root->data >= L) ans += rangeSumBSTRecursive(root->left, L, H);
	if(root->data <= H) ans += rangeSumBSTRecursive(root->right, L, H);
	return ans;
}
//Time Complexity : O(N)
//Space Complexity : O(W), where W is the width of BST. In case of skewed tree, it will be O(1) and in case of balanced tree it will be O(N/2) ~ O(N)
int rangeSumBSTIterative(BNode* root, int L, int H) {
	if(root == NULL) return 0;
	queue<BNode*> q;
	q.push(root);
	int sum = 0;
	while(!q.empty()) {
		BNode* node = q.front();
		q.pop();
		if(node->data >= L && node->data <= H)
			sum += node->data;
		if(node->data >= L && node->left) q.push(node->left);
		if(node->data <= H && node->right) q.push(node->right);
	}
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
	cout << rangeSumBSTRecursive(root, 8, 14) << endl;
	cout << rangeSumBSTIterative(root, 8, 14) << endl;

	return 0;
}
*/
