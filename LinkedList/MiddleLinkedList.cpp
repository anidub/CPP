#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/middle-of-the-linked-list/
 *Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
https://leetcode.com/problems/middle-of-the-linked-list/discuss/154763/Remember-this-pattern-for-problems-that-require-middle-finding-in-a-Linked-List.
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head) {
	if(!head) return head;
	ListNode *fast = head;
	ListNode *slow = head;
	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(3);head->next->next->next = new ListNode(4);
	head->next->next->next->next  = new ListNode(5); head->next->next->next->next->next  = new ListNode(6);

	cout << middleNode(head)->val << endl;
}*/
