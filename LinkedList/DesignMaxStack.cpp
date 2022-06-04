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

using namespace std;

/*https://leetcode.com/problems/max-stack/
 * Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

MaxStack() Initializes the stack object.
void push(int x) Pushes element x onto the stack.
int pop() Removes the element on top of the stack and returns it.
int top() Gets the element on the top of the stack without removing it.
int peekMax() Retrieves the maximum element in the stack without removing it.
int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the top-most one.
Could you come up with a solution that supports O(1) for each top call and O(logn) for each other call?

There are two solutions below: use depending on clarification on time complexities for operations. If none the use first

https://leetcode.com/problems/max-stack/discuss/490946/c%2B%2B-two-solutions-clean-code
 */
/*
 * push -O(log(n)) - due to insert in sorted map ( c++ map is RB tree/BST)
pop , popMax- O(log(n) - due to each erase() in operation in sorted map requires rebalancing
top, peekMax - O(1)

 */
/*
class MaxStack {
	list<int> dll;
	map<int, vector<list<int>::iterator>, greater<int>> mp;
public:
	void push(int x) {
		dll.push_front(x);
		mp[x].push_back(dll.begin());
	}

	int pop() {
		int x = dll.front();
		dll.pop_front();
		mp[x].pop_back();
		if(mp[x].empty()) mp.erase(x);
		return x;
	}

	int top() {
		return dll.front();
	}

	int peekMax() {
		return mp.begin()->first;
	}

	int popMax() {
		int x = mp.begin()->first;
		auto it = (mp.begin()->second).back();
		dll.erase(it);
		mp[x].pop_back();
		if(mp[x].empty()) mp.erase(x);
		return x;
	}

};
*/
/*
 * push, pop, top, peekMax- O(1)
popMax - O(n)- since in the worst case we need to pop all elements from the stack to get to the max if it was inserted first
 */

class MaxStack{
	stack<int> s1;
	stack<int> s2;
public:
	void push(int x) {
		s1.push(x);
		if(s2.empty() || s2.top() <= x) s2.push(x);
	}

	int pop() {
		int x = s1.top();
		s1.pop();
		if(x == peekMax()) s2.pop();
		return x;
	}

	int top() { return s1.top(); }

	int peekMax() {return s2.top();}

	int popMax() {
		int x = peekMax();
		stack<int> tmp;
		while(top() != x) tmp.push(pop());
		pop();
		while(!tmp.empty()) {
			push(tmp.top());
			tmp.pop();
		}
		return x;
	}
};

