#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <stack>
#include <utility>
#include <list>
#include <iterator>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/linked-list-random-node/
 * Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Implement the Solution class:

Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
 *
 *
https://leetcode.com/problems/linked-list-random-node/discuss/1672070/C%2B%2B-EASY-TO-SOLVE-oror-Beginner-friendly-with-few-imp-notes
The Reservoir sampling method:-
When we read the first node head, if the stream ListNode stops here, we can just return the head->val. The probability of picking here is 1/1 .
When we goto second node we can decide if we replace the result r or not. The possibility is 1/2. So now we need to generate a random number between 0 & 1 and if it is equals to 1 replace r with the current node else we don't traumantize r, so it's value is till the value of head .
Now let's goto third node and we can decide if we can replace the result r or not . The probability of picking the third node will be 1/3 . and not picking up will be 2/3 . So now we generate a random number between 0-to-2 if the result is 2 then we replace r with the value of indexed node 2
We need to continue this till the end of list node .
To conclude, if we have n different balls than the equal probability of picking any one of them will be 1/n .
Now that's it, this is what reservoir sampling method looks like, told you its easy ;)
 */
struct ListNode {
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(nullptr) {}
};

class RandomLLNode {
	ListNode *HeadNode;
public:
RandomLLNode(ListNode *head) {
	HeadNode = head;
}

int getRandom() {
	int res, len = 1;
	ListNode *cur = HeadNode;
	while(cur) {
		if(rand() % len == 0)
			res = cur->val;
		len++;
		cur = cur->next;
	}
	return res;
}
};
/*
int main() {
	ListNode* head = new ListNode(1); head->next = new ListNode(2);head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	RandomLLNode randomLLNode(head);
	cout << randomLLNode.getRandom() << endl;
	cout << randomLLNode.getRandom() << endl;
	cout << randomLLNode.getRandom() << endl;
}
*/
