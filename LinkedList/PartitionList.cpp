#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/partition-list/
 * Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
https://leetcode.com/problems/partition-list/discuss/29185/Very-concise-one-pass-solution
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
	if(!head || !head->next) return head;

	ListNode smallerHead(0), largerHead(0);
	ListNode *smaller = &smallerHead, *larger = &largerHead;
	while(head) {
		if(head->val < x) {
			smaller->next = head;
			smaller = smaller->next;
		} else {
			larger->next = head;
			larger = larger->next;
		}
		head = head->next;
	}
	larger->next = NULL;
	smaller->next = largerHead.next;
	return smallerHead.next;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(9);head->next->next->next = new ListNode(3);
	head->next->next->next->next  = new ListNode(1);

	ListNode *result = partition(head, 5);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
	delete head, result, cur;
	return 0;
}
*/
