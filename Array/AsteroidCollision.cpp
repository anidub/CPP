#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/asteroid-collision/
 * We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
https://leetcode.com/problems/asteroid-collision/discuss/904281/C%2B%2B-code-with-explanation-(beats-95-in-runtime) : well explained

Consider the same example [8, 9, 6, -7, -9, 12, 50, -34]
Initially i = 0.

Whenever we encounter a positive value, we will simply push it to the stack.
The moment we encounter a negative value, we know some or all or zero positive values will be knocked out of the stack. The negative value may itself be knocked out or it may enter the stack.
We will keep on poping the elements from the stack while the asteroids[i] > s.top(). But remember, negative asteroids can never pop another negative asteroids, since they will never meet them. So, the final condition is while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i])), we will pop the elements.
We have to take care of the case when s.top() == asteroids[i]. In this case one positive element will pop out and negative asteroid won't enter the stack.
If after knocking out elements stack becomes empty() or s.top() becomes negative, that means the current asteroids[i] will enter the stack.

 */
//TC: O(n), SC : O(n)
vector<int> asteroidCollision(vector<int>& ast) {
	if(ast.empty()) return {};
	int n = ast.size();
	stack<int> s;

	for(int i = 0; i < n; i++) {
		if(s.empty() || ast[i] > 0) {
			s.push(ast[i]);
		} else {
			while(!s.empty() && s.top() > 0 && s.top() < abs(ast[i])) {
				s.pop();
			}
			if(!s.empty() && s.top() == abs(ast[i])) {
				s.pop();
			} else {
				if(s.empty() || s.top() < 0)
					s.push(ast[i]);
			}
		}
	}
	vector<int> res(s.size());		// finally we are returning the elements which remains in the stack. we have to return them in reverse order.
	for(int i = s.size() - 1; i >= 0; i--) {
		res[i] = s.top();
		s.pop();
	}
	return res;
}
/*
int main() {
	vector<int> ast = {5, 10, -5};
	asteroidCollision(ast);

	return 0;
}*/
