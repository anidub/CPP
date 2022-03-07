#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
 * Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/discuss/366350/C%2B%2B-O(n)-(explained-with-pictures) : well explained
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//Time Complexity: O(n) where n is the length of head. Space Complexity: O(n) where n is the length of head
ListNode* removeZeroSumNodes(ListNode* head) {
	if(!head) return head;

	ListNode* dummy = new ListNode(0);
	dummy->next = head;

	unordered_map<int, ListNode*> map;
	int cur_sum = 0;
	map[cur_sum] = dummy;

	while(head != NULL) {
		cur_sum += head->val;
		if(map.find(cur_sum) != map.end()) {
			ListNode* prev = map[cur_sum];
			ListNode* start = prev;
			int temp_sum = cur_sum;
			while(prev != head) {
				prev = prev->next;
				temp_sum += prev->val;
				if(prev != head) map.erase(temp_sum);
			}
			start->next = head->next;
		} else {
			map[cur_sum] = head;
		}
		head = head->next;
	}
	head = dummy->next;
	delete dummy;
	return head;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(-3);head->next->next->next = new ListNode(3);
	head->next->next->next->next  = new ListNode(1);

	ListNode *result = removeZeroSumNodes(head);
	ListNode *cur = result;
	while(cur != NULL){
		cout << cur->val << "-";
		cur = cur->next;
	}
	delete head, result, cur;
	return 0;
}*/
