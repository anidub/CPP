#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/rotate-list/
 * Given the head of a linked list, rotate the list to the right by k places.
 * Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
https://leetcode.com/problems/rotate-list/discuss/22853/C%2B%2B-concise-solution.
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateList(ListNode* head, int k) {
	int len = 0;
	ListNode* node = head;
	while(node) {
		node = node->next;
		len++;
	}
	if(!head || k % len == 0) return head;
	k = k % len;

	ListNode *fast, *slow;
	fast = slow = head;

	for(int i = 0; i < k; i++) {
		fast = fast->next;
	}

	while(fast && fast->next) {
		fast = fast->next;
		slow = slow->next;
	}
	ListNode* res = slow->next;
	slow->next = nullptr;
	fast->next = head;
	return res;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(3);head->next->next->next = new ListNode(4);
	head->next->next->next->next  = new ListNode(5);

	ListNode *result = rotateList(head,2);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
	delete head, result, cur;

	return 0;
}
*/
