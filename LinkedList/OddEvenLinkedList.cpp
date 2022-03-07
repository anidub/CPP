#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/odd-even-linked-list/
 * Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

https://leetcode.com/problems/odd-even-linked-list/discuss/78274/My-c%2B%2B-solution
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//Time Complexity: O(n) Space Complexity: O(1)
ListNode* oddEvenList(ListNode *head) {
	if(!head || !head->next) return head;

	ListNode *odd = head;
	ListNode *even_head = head->next, *even = even_head;

	while(even && even->next) {
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}

	odd->next = even_head;
	return head;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(3);head->next->next->next = new ListNode(4);
	head->next->next->next->next  = new ListNode(5);

	ListNode *result = oddEvenList(head);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
}*/
