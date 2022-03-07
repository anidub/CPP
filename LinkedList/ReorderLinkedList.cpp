#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/reorder-list/
 * You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 * Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

https://leetcode.com/problems/reorder-list/discuss/613430/C%2B%2B-or-Easy
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head);
ListNode* reverseLnkL(ListNode* head);

ListNode* reorderList(ListNode* head) {
	if(!head) return head;

	ListNode* slow = partition(head);
	ListNode* start = head;
	ListNode* end = slow->next;
	slow->next = NULL;

	end = reverseLnkL(end);

	ListNode* temp1, *temp2;

	while(start && end) {
		temp1 = start->next;
		temp2 = end->next;
		start->next = end;
		end->next = temp1;
		start = temp1;
		end = temp2;
	}
	return head;
}

ListNode* reverseLnkL(ListNode* head) {
	if(!head) return nullptr;

	ListNode *prev = NULL, *cur = head;
	ListNode *nextNode;
	while(cur) {
		nextNode = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nextNode;
	}
	head = prev;
	return head;
}

ListNode* partition(ListNode* head) {
	if(!head) return nullptr;

	ListNode *fast = head;
	ListNode *slow = head;
	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

/*
int main() {
	ListNode* n1 = new ListNode(1); n1->next = new ListNode(2); n1->next->next  = new ListNode(3);
	n1->next->next->next  = new ListNode(4);  n1->next->next->next->next  = new ListNode(5);

	ListNode *result = reorderList(n1);
	ListNode* dummy = result;
	while(dummy)  {
		cout << dummy->val << "-";
		dummy = dummy->next;
	}
	cout << endl;
	delete n1;
	return 0;
}*/
