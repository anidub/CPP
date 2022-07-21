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
/*https://www.educative.io/courses/grokking-the-coding-interview/B1PzmqOKDLQ
 * Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.
 * Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
Output: true
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
ListNode *reverse(ListNode *head);
//TC:O(N)
bool isPalindrome(ListNode *head) {
	if(head == nullptr || head->next == nullptr) return true;

	ListNode *fast = head;
	ListNode *slow = head;

	while(fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	if(fast) slow = slow->next;

	ListNode *secondHalf = reverse(slow);
	ListNode *secondHalfCopy = secondHalf;

	while(head != nullptr && secondHalfCopy != nullptr) {
		if(head->value != secondHalfCopy->value) break;
		head = head->next;
		secondHalfCopy = secondHalfCopy->next;
	}
	reverse(secondHalf);
	if(head == nullptr || secondHalfCopy == nullptr)
		return true;
	return false;
}

ListNode *reverse(ListNode *head) {
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
/*
int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << isPalindrome(head) << endl;

  head->next->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << isPalindrome(head) << endl;
}
*/
