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
/*https://www.educative.io/courses/grokking-the-coding-interview/N7pvEn86YrN
 *Given the head of a Singly LinkedList that contains a cycle, write a function to find the starting node of the cycle
 */
//TC:O(N), SC:O(1)
ListNode* findCycleStart(ListNode *head) {
	if(head == nullptr) return nullptr;
	ListNode *fast = head;
	ListNode *slow = head;

	while(fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast) break;
	}

	if(fast == nullptr && fast->next == nullptr) return nullptr;

	while(head != slow) {
		head = head->next;
		slow = slow->next;
	}
	return slow;
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
  cout << "LinkedList cycle start: " << findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: " << findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: " << findCycleStart(head)->value << endl;
}*/
