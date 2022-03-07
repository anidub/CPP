#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/palindrome-linked-list/
 * Given the head of a singly linked list, return true if it is a palindrome.
 * Input: head = [1,2,2,1]
Output: true

https://leetcode.com/problems/palindrome-linked-list/discuss/384305/Easy-C%2B%2B-solution-in-O(1)-space-beats-90
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseLL(ListNode* head);

//TC : O(n), SC: O(1)
bool isPalindrome(ListNode *head) {
	if(!head) return true;
	ListNode *fast = head;
	ListNode *slow = head;

	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	if(fast) slow = slow->next;
	ListNode *firsthalf = head;
	ListNode *secondhalf = reverseLL(slow);

	while(secondhalf) {
		if(firsthalf->val != secondhalf->val) return false;
		firsthalf = firsthalf->next;
		secondhalf = secondhalf->next;
	}
	return true;
}

ListNode* reverseLL(ListNode* head) {
	ListNode *cur = head;
	ListNode *prev = NULL, *nextNode;

	while(cur) {
		nextNode = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nextNode;
	}
	head = prev;
	return head;
}
/*
int main() {
	ListNode* n1 = new ListNode(1); n1->next = new ListNode(4); n1->next->next  = new ListNode(4);
	n1->next->next->next  = new ListNode(1);
	cout << isPalindrome(n1) << endl;

	delete n1;

	return 0;
}*/
