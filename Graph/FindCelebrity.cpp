#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/find-the-celebrity/
 * Suppose you are at a party with n people labeled from 0 to n - 1 and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know the celebrity, but the celebrity does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) that tells you whether A knows B. Implement a function int findCelebrity(n). There will be exactly one celebrity if they are at the party.

Return the celebrity's label if there is a celebrity at the party. If there is no celebrity, return -1.
Input: graph = [[1,1,0],[0,1,0],[1,1,1]]
Output: 1
Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.

https://leetcode.com/problems/find-the-celebrity/discuss/71268/Straight-forward-C%2B%2B-solution-with-explaination
Rule 1. If A knows B: A must not be celebrity, B possible
Rule 2. If A doesn't know B: A possible, B must not be celebrity.

 */

bool knows(int i, int j);
/* WORKS!!
//TC: O(N), SC : O(1)
int findCelebrity(int n) {
	if(n <= 1) return 0;
	int candidate = 0;

	for(int i = 1; i < n; i++) {
		if( !knows(i, candidate) )
			candidate = i;
	}

	for(int j = 0; j < n; j++) {
		if(j == candidate) continue;

		if( !knows(j, candidate) || knows(candidate, j) )
			return -1;
	}
	return candidate;
}*/
/*
int main() {
	cout << findCelebrity(2) << endl;
	return 0;
}
*/
