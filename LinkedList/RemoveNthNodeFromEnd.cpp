#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/8812/My-short-C%2B%2B-solution : comments
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthNodeFromEnd(ListNode *head, int n) {
	if(!head) return NULL;

	ListNode *ans;
	ListNode *fast = head;
	ListNode *slow = head;

	for(int i = 0; i < n; i++)
		fast = fast->next;

	if(fast == NULL) {
		ans = head->next;
		head = head->next;
		return ans;
	}

	while(fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	slow->next = slow->next->next;
	return head;
}

/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(3);head->next->next->next = new ListNode(4);
	head->next->next->next->next  = new ListNode(5);

	ListNode *result = removeNthNodeFromEnd(head, 2);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
}*/
