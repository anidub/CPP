#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

class ListNode {
public:
	int value;
	ListNode *next;

	ListNode(int value) {
		this->value = value;
		this->next = nullptr;
	}
};
/*
 * https://www.educative.io/courses/grokking-the-coding-interview/N7rwVyAZl6D
 * https://www.geeksforgeeks.org/find-length-of-loop-in-linked-list/
 *
 */
int getCycleLength(ListNode *slow);
//TC:O(N)
int findCycleLength(ListNode *head) {
	if(head == nullptr) return 0;
	ListNode *slow = head;
	ListNode *fast = head;

	while(fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) return getCycleLength(slow);
	}
	return 0;
}

int getCycleLength(ListNode *slow) {
	ListNode *current = slow;
	int cycleLength = 1;

	while(current->next != slow) {
		current = current->next;
		cycleLength++;
	}
	return cycleLength;
}
/*
int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle length: " << findCycleLength(head) << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle length: " << findCycleLength(head) << endl;
  delete head;
}*/
