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
 */
class MergeKSortedLists {
public:
	//TC:O(kN):k is number of lists, N : size of each list, SC:O(1)
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.empty()) return nullptr;
		ListNode* dummy = new ListNode(INT_MIN), *cur = dummy;
		int min = INT_MAX, idx = 0;

		while(true) {
			for(int i = 0; i < lists.size(); i++) {
				if(lists[i] && lists[i]->val < min) {
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
		ListNode *temp = dummy->next;
		delete dummy;
		return temp;
	}
};
