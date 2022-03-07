#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/add-two-numbers/
 *
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


 * https://leetcode.com/problems/add-two-numbers/discuss/1554/Easy-recursive-solution-in-C%2B%2B
 * https://leetcode.com/problems/add-two-numbers/discuss/1498/C%2B%2B-concise-solution.
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumberRecursiveUtil(ListNode* l1, ListNode* l2, int carry);

ListNode* addTwoNumberRecursive(ListNode* l1, ListNode* l2) {
	return addTwoNumberRecursiveUtil(l1, l2, 0);
}

ListNode* addTwoNumberRecursiveUtil(ListNode* l1, ListNode* l2, int carry) {
	if(!l1 && !l2) {
		if(carry) return new ListNode(carry);
		else return NULL;
	}

	int val = carry + (l1 ? l1->val:0) + (l2 ? l2->val:0);
	ListNode* newNode = new ListNode(val%10);
	newNode->next = addTwoNumberRecursiveUtil(l1 ? l1->next:NULL, l2 ? l2->next:NULL, val/10);
	return newNode;
}

ListNode* addTwoNumbersIterative(ListNode* l1, ListNode* l2) {
	int carry = 0;
	ListNode* dummy = new ListNode(0), *cur;
	cur = dummy;

	while(l1 || l2 || carry) {
		if(l1) {
			carry += l1->val;
			l1 = l1->next;
		}
		if(l2) {
			carry += l2->val;
			l2 = l2->next;
		}
		cur->next = new ListNode(carry%10);
		cur = cur->next;
		carry = carry/10;
	}
	return dummy->next;
}
/*
int main() {
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(7);

	ListNode* result = addTwoNumbersIterative(l1, l2);
	ListNode* dummy = result;
	while(dummy)  {
		cout << dummy->val << "-";
		dummy = dummy->next;
	}
	cout << endl;
	delete l1; delete l2;
	return 0;
}*/
