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
/*https://leetcode.com/problems/kth-largest-element-in-a-stream/
 * Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8

https://leetcode.com/problems/kth-largest-element-in-a-stream/discuss/250678/C%2B%2B-priority_queue
https://leetcode.com/problems/kth-largest-element-in-a-stream/discuss/596093/C%2B%2B-solution-with-understandable-explaination
https://leetcode.com/problems/kth-largest-element-in-a-stream/discuss/386215/C%2B%2B-solution-without-heap-(BST)
 */
class KthLargest {
public:
	KthLargest(int k, vector<int>& nums) {
		this->k = k;
		for(int& i : nums) {
			save(i);
		}
	}

	int add(int val) {
		if(pq.size() < k || pq.top() < val) {
			save(val);
		}
		return pq.top();
	}

private:
	int k;
	priority_queue<int, vector<int>, greater<int>> pq;
	void save(int n) {
		pq.push(n);
		if(pq.size() > k)
			pq.pop();
	}
};

struct CustomNode { // in struct everything is public by default but in class its private
	int val;
	int cnt;// counter for the nodes in subtree
	CustomNode* left;
	CustomNode* right;

	CustomNode(int x) : val(x), cnt(1), left(NULL), right(NULL) {}
};

//Optimal: utilizes BST properties
/* understand using drawing out tree and printing out as in leetcode
 *                  4(5) : this mean 5 is count of 4
 *          2              5(3) : this mean 3 is count of 5
 *             3                8(1)
 *
 *https://leetcode.com/problems/kth-largest-element-in-a-stream/discuss/386215/C%2B%2B-solution-without-heap-(BST)
 */
class KthLargestBST{
private:
	CustomNode* root = NULL;
	int k;
	CustomNode* insert(CustomNode* root, int num) {
		if(root == NULL)
			return new CustomNode(num);
		if(num < root->val)// left subtree
			root->left = insert(root->left, num);
		else// right subtree
			root->right = insert(root->right, num);

		root->cnt++;// increment number of nodes in the tree
		return root;
	}

	int search(CustomNode* root, int k) {
		if(root == NULL) return 0;// this will not be executed with valid input
		int nodes_right = 0;// number of nodes in the right subtree

		if(root->right)
			nodes_right = root->right->cnt;

		// if M nodes in the right subtree, root is M+1 largest
		int rootLargest = nodes_right + 1;

		if(k == rootLargest)
			return root->val;
		else if(k < rootLargest)
			return search(root->right, k);// perform search in right subtree otherwise, remove the right half nodes,
        // and search in the left subtree
		k = k- rootLargest;
		return search(root->left, k);
	}


public:
	KthLargestBST(int k, vector<int>& nums) {
		for(int& i : nums) {
			this->root = this->insert(this->root, i);
		}
		this->k = k;
	}

	int add(int val) {
		this->root = this->insert(this->root, val);
		return search(this->root, this->k);
	}
};
