#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
 *You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
check if by reference required or swap by values

https://leetcode.com/problems/swapping-nodes-in-a-linked-list/discuss/1261813/Java-(2ms)-Swapping-Node-References : ref
https://leetcode.com/problems/swapping-nodes-in-a-linked-list/solution/
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
 * Swapping by reference
 *
 */

void swapNodesUtilRef(ListNode* p1, ListNode* p2);

ListNode* swapNodes(ListNode* head, int k) {
	if(!head || !head->next) return head;

	ListNode *dummyHead = new ListNode(-1);
	dummyHead->next = head;
	ListNode *p1 = dummyHead;
	for(int i = 1; i < k; i++)
		p1 = p1->next;

	ListNode *p2 = dummyHead;
	ListNode *dummy = p1->next;

	while(dummy->next != nullptr) {
		p2 = p2->next;
		dummy = dummy->next;
	}

	if(p1->next != p2->next)
		swapNodesUtilRef(p1, p2);

	head = dummyHead->next;
	delete dummyHead, dummy;
	return head;
}

void swapNodesUtilRef(ListNode *p1, ListNode *p2) {
	ListNode *p1Target = p1->next;
	ListNode *p2Target = p2->next;

	p1->next = p2Target;
	p2->next = p1Target;

	ListNode* tmp = p2Target->next;
	p2Target->next = p1Target->next;
	p1Target->next = tmp;
}

ListNode* swapNodesByValue(ListNode* head, int k) {
	if(!head || !head->next) return head;

	ListNode *front = nullptr;
	ListNode *end = nullptr;
	ListNode *cur = head;
	int len = 0;

	while(cur) {
		len++;
		if(end != nullptr)
			end = end->next;
		if(len == k) {
			front = cur;
			end = head;
		}
		cur = cur->next;
	}
	swap(front->val, end->val);
	return head;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(9);head->next->next->next = new ListNode(3);
	head->next->next->next->next  = new ListNode(1);

	ListNode *result = swapNodes(head, 2);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
	delete head, result, cur;
	return 0;
}*/
