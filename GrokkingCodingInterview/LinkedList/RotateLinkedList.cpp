#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;

class ListNode {
public:
	int value;
	ListNode *next;

	ListNode(int value) {
		this->value = value;
		next = nullptr;
	}
};
/*https://www.educative.io/courses/grokking-the-coding-interview/mErolRNQ00R
 * Rotate a LinkedList (medium)#
Given the head of a Singly LinkedList and a number ‘k’, rotate the LinkedList to the right by ‘k’ nodes.

1 2 3 4 5 6
4 5 6 1 2 3
 */

ListNode* rotateLinkedList(ListNode* head, int rotations) {
	if(head == nullptr || head->next == nullptr || rotations <= 0) return head;

	ListNode *lastNode = head;
	int listLength = 1;

	while(lastNode->next != nullptr) {
		lastNode = lastNode->next;
		listLength++;
	}

	lastNode->next = head;
	rotations %= listLength;
	int skipLength = listLength - rotations;

	ListNode *lastNodeRotatedList = head;
	for(int i = 0; i < skipLength - 1; i++) {
		lastNodeRotatedList = lastNodeRotatedList->next;
	}

	head = lastNodeRotatedList->next;
	lastNodeRotatedList->next = nullptr;

	return head;
}

/*
int main() {
	  ListNode *head = new ListNode(1);
	  head->next = new ListNode(2);
	  head->next->next = new ListNode(3);
	  head->next->next->next = new ListNode(4);
	  head->next->next->next->next = new ListNode(5);
	  head->next->next->next->next->next = new ListNode(6);

	  ListNode *result = rotateLinkedList(head, 3);
	  cout << "Nodes of the reversed LinkedList are: ";
	  while (result != nullptr) {
	    cout << result->value << " ";
	    result = result->next;
	  }
}*/
