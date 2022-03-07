#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
 *Given a Circular Linked List node, which is sorted in ascending order, write a function to insert a value insertVal into the list such that it remains a sorted circular list. The given node can be a reference to any single node in the list and may not necessarily be the smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the circular list should remain sorted.

If the list is empty (i.e., the given node is null), you should create a new single circular list and return the reference to that single node. Otherwise, you should return the originally given node.
Input: head = [3,4,1], insertVal = 2
Output: [3,4,1,2]
Explanation: In the figure above, there is a sorted circular list of three elements. You are given a reference to the node with value 3, and we need to insert 2 into the list. The new node should be inserted between node 1 and node 3. After the insertion, the list should look like this, and we should still return node 3.

 https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/discuss/136918/(Accepted)-C%2B%2B-Solution-in-O(n)-with-Explanation
 */
class CircularNode {
public:
    int val;
    CircularNode* next;

    CircularNode() {}

    CircularNode(int _val) {
        val = _val;
        next = NULL;
    }

    CircularNode(int _val, CircularNode* _next) {
        val = _val;
        next = _next;
    }
};

CircularNode* insertInSorted(CircularNode* head, int insertVal) {
	if(!head) {
		CircularNode *head = new CircularNode(insertVal, nullptr);
		head->next = head;
		return head;
	}

	CircularNode *prev = head;
	CircularNode *next = head->next;
	bool inserted = false;

	while(true) {
        // insert when:
        // 1. prev <= insertVal <= next
        // 2. insertVal < min (insert at the tail)
        // 3. insertVal > max (insert at the tail)
		if( (prev->val <= insertVal && next->val >= insertVal) ||
			(prev->val > next->val && insertVal < next->val) ||
			(prev->val > next->val && insertVal > prev->val)
		) {
			prev->next = new CircularNode(insertVal, next);
			inserted = true;
			break;
		}
		prev = prev->next;
		next = next->next;
		if(prev == head) break;
	}
	if(!inserted) {
        // The only reason why `value` was not inserted is that
        // all values in the list are the same and are not equal to `value`.
        // So, we could insert `value` anywhere.
		prev->next = new CircularNode(insertVal, next);
	}
	return head;
}
/*
int main() {
	CircularNode *head = new CircularNode(3, nullptr);
	head->next = new CircularNode(4, nullptr);
	head->next->next = new CircularNode(1, nullptr);
	head->next->next->next = head;
	insertInSorted(head, 2);
	delete head;

	return 0;
}*/
