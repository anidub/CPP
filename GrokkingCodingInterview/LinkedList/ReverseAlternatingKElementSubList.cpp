#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/m2YYJJRP9KG
 * Reverse alternating K-element Sub-list (medium)#
Given the head of a LinkedList and a number ‘k’, reverse every alternating ‘k’ sized sub-list starting from the head.

If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.
https://www.educative.io/courses/grokking-the-coding-interview/q2lZKgLm980

1 2 3 4 5 6 7 8
2 1 3 4 6 5 8 7
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

//TC:O(N), SC: O(1)
ListNode *reverseAlternatingKElement(ListNode *head, int k) {
	if(k <= 1 || head == nullptr) return head;

	ListNode* previous = nullptr, *current = head;

	while(current != nullptr) {
		ListNode *lastNodeOfPrevious = previous;
		ListNode *lastNodeOfSub = current; //current batch

		ListNode *next = nullptr;
		for(int i = 0; i < k && current != nullptr; i++) {
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}

		if(lastNodeOfPrevious != nullptr)
			lastNodeOfPrevious->next = previous;
		else
			head = previous;

		lastNodeOfSub->next = current;

		for(int i = 0; i < k && current != nullptr; i++) {
			previous = current;
			current = current->next;
		}
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

  ListNode *result = reverseAlternatingKElement(head, 2);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}*/
