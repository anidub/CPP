#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/reverse-linked-list-ii/
 * Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list
 * Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
https://leetcode.com/problems/reverse-linked-list-ii/discuss/30744/Share-my-14-lines-C%2B%2B-solution

Use variables on stack not heap otherwise memory leak
ListNode newNode; <- stack
ListNode *newNode = new ListNode(); <- heap
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetweenMandN(ListNode *head, int m, int n){
	if(!head || m == n) return head;
	n = n-m;
	ListNode prehead(0);
	prehead.next = head;
	ListNode *pre = &prehead;

	while(m > 1) {
		pre = pre->next;
		m--;
	}
	ListNode *pstart = pre->next;

	while(n > 0) {
		ListNode *p = pstart->next;
		pstart->next = p->next;
		p->next = pre->next;
		pre->next = p;
		n--;
	}
	return prehead.next;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(3);head->next->next->next = new ListNode(4);
	head->next->next->next->next  = new ListNode(5);

	ListNode *result = reverseBetweenMandN(head,2 ,5);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
	delete head, result, cur;

	return 0;
}*/
