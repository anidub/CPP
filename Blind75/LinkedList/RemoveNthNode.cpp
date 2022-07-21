#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
 */
class RemoveNthNode {
public:
	//TC:O(N), SC:O(1)
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* ans;
		ListNode* fast = head;
		ListNode* slow = head;

		for(int i = 0; i < n; i++) {
			fast = fast->next;
		}
		if(fast == nullptr) {
			ans = head->next;
			delete head;
			return ans;
		}

		while(fast->next != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}

		slow->next = slow->next->next;
		return head;
	}
 };
/*
int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next =  new ListNode(5);;
	RemoveNthNode dc;
	cout << dc.removeNthFromEnd(head, 2)->val << endl;
}
*/
