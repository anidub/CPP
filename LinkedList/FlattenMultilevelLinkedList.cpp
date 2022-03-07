#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 * You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/231435/C%2B%2B-Recursive-and-Iterative
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/728353/C%2B%2B-or-Two-Solutions : recursive
 */
class MultiLLNode {
public:
	int val;
	MultiLLNode *next;
	MultiLLNode *prev;
	MultiLLNode *child;
};

MultiLLNode* flattenMultiLevelLinkedListIterative(MultiLLNode *head) {//Use this
	if(!head) return NULL;
	MultiLLNode *cur = head;
	while(cur) {
		if(cur->child) {
			MultiLLNode *next = cur->next;
			cur->next = cur->child;
			cur->child = NULL;
			cur->next->prev = cur;
			MultiLLNode *tail = cur->next;
			while(tail->next)
				tail = tail->next;
			tail->next = next;
			if(next)
				next->prev = tail;
		}
		cur = cur->next;
	}
	return head;
}

MultiLLNode* flattenMultiLevelLinkedListRecusive(MultiLLNode *head) {
	if(!head) return NULL;
	MultiLLNode *cur = head;
	while(cur) {
		if(cur->child) {
			MultiLLNode *next = cur->next;
			MultiLLNode *child = flattenMultiLevelLinkedListRecusive(cur->child);
			cur->child = NULL;
			cur->next = child;
			child->prev = cur;
			MultiLLNode *tail = child;
			while(tail->next)
				tail = tail->next;
			tail->next = next;
			if(next) next->prev = tail;
		}
		cur = cur->next;
	}
	return head;
}

/*
int main() {
}*/
