#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <stack>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/next-greater-node-in-linked-list/
 * You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 *https://leetcode.com/problems/next-greater-node-in-linked-list/discuss/277316/C%2B%2B-O(n)-solution-with-stack
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nextLargerNodes(ListNode* head) {
    if(!head) return {};
    vector<int> result;
    stack<pair<int, int>> st;
    for(int i = 0; head; head = head->next) {
    	while(st.size() && head->val > st.top().first) {
    		result[st.top().second] = head->val;
    		st.pop();
    	}
    	st.push({head->val, i++});
    	result.push_back(0);
    }
    return result;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(2);head->next->next->next = new ListNode(3);
	head->next->next->next->next  = new ListNode(4);


	delete head;
	return 0;
}
*/
