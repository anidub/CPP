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
/*https://www.geeksforgeeks.org/skip-list/
 * https://www.youtube.com/watch?v=YZ5ef_HiHJ8
 * https://leetcode.com/problems/design-skiplist/
 * Design a Skiplist without using any built-in libraries.

A skiplist is a data structure that takes O(log(n)) time to add, erase and search. Comparing with treap and red-black tree which has the same function and performance, the code length of Skiplist can be comparatively short and the idea behind Skiplists is just simple linked lists.
Input
["Skiplist", "add", "add", "add", "search", "add", "search", "erase", "erase", "search"]
[[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
Output
[null, null, null, null, false, null, true, false, true, false]
https://leetcode.com/problems/design-skiplist/discuss/400028/C%2B%2B-SkipList.-2-pointer-for-each-node.-64ms.
 *
search(): O(log n)
add(): O(log n)
erase(): O(log n)
*/

struct Node {
	Node *right;
	Node *down;
	int val;
	Node(Node *right, Node *down, int val): right(right), down(down), val(val) {}
};

class Skiplist{
	Node *head;

public:
	Skiplist() {
		head = new Node(nullptr, nullptr, 0);
	}
	bool search(int num) {
		Node *p = head;
		while(p) {
			while(p->right && p->right->val < num) p = p->right;
			if(!p->right || p->right->val > num) p = p->down;
			else
				return true;
		}
		return false;
	}

	void add(int num) {
		vector<Node*> insertPoints;
		Node *p = head;
		while(p) {
			while(p->right && p->right->val < num) p = p->right;
			insertPoints.push_back(p);
			p = p->down;
		}
		bool insertUp = true;
		Node *downNode = nullptr;

		while(insertUp && insertPoints.size()) {
			Node *ins = insertPoints.back();
			insertPoints.pop_back();

			ins->right = new Node(ins->right, downNode, num);
			downNode = ins->right;
			insertUp = (rand() % 2 == 0); // Randomly decide whether to insert at a higher level

		}
		if(insertUp) {        // If we need to add a new top level
			head = new Node(new Node(nullptr, downNode, num), head, 0);
		}
	}

	bool erase(int num) {
		Node *p = head;
		bool seen = false;
		while(p) {
			while(p->right && p->right->val < num) p = p->right;
			if(!p->right || p->right->val > num) p = p->down;
			else {
				seen = true;
				p->right = p->right->right;
				p = p->down;
			}
		}
		return seen;
	}
};
/*
int main() {
	Skiplist *skiplist = new Skiplist();
	skiplist->add(1);
	skiplist->add(2);
	skiplist->add(3);
	cout << skiplist->search(0) << endl; // return False
	skiplist->add(4);
	skiplist->search(1); // return True
	skiplist->erase(0);  // return False, 0 is not in skiplist.
	cout << skiplist->erase(1) << endl;  // return True
	skiplist->search(1); // return False, 1 has already been erased.

	delete skiplist;
	return 0;
}*/
