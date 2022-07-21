#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>
/*https://leetcode.com/problems/reverse-linked-list/
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 * Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

 */

using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ReverseLinkedList {
public:
	//TC:O(N), SC:O(1)
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* cur = head;
		while(cur) {
			ListNode* next = cur->next;
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
	head->next->next->next->next = new ListNode(5);
	ReverseLinkedList rll;
	cout << rll.reverseList(head)->val << endl;
}
*/
