#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/remove-linked-list-elements/
 * Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
 *Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

https://leetcode.com/problems/remove-linked-list-elements/discuss/722528/C%2B%2B-2-solutions%3A-With-single-pointer-%2B-With-double-pointers-(Easy-to-understand) : comments
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteNode(ListNode* head, int val) {
	if(head == nullptr) return head;
	ListNode *delNode;

	while(head && head->val == val) {
		delNode = head;
		head = head->next;
		delete delNode;
	}

	ListNode *cur = head;
	while(cur && cur->next) {
		if(cur->next->val == val) {
			delNode = cur->next;
			cur->next = cur->next->next;
			delete delNode;
		} else
			cur = cur->next;
	}
	return head;
}
/*
int main() {
	ListNode *l1 = new ListNode(7);
	l1->next = new ListNode(2);l1->next->next = new ListNode(4);l1->next->next->next = new ListNode(3);


	ListNode *result = deleteNode(l1, 4);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
	delete l1;
}*/
