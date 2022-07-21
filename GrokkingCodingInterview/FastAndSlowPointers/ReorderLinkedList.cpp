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
 * https://www.educative.io/courses/grokking-the-coding-interview/YQJ4mr7yOrW
 * Input: 2 -> 4 -> 6 -> 8 -> 10 -> 12 -> null
Output: 2 -> 12 -> 4 -> 10 -> 6 -> 8 -> null
 */

ListNode *reverseLL(ListNode* head) {
	ListNode *current = head, *prev = nullptr, *next = nullptr;
	while(current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

ListNode *partition(ListNode *head) {
	ListNode *fast = head, *slow = head;
	while(fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
//TC:O(N), SC: O(1)
void reorder(ListNode *head) {
	if(head == nullptr || head->next == nullptr) return;
	ListNode *slow = partition(head);
	ListNode *start = head;
	ListNode *end = slow->next;
	slow->next = nullptr;

	end = reverseLL(end);
	ListNode *temp1, *temp2;

	while(start && end) {
		temp1 = start->next;
		temp2 = end->next;

		start->next = end;
		end->next = temp1;

		start = temp1;
		end = temp2;
	}
}
/*
int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);
  head->next->next->next->next->next = new ListNode(12);
  reorder(head);
  while (head != nullptr) {
    cout << head->value << " ";
    head = head->next;
  }
}
*/
