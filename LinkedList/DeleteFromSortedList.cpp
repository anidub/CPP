#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 *Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

 https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/discuss/28351/C%2B%2B-solution-simple-and-easy-to-understand : comments
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicatesFromSorted(ListNode* head) {
	if(!head || !head->next) return head;

	ListNode dummyHead(-1); dummyHead.next = head;
	ListNode* cur = head; ListNode* prev = &dummyHead;

	while(cur != nullptr && cur->next != nullptr) {
		if(cur->next->val == cur->val) {
			int duplicateVal = cur->val;
			while(cur != nullptr && cur->val == duplicateVal) {
				prev->next = cur->next;
				delete cur;
				cur = prev->next;
			}
		} else {
			prev = cur;
			cur = cur->next;
		}
	}
	return dummyHead.next;
}

/*https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/discuss/28730/Concise-solution-and-memory-freeing
 * We need to free memory when we delete a node. But don't use delete node; construct on an interview without discussing it with the interviewer. A list node can
 * be allocated in many different ways and we can use delete node; only if we are sure that the nodes were allocated with new TreeNode(...);
 */
ListNode* deleteDuplicates(ListNode* head) {
	if(!head) return head;
	ListNode* cur = head;
	while(cur) {
		while(cur->next && cur->next->val == cur->val)
			cur->next = cur->next->next;
		cur = cur->next;
	}
	return head;
}

//https://leetcode.com/problems/delete-node-in-a-linked-list/
//https://leetcode.com/problems/delete-node-in-a-linked-list/discuss/65547/My-C%2B%2B-solution-in-1-line : comments
void deleteNode(ListNode* node) {
	ListNode* temp = node->next;
	*node = *temp;
	delete temp;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(2);head->next->next->next = new ListNode(3);
	head->next->next->next->next  = new ListNode(4);

	//ListNode *result = deleteDuplicatesFromSorted(head);
	ListNode *result = deleteDuplicates(head);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
	delete head, result, cur;
	return 0;
}*/
