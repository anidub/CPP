#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/merge-two-sorted-lists/
 *You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

https://leetcode.com/problems/merge-two-sorted-lists/discuss/226176/C%2B%2B-iterative-and-recursive

 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoSortedLinkedListsIterative(ListNode *l1, ListNode *l2) {
	ListNode* dummy = new ListNode(INT_MIN), *pre = dummy;

	while(l1 && l2) {
		if(l1->val < l2->val) {
			pre->next = l1;
			l1 = l1->next;
		} else {
			pre->next = l2;
			l2 = l2->next;
		}
		pre = pre->next;
	}
	pre->next = l1 ? l1 : l2;

	return dummy->next;
}

ListNode*  mergeTwoSortedLinkedListsRecursive(ListNode *l1, ListNode *l2) {
	if(!l1 || !l2)
		return l1 ? l1 : l2;

	if(l1->val < l2->val) {
		l1->next = mergeTwoSortedLinkedListsRecursive(l1->next, l2);
		return l1;
	}
	l2->next = mergeTwoSortedLinkedListsRecursive(l1, l2->next);
	return l2;
}

/*
int main() {
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(5);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(7);

	ListNode* result = mergeTwoSortedLinkedListsRecursive(l1, l2);
	ListNode* dummy = result;
	while(dummy)  {
		cout << dummy->val << "-";
		dummy = dummy->next;
	}
	cout << endl;
	delete l1; delete l2;
	return 0;
}
*/
