#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*educative.io/courses/grokking-the-coding-interview/q2lZKgLm980
 * Reverse alternating K-element Sub-list (medium)#
Given the head of a LinkedList and a number ‘k’, reverse every alternating ‘k’ sized sub-list starting from the head.

If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.
1 - 2 -3 -4 -5 -6 -7 -8

3 2 1 6 5 4 8 7

 */
class ListNode {
public:
	int value;
	ListNode *next;

	ListNode(int value) {
		this->value = value;
		next = nullptr;
	}
};
//TC:O(N), SC:O(1)
ListNode* reverseEveryKSubList(ListNode *head, int k) {
	if(head == nullptr) return head;
	if(k == 0) return head;

	ListNode *current = head, *previous = nullptr;

	while(true) {
		ListNode *lastOfNodeOfPreviousPart = previous;
		ListNode* lastNodeOfSubList = current;
		int i = 0;

		ListNode *next = nullptr;
		while(current != nullptr && i < k) {
			i++;
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}

		if(lastOfNodeOfPreviousPart != nullptr) {
			lastOfNodeOfPreviousPart->next = previous;
		} else
			head = previous;

		lastNodeOfSubList->next = current;
		if(current == nullptr)
			break;

		previous = lastNodeOfSubList;
	}
	return head;
}

/*
int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);

  ListNode *result = reverseEveryKSubList(head, 3);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
*/
