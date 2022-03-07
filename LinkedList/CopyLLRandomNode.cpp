#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/copy-list-with-random-pointer/
 * A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

 *
 *Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]


 * https://leetcode.com/problems/copy-list-with-random-pointer/discuss/910443/Kotlin-C%2B%2B%3A-O(n)-time-and-O(1)-space
 * https://leetcode.com/problems/copy-list-with-random-pointer/discuss/249256/C%2B%2B-iterative-recursive-and-O(1)-space
 */
class LLRandomNode {
public:
    int val;
    LLRandomNode* next;
    LLRandomNode* random;

    LLRandomNode(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
//O(1)-space// to understand : https://www.youtube.com/watch?v=OvpKeraoxW0 at 11.30 onwards
LLRandomNode* copyRandomLLOptimal(LLRandomNode* head) {
	if(!head) return head;

	LLRandomNode* node = head;
	while(node != NULL) {
		LLRandomNode* cloned = new LLRandomNode(node->val);
		cloned->next = node->next;
		node->next = cloned;
		node = cloned->next;
	}

	node = head;
	while(node != NULL) {
		if(node->random != NULL)
			node->next->random = node->random->next;
		node = node->next->next;
	}
	node = head;
	LLRandomNode* dummy = new LLRandomNode(-1), *cur = dummy;
	dummy->next = head;

	while(node != NULL) {
		cur->next = node->next;
		node->next = node->next->next;
		cur = cur->next;
		node = node->next;
	}
	return dummy->next;
}

unordered_map<LLRandomNode*, LLRandomNode*> copies;
//O(N) space
LLRandomNode* copyRandomLLIterative(LLRandomNode* head) {
	if(!head) return NULL;

	copies[head] = new LLRandomNode(head->val);
	LLRandomNode *node = head;

	while(node) {
		LLRandomNode *next = node->next; LLRandomNode *random = node->random;

		if(next && copies.find(next) == copies.end()) {
			copies[next] = new LLRandomNode(next->val);
		}
		if(random && copies.find(random) == copies.end()) {
			copies[random] = new LLRandomNode(random->val);
		}

		copies[node]->next = next ? copies[next] : NULL;
		copies[node]->random = random ? copies[random] : NULL;
		node = next;
	}
	return copies[head];
}
//O(N) space
LLRandomNode* copyRandomLLRecursive(LLRandomNode* head) {
	if(!head) return NULL;

	if(copies.find(head) == copies.end()) {
		copies[head] = new LLRandomNode(head->val);
		copies[head]->next = copyRandomLLRecursive(head->next);
		copies[head]->random = copyRandomLLRecursive(head->random);
	}
	return copies[head];
}
/*
int main() {

	return 0;
}
*/
