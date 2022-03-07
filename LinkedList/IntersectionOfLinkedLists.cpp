#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/intersection-of-two-linked-lists/
 * Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return nul
 Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/155040/C%2B%2B-3-Solutions
https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49913/Concise-48ms-C%2B%2B-solution-with-description-and-comment-on-trees
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	if(!headA || !headB) return nullptr;
	ListNode *curA = headA, *curB = headB;

	while(curA != curB) {
		curA = curA ? curA->next : headB;
		curB = curB ? curB->next : headA;
	}
	return curA;
}

ListNode* getIntersectionNodeOther(ListNode* headA, ListNode* headB) {
	ListNode *curA = headA, *curB = headB;
	int countA = 0, countB = 0;

	while(curA) {
		curA = curA->next;
		countA++;
	}

	while(curB) {
		curB = curB->next;
		countB++;
	}

	int diff = std::abs(countA - countB);
	if(countB > countA) {
		swap(headA, headB);
	}
	while(diff--) {
		headA = headA->next;
	}
	while(headA != headB){
		headA = headA->next;
		headB = headB->next;
	}
	return headA;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(3);head->next->next->next = new ListNode(4);
	head->next->next->next->next  = new ListNode(5);

	ListNode *head1 = new ListNode(1);
	head1->next = new ListNode(2);head1->next->next = head->next->next;

	cout << getIntersectionNodeOther(head, head1)->val << endl;
	delete head, head1;

	return 0;
}*/
