#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/swap-nodes-in-pairs/
 * Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
 Input: head = [1,2,3,4]
Output: [2,1,4,3]

if you want using new pointer : https://leetcode.com/problems/swap-nodes-in-pairs/discuss/719676/C%2B%2B-oror-100.00-oror-Easy-to-understand

https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11331/4ms-Easy-C%2B%2B-Iterative-Solution //used
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapAdjacentNodes(ListNode *head) {
	if(!head || !head->next) return head;

	ListNode new_head(0);
	new_head.next = head;
	ListNode *pre = &new_head;
	ListNode *cur = head;

	while(pre->next && cur->next) {
		pre->next = cur->next;
		cur->next = cur->next->next;
		pre->next->next = cur;
		pre = cur;
		cur = pre->next;
	}
	return new_head.next;
}

//https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11175/C%2B%2B-recursive-and-iterative-solutions.
ListNode* swapPairsRecursive(ListNode* head) {
    if (!head || !(head->next))
        return head;
    ListNode *res = head->next;
    head->next = swapPairsRecursive(res->next);
    res->next = head;
    return res;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(3);head->next->next->next = new ListNode(4);
	head->next->next->next->next  = new ListNode(5);

	ListNode *result = swapAdjacentNodes(head);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
	delete head, result, cur;

	return 0;
}*/
