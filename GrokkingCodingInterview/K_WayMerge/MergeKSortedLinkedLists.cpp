#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/Y5n0n3vAgYK
 * Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.
 * Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]
 */
class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

class MergeKSortedLists {
public:
	struct ValueCompare {
		bool operator()(const ListNode* x, const ListNode* y) {
			return x->value > y->value;
		}
	};

	//TC: O(N *LOGK), SC:O(K)
	ListNode *merge(const vector<ListNode *> &lists) {
		if(lists.empty()) return nullptr;

		priority_queue<ListNode*, vector<ListNode*>, ValueCompare> minHeap;

		for(auto entry : lists) {
			if(entry != nullptr)
				minHeap.push(entry);
		}

		ListNode *head = nullptr, *tail = nullptr;

		while(!minHeap.empty()) {
			ListNode *node = minHeap.top(); minHeap.pop();
			if(head == nullptr) {
				head = node;
				tail = node;
			} else {
				tail->next = node;
				tail = tail->next;
			}
			if(node->next != nullptr)
				minHeap.push(node->next);
		}
		return head;
	}

};

/*
int main() {
	  ListNode *l1 = new ListNode(2);
	  l1->next = new ListNode(6);
	  l1->next->next = new ListNode(8);

	  ListNode *l2 = new ListNode(3);
	  l2->next = new ListNode(6);
	  l2->next->next = new ListNode(7);

	  ListNode *l3 = new ListNode(1);
	  l3->next = new ListNode(3);
	  l3->next->next = new ListNode(4);
	  MergeKSortedLists mksl;

	  ListNode *result = mksl.merge(vector<ListNode *>{l1, l2, l3});
	  cout << "Here are the elements form the merged list: ";
	  while (result != nullptr) {
	    cout << result->value << " ";
	    result = result->next;
	  }
}
*/
