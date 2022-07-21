#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_set>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/stamping-the-sequence/
 *You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.

In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.

For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
place stamp at index 0 of s to obtain "abc??",
place stamp at index 1 of s to obtain "?abc?", or
place stamp at index 2 of s to obtain "??abc".
Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
We want to convert s to target using at most 10 * target.length turns.

Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 * target.length turns, return an empty array.
Input: stamp = "abc", target = "ababc"
Output: [0,2]
Explanation: Initially s = "?????".
- Place stamp at index 0 to get "abc??".
- Place stamp at index 2 to get "ababc".
[1,0,2] would also be accepted as an answer, as well as some other answers.

https://www.youtube.com/watch?v=EtalsGoNrBI : well explained
https://leetcode.com/problems/stamping-the-sequence/discuss/1136054/Short-and-Easy-w-Explanation-and-Illustration-or-Greedy-Approach

 In worst case, we might only add 1 extra star in each iteration of target, and we would have to iterate N-M length for N times to make all characters starred. Consider example - target = "aaaaaaaaabc", stamp = "abc".

 */
int n, m, stars;
vector<int> moveStampAns;

bool checkAndReplace(string &stamp, int &start, string &target);

//TC: O(N*(N-M)), SC:O(N):where M, NM,N are the lengths of stamp, target.
vector<int> movesToStamp(string stamp, string target) {
	if(target.empty()) return {};
	stars = 0, n = target.size(), m = stamp.size();
	vector<bool> vis(n, false);

	while(stars < n) {// till all characters have not been stamped
		bool replaced = false;
		for(int i = 0; i <= n - m && stars < n; i++) {
			if(!vis[i]) {// for each non-visited index, check if there's a match with 'stamp' for target substring starting at replace and increment the stars count if there's a match (partial or complete)
				replaced = checkAndReplace(stamp, i, target);
				vis[i] = replaced;
			}
		}
		if(!replaced) return {}; // if no replacement occurs throughout one iteration over target, return []
	}
	reverse(moveStampAns.begin(), moveStampAns.end());// we began with reverse approach, real sequence will be reverse of what we got
	return moveStampAns;
}

bool checkAndReplace(string &stamp, int &start, string &target) {
	for(int i = 0; i < m; i++) {// check for match
		if(target[i + start] != '*' && target[i + start] != stamp[i])
			return false;
	}
	moveStampAns.push_back(start);// match occurs - push index into ans and replace start to start+m	with *

	for(int i = start; i - start < m; i++) {
		stars += (target[i] != '*');
		target[i] = '*';// dont count ⬆️ if it was already star character
	}
	return true;// denotes replacement happened at index start to start + m
}
/*
int main() {
	string s = "abc", t = "ababc";
	movesToStamp(s, t);

	return 0;
}*/
