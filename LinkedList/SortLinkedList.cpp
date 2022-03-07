#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/sort-list/
 * Given the head of a linked list, return the list after sorting it in ascending order
 * Input: head = [4,2,1,3]
Output: [1,2,3,4]

https://leetcode.com/problems/sort-list/discuss/46877/C%2B%2B-merge-sort-solution.
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* merge(ListNode *left, ListNode *right);
ListNode* sortLinkedList(ListNode* head) {
	if(!head || !head->next) return head;
	ListNode *fast = head->next;
	ListNode *slow = head;

	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode *r = sortLinkedList(slow->next);
	slow->next = NULL;
	ListNode *l = sortLinkedList(head);
	return merge(l, r);
}

ListNode* merge(ListNode *left, ListNode *right) {
	ListNode* dummy = new ListNode(0), *node;
	node = dummy;
	while(left && right) {
		if(left->val < right->val) {
			node->next = left;
			left = left->next;
		} else {
			node->next = right;
			right = right->next;
		}
		node = node->next;
	}
	if(left) node->next = left;
	else node->next = right;
	return dummy->next;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(9);head->next->next->next = new ListNode(4);
	head->next->next->next->next  = new ListNode(5);

	ListNode *result = sortLinkedList(head);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
	delete head, result, cur;

	return 0;
}
*/
