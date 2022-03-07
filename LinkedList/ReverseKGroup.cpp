#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/reverse-nodes-in-k-group/
 * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

 * https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/607749/C%2B%2B-or-Easy-solution-or-Recursion
 * https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11457/20-line-iterative-C%2B%2B-solution : comments
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
 * avoided using new keyword since it requires delete and causes memory leak
 * To not leak memory and to not have to delete preheader manually use below
 */
ListNode* reverseKGroupsOptimal(ListNode* head, int k) {
	if(!head || k == 1) return head;
	ListNode preheader = ListNode(-1);
	preheader.next = head;
	ListNode *cur = &preheader, *pre = &preheader, *nex;
	int count = 0;
	while(cur = cur->next) count++;

	while(count >= k) {
		cur = pre->next;
		nex = cur->next;
		for(int i = 1; i < k; i++) {
			cur->next = nex->next;
			nex->next = pre->next;
			pre->next = nex;
			nex = cur->next;
		}
		pre = cur;
		count -= k;
	}
	return preheader.next;

}

int countNodes(ListNode* head) {
	int c = 0;
	if(!head) return c;
	while(head) {
		c++; head = head->next;
	}
	return c;
}

ListNode* reverseKGroups(ListNode* head, int k) {
	ListNode* prev = NULL;
	ListNode *next, *cur = head;

	int c = countNodes(head);
	if(c < k || !head) return head;

	int n = k;
	while(cur && n--) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	if(head) head->next = reverseKGroups(next, k);

	return prev;
}
/*
int main() {

	return 0;
}*/
