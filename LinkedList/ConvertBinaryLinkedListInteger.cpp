#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
 *Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/discuss/1616270/CC%2B%2BPython-Simple-IterativeRecursive-Solutions

Left Shift : << :Takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift.
Or in other words left shifting an integer “x” with an integer “y” denoted as ‘(x<<y)’ is equivalent to multiplying x with 2^y (2 raised to power y).

x << y = x * 2^y

Right Shift : >>
Takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift.
In other words right shifting an integer “x” with an integer “y” denoted as ‘(x>>y)‘ is equivalent to dividing x with 2^y.
x >> y = x / 2^y

 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//Time Complexity: O(n) Space Complexity: O(1)
int getDecimalValue(ListNode* head) {
	if(!head) return -1;
	int res = 0;
	while(head) {
		res = res << 1;
		res += head->val;
		head = head->next;
	}
	return res;
}
/*
int main() {
	ListNode* head = new ListNode(1); head->next = new ListNode(0); head->next->next = new ListNode(1);
	cout << getDecimalValue(head) << endl;
	delete head;
}*/
