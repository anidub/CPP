#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/merge-two-sorted-lists/
 * You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 * https://leetcode.com/problems/merge-two-sorted-lists/discuss/1826666/C%2B%2B-oror-Easy-To-Understand-oror-2-Approaches-oror-Recursive-oror-Iterative comments
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MergeTwoSortedLists {
public:
	//TC:O(M+N), SC:O(1)
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == nullptr) return l2;
		if(l2 == nullptr) return l1;

		ListNode* dummy = new ListNode(INT_MIN), *pre = dummy;

		while(l1 && l2) {
			if(l1->val < l2->val) {
				pre->next = l1;
				l1 = l1->next;
			} else {
				pre->next = l2;
				l2 = l2->next;
			}
			pre = pre->next;
		}
		pre->next = l1 ? l1 : l2;
		ListNode* temp = dummy->next;
		delete dummy;
		return temp;
	}
};
