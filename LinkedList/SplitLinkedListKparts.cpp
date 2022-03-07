#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/split-linked-list-in-parts/
 * Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

https://leetcode.com/problems/split-linked-list-in-parts/discuss/1244927/C%2B%2B-oror-easy-solution
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// TC: O(N), SC: O(1)
vector<ListNode*> splitLinkedListKparts(ListNode* head, int k) {
	ListNode* cur = head;
	vector<ListNode*> result;
	int len = 0;//first calculate the length
	while(cur) {
		cur = cur->next;
		len++;
	}
	cur = head;
	int numNodes = len / k;//the number of nodes that are to be in each group
	int extra = len % k; //the extra nodes that are left

	while(cur) {
		result.push_back(cur);
		int curLen = 1;
		while(curLen < numNodes) {
			cur = cur->next;
			curLen++;
		}
		if(extra > 0 && len > k) {
			cur = cur->next;
			extra--;
		}
		ListNode* temp = cur->next;
		cur->next = NULL;
		cur = temp;
	}
	while(len < k) {//if the number of nodes are less than k we add NULL
		result.push_back(NULL);
		len++;
	}
	return result;
}
/*
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);head->next->next = new ListNode(9);head->next->next->next = new ListNode(3);
	head->next->next->next->next  = new ListNode(1);
	splitLinkedListKparts(head, 5);
	delete head;
	return 0;
}*/
