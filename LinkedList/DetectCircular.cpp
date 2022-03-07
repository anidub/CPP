#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/linked-list-cycle/
 *Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
https://leetcode.com/problems/linked-list-cycle/discuss/44489/O(1)-Space-Solution
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool detectHasCycle(ListNode *head) {
	if(!head) return false;
	ListNode *fast = head, *slow = head;
	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast) return true;
	}
	return false;
}
/*https://leetcode.com/problems/linked-list-cycle-ii/
 * Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * https://leetcode.com/problems/linked-list-cycle-ii/discuss/1701128/C%2B%2BJavaPython-Slow-and-Fast-oror-Image-Explanation-oror-Beginner-Friendly
 * Time  Complexity: O(N) Space Complexity: O(1)
 */
ListNode* getCyclicNodeStart(ListNode *head) {
	if(!head) return nullptr;
	ListNode *fast = head, *slow = head;
	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast) break;
	}
	if( !(fast && fast->next) ) return nullptr;
	while(head != slow) {
		head = head->next;
		slow = slow->next;
	}
	return head;
}
/*
int main() {
	ListNode *head = new ListNode(3);
	head->next = new ListNode(4);
	head->next->next = new ListNode(1);
	head->next->next->next = head;

	cout << detectHasCycle(head) << endl;

	cout << getCyclicNodeStart(head)->val << endl;
	delete head;
	return 0;
}*/
