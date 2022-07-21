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
/*https://leetcode.com/problems/linked-list-cycle/
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * Input: head = [3,2,0,-4], pos = 1
Output: true

 */
class DetectCycle {
public:
	bool hasCycle(ListNode* head) {
		ListNode* fast = head, *slow = head;

		while(fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if(slow == fast) return true;
		}
		return false;
	}
};
/*
int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = head;
	DetectCycle dc;
	cout << dc.hasCycle(head) << endl;
}
*/
