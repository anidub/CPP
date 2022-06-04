#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*Copy a singly linkedList;
 *
 *  1 - 4 - 3
 *
 *  1 - 4 - 3
 *
 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* cloneSinglyLinkedList(ListNode *head) {
	if(head == nullptr) return nullptr;
	ListNode *cur = head;
	ListNode *newList = nullptr, *tail = nullptr;

	while(cur) {
		if(newList == nullptr) {
			newList = new ListNode(cur->val);
			newList->next = cur->next;
			tail = newList;
		} else {
			tail->next = new ListNode(cur->val);
			tail = tail->next;
			tail->next = nullptr;
		}
		cur = cur->next;
	}
	return newList;
}
/*
int main(){
    ListNode* n1 = new ListNode(1); n1->next = new ListNode(4); n1->next->next  = new ListNode(5);
    ListNode *result = cloneSinglyLinkedList(n1);
    ListNode* dummy = result;
	while(dummy)  {
		cout << dummy->val << "-";
		dummy = dummy->next;
	}
	cout << endl;
    return 0;
}*/
