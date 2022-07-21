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
/*https://www.educative.io/courses/grokking-the-coding-interview/3j5GD3EQMGM
 *
 */
class ListNode {
public:
	int value;
	ListNode *next;

	ListNode(int value) {
		this->value = value;
		this->next = nullptr;
	}
};
//TC:O(N), SC:O(1)
ListNode* findMiddleLinkedList(ListNode *head) {
	if(head == nullptr) return nullptr;
	ListNode *fast = head;
	ListNode *slow = head;

	while(fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
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
  cout << "Middle Node: " << findMiddleLinkedList(head)->value << endl;

  head->next->next->next->next->next = new ListNode(6);
  cout << "Middle Node: " << findMiddleLinkedList(head)->value << endl;

  head->next->next->next->next->next->next = new ListNode(7);
  cout << "Middle Node: " << findMiddleLinkedList(head)->value << endl;
}*/
