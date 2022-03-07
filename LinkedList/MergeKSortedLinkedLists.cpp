#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/merge-k-sorted-lists/
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
https://leetcode.com/problems/merge-k-sorted-lists/discuss/244840/C%2B%2B-4-solutions
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKSortedLists(vector<ListNode*>& lists) {
	if(lists.empty()) return NULL;
	ListNode *dummy = new ListNode(INT_MIN), *cur = dummy;
	int min = INT_MAX, idx = 0;

	while(true) {
		for(int i = 0; i < lists.size(); i++) {
			if(lists[i] &&  lists[i]->val < min) {
				min = lists[i]->val;
				idx = i;
			}
		}
		if(min == INT_MAX) break;
		cur->next = lists[idx];
		cur = cur->next;
		lists[idx] = lists[idx]->next;
		min = INT_MAX;
	}
	return dummy->next;
}
/*
int main() {
	ListNode* n1 = new ListNode(1); n1->next = new ListNode(4); n1->next->next  = new ListNode(5);
	ListNode* n2 = new ListNode(1); n2->next = new ListNode(3); n2->next->next  = new ListNode(4);
	ListNode* n3 = new ListNode(2); n3->next = new ListNode(6);
	vector<ListNode*> v {n1, n2, n3};
	ListNode *result = mergeKSortedLists(v);

	ListNode* dummy = result;
	while(dummy)  {
		cout << dummy->val << "-";
		dummy = dummy->next;
	}
	cout << endl;
	delete n1; delete n2; delete n3;

	return 0;
}*/
