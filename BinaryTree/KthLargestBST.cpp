#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <deque>
#include <queue>
#include <vector>

using namespace std;
/*https://www.geeksforgeeks.org/kth-largest-element-in-bst-when-modification-to-bst-is-not-allowed/
 * K’th Largest Element in BST when modification to BST is not allowed
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

void kthLargest(BNode* root, int k);
void kthLargestUtil(BNode* root, int k, int& c);

void kthLargestUtil(BNode* root, int k, int& c) { // we start with right most since that is the largest elements in bst
	if(root == NULL || c >= k)
		return;

	kthLargestUtil(root->right, k, c);
	c++;
	if(c == k){
		cout << root->data;
		return;
	}
	kthLargestUtil(root->left, k, c);
}

void kthLargest(BNode* root, int k) {
	if(root == NULL) return;

	int c = 0;//count
	kthLargestUtil(root, k, c);
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

	kthLargest(root, 3);

	delete root;

	return 0;
}*/
