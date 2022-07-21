#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/reorder-list/
 * You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
Input: head = [1,2,3,4]
Output: [1,4,2,3]
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ReorderList {
public:
	//TC:O(N), SC:O(1)
	void reorderList(ListNode* head) {
		if(head == nullptr) return;

		ListNode* start = head;
		ListNode* slow = partition(head);
		ListNode* end = slow->next;
		slow->next = nullptr;
		end = reverse(end);

		ListNode* temp1, *temp2;

		while(start && end) {
			temp1 = start->next;
			temp2 = end->next;
			start->next = end;
			end->next = temp1;
			start = temp1;
			end = temp2;
		}
	}

	ListNode* partition(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while(fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}

	ListNode* reverse(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* cur = head;
		ListNode* next;
		while(cur) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
};
/*
int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next =  new ListNode(5);;
	ReorderList dc;
	dc.reorderList(head);
}
*/
