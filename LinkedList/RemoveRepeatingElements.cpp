#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/
 *Given the head of a linked list, find all the values that appear more than once in the list and delete the nodes that have any of those values.

Return the linked list after the deletions.
Input: head = [1,2,3,2]
Output: [1,3]
Explanation: 2 appears twice in the linked list, so all 2's should be deleted. After deleting all 2's, we are left with [1,3
https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/discuss/1171638/C%2B%2B-Two-Pass
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeRepeatingElements(ListNode* head) {
	if(head == nullptr) return head;
	ListNode tmp(-1);
	tmp.next = head;
	ListNode *cur = head;
	unordered_map<int, int> map;
	while(cur != nullptr) {
		map[cur->val]++;
		cur = cur->next;
	}
	cur = &tmp;
	ListNode *newNode = &tmp;
	while(cur != nullptr) {
		newNode->next = cur->next;
		if(cur->next && map[cur->next->val] == 1)
			newNode = newNode->next;
		cur = cur->next;
	}
	return tmp.next;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(2);head->next->next->next = new ListNode(3);
	head->next->next->next->next  = new ListNode(9);

	ListNode *result = removeRepeatingElements(head);
	ListNode *cur = result;
	while(cur != nullptr){
		cout << cur->val << "-";
		cur = cur->next;
	}
	delete head, result, cur;
	return 0;
}
*/
