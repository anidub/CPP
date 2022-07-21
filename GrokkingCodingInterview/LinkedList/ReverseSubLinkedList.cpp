#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/qVANqMonoB2
 * Given the head of a LinkedList and two positions ‘p’ and ‘q’, reverse the LinkedList from position ‘p’ to ‘q’.
 *
 * 1 - 2 -3 - 4 - 5
 * Nodes of the reversed LinkedList are: 1 5 4 3 2
 */
/*
 * Similar Questions#
Problem 1: Reverse the first ‘k’ elements of a given LinkedList.

Solution: This problem can be easily converted to our parent problem; to reverse the first ‘k’ nodes of the list, we need to pass p=1 and q=k.

Problem 2: Given a LinkedList with ‘n’ nodes, reverse it based on its size in the following way:

If ‘n’ is even, reverse the list in a group of n/2 nodes.
If n is odd, keep the middle node as it is, reverse the first ‘n/2’ nodes and reverse the last ‘n/2’ nodes.
Solution: When ‘n’ is even we can perform the following steps:

Reverse first ‘n/2’ nodes: head = reverse(head, 1, n/2)
Reverse last ‘n/2’ nodes: head = reverse(head, n/2 + 1, n)
When ‘n’ is odd, our algorithm will look like:

head = reverse(head, 1, n/2)
head = reverse(head, n/2 + 2, n)
Please note the function call in the second step. We’re skipping two elements as we will be skipping the middle element.
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
//TC:O(N), SC: O (1)
ListNode* reverseSubList(ListNode *head, int p, int q) {
	if(head == nullptr) return head;
	if(p == q) return head;

	int i = 0;
	ListNode *current = head, *previous = nullptr;
	while(current != nullptr && i < p - 1) {
		previous = current;
		current = current->next;
		i++;
	}

	ListNode *lastNodeOfFirstPart = previous;
	ListNode *lastNodeOfSubList = current;

	ListNode *next;
	while(current != nullptr && i < q - p + 1) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	if(lastNodeOfFirstPart != nullptr)
		lastNodeOfFirstPart->next = previous;
	else
		head = previous;

	lastNodeOfSubList->next = current;

	return head;
}
/*
int main() {
	  ListNode *head = new ListNode(1);
	  head->next = new ListNode(2);
	  head->next->next = new ListNode(3);
	  head->next->next->next = new ListNode(4);
	  head->next->next->next->next = new ListNode(5);

	  ListNode *result = reverseSubList(head, 2, 4);
	  cout << "Nodes of the reversed LinkedList are: ";
	  while (result != nullptr) {
	    cout << result->value << " ";
	    result = result->next;
	  }
}*/
