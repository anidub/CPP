#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/insertion-sort-list/
 * Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
 * The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.

Input: head = [4,2,1,3]
Output: [1,2,3,4]
https://leetcode.com/problems/insertion-sort-list/discuss/46422/My-C%2B%2B-solution

https://leetcode.com/problems/insertion-sort-list/discuss/46571/C%2B%2B-recursive-insertion-sort.
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertionSort(ListNode* head) {
	if(!head || !head->next) return head;

	ListNode *p = head->next;
	head->next = NULL;

	while(p != NULL) {
		ListNode* pNext = p->next;
		ListNode* q = head;

		if(p->val < q->val) {
			p->next = q;
			head = p;
		} else {
			while(q != NULL && q->next != NULL && q->next->val <= p->val)
				q = q->next;

			p->next = q->next;
			q->next = p;
		}
		p = pNext;
	}
	return head;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(9);head->next->next->next = new ListNode(3);
	head->next->next->next->next  = new ListNode(1);

	ListNode *result = insertionSort(head);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
	delete head, result, cur;
	return 0;
}*/
