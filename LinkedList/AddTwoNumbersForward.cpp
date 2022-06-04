#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/add-two-numbers-ii/
 * You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
https://leetcode.com/problems/add-two-numbers-ii/discuss/1514318/C%2B%2B-commented-solution-or-Without-stack-or-recursion
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//TC: O(N1 + N2), SC: O(1)
ListNode* addTwoNumbersForward(ListNode *l1, ListNode *l2) {
	if(!l1) return l2;
	if(!l2) return l1;

	ListNode *cur1 = l1; int len1 = 0;
	// find the length of both lists
	while(cur1) {
		cur1 = cur1->next;
		len1++;
	}

	ListNode *cur2 = l2; int len2 = 0;
	while(cur2) {
		cur2 = cur2->next;
		len2++;
	}
	// parse both lists and sum the corresponding positions without taking carry into account
	// 3->3-> 3 + 7->7 --> 3->10->10--> 10->10->3

	cur1 = l1, cur2 = l2;
	ListNode *head = NULL;

	while(len1 && len2) {
		int val = 0;
		if(len1 >= len2) {
			val += cur1->val;
			cur1 = cur1->next;
			len1--;
		}
		if(len1 < len2) {
			val += cur2->val;
			cur2 = cur2->next;
			len2--;
		}
		 // update the result: add to front
		ListNode *curr = new ListNode(val);
		curr->next = head;
		head = curr;
	}

	cur1 = head;
	head = NULL;
	int carry = 0;
    // take the carry into account
    // to have all elements to be less than 10
    // 10->10->3 --> 0->1->4 --> 4->1->0
	while(cur1) {
		// current sum and carry
		int val = (cur1->val + carry) % 10;
		carry = (cur1->val) / 10;
		 // update the result: add to front
		ListNode *curr= new ListNode(val);
		curr->next = head;
		head = curr;
		// move to the next elements in the list
		cur1 = cur1->next;
	}
	 // add the last carry
	if(carry != 0) {
		ListNode *cur = new ListNode(carry);
		cur->next = head;
		head = cur;
	}
	return head;
}
/*
int main() {
	ListNode *l1 = new ListNode(7);
	l1->next = new ListNode(2);l1->next->next = new ListNode(4);l1->next->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6); l2->next->next = new ListNode(4);

	ListNode *result = addTwoNumbersForward(l1, l2);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
	delete l1, l2;
}
*/
