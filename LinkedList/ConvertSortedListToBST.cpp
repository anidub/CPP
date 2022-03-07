#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/discuss/1193992/C%2B%2B-Super-Simple-and-Short-Recursive-Solution
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*Time complexity: O(n log(n)).There are log(n) recursive levels because each time we split it to half, and in each level we loop through the whole list, divided into small parts.
Space complexity: O(log(n)). We don't consider the returning tree as extra space, but we have log(n) recursive calls on stack.

 */
TreeNode* sortedListToBST(ListNode *head, ListNode *tail = NULL) {
	if(head == tail) return NULL;

	ListNode *fast = head; ListNode *slow = head;
	while(fast != tail && fast->next != tail) {
		fast = fast->next->next;
		slow = slow->next;
	}
	TreeNode* root = new TreeNode(slow->val);
	root->left = sortedListToBST(head, slow);
	root->right = sortedListToBST(slow->next, tail);
	return root;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(9);head->next->next->next = new ListNode(3);
	head->next->next->next->next  = new ListNode(1);

	TreeNode *root = sortedListToBST(head);

	delete head, root;
	return 0;
}*/
