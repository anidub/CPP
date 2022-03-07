#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/discuss/1019050/C%2B%2B-Iterative-and-Recursivs-Approach
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
//Time: O(N)
BNode* convertArrayToBST(vector<int>& nums, int start, int end) {
	if(start > end) return NULL;
	int mid = start + (end-start)/2;
	int midVal = nums[mid];

	BNode* root = new BNode(midVal);
	root->left = convertArrayToBST(nums, start, mid-1);
	root->right = convertArrayToBST(nums, mid+1, end);
	return root;
}
//Time: O(N)
BNode* convertArrayToBSTIterative(vector<int>& nums) {
	if(nums.empty()) return NULL;

	int left, right, mid;
	left = 0;
	right = nums.size() - 1;
	mid = left + (right - left)/2;

	BNode* root = new BNode(nums[mid]);
	queue<tuple<BNode*, int, int, bool>> q;
	q.push(make_tuple(root, left, mid-1, true));
	q.push(make_tuple(root, mid+1, right, false));

	while(!q.empty()) {
		auto [parent, l, r, isLeftChild] = q.front();
		q.pop();

		if(l > r) continue;
		mid = l + (r - l)/2;
		BNode* temp = new BNode(nums[mid]);
		if(isLeftChild)
			parent->left = temp;
		else
			parent->right = temp;

		q.push((make_tuple(temp, l, mid-1, true)));
		q.push(make_tuple(temp, mid+1, r, false));
	}
	return root;
}

void preOrder(BNode* node){
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void BSTtoArray(BNode* root, int a[]) {
	static int pos = 0;
	if(root) {
		BSTtoArray(root->left, a);
		a[pos++] = root->data;
		BSTtoArray(root->right, a);
	}
}

int getTreeSize(BNode* root) {
	if(root == NULL) return 0;
	else
		return getTreeSize(root->left) + 1 + getTreeSize(root->right);
}
/*
int main() {
	vector<int> nums = {-10,-3,0,5,9};
	BNode* root = convertArrayToBST(nums, 0, nums.size() - 1);
	preOrder(root);
	cout << endl;
	root = convertArrayToBSTIterative(nums);
	preOrder(root);
	cout << endl;
	int size = getTreeSize(root);
	cout << size;
	//int* a = new int[size];
	int* array = new int[size];
	//std::array<int, 5> newarr; another way of initialize array. size:  myints.size() or in bytes: sizeof(myints)
	BSTtoArray(root, array);

	delete root;

	return 0;
}*/


