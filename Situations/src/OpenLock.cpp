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
/*https://leetcode.com/problems/open-the-lock/
 * You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".

https://leetcode.com/problems/open-the-lock/discuss/110230/BFS-solution-C%2B%2B
https://www.youtube.com/watch?v=vtxETRvR9JY : explained
 */
vector<string> turn(string s, int i);

/*Time: O(N^2 * A^N + D)where, N is Number of dials (4 in our case) A is number of alphabets (10 in our case -> 0 to 9) D is the size of deadends.
There are 10 x 10 x 10 x 10 possible combinations => 10^4 => A^N
For each combination, we are looping 4 times (which is N) and in each iteration, there are substring operations ( which is O(N) * constant) => O(4N*constant) => O(4N) => O(NN) => O(N^2)
Total complexity => A^N * N^2, plus D to create the hashset => N^2 * A^N + D
Space: O(A^N)
 */

int openLock(vector<string> &deadends, string target) {
	if(target.empty()) return 0;

	unordered_set<string> dead(deadends.begin(), deadends.end()), seen({"0000"});

	if(dead.find("0000") != dead.end()) return -1; // if start string itself is a deadend
	if(target == "0000") return 0;// if start string itself is the target string.

	queue<string> q; q.push({"0000"});
	int minTurns = 0;

	while(!q.empty()) {
		int sz = q.size();
		minTurns++;

		for(int i = 0; i < sz; i++) {// traversing all nodes on the current level of BFS traversal
			auto cur_str = q.front(); q.pop();
			for(int j = 0; j < 4; j++) {// Trying forward and backward turn for each digit of current string
				for(auto adj_str : turn(cur_str, j)) {
					if(dead.find(adj_str) == dead.end() && seen.find(adj_str) == seen.end()) {// adjacent (turned) string is not visited earlier, nor a dead end
						if(adj_str == target) return minTurns;
						else q.push(adj_str), seen.insert(adj_str);
					}
				}
			}
		}
	}
	return -1;
}

// turns the ith digit of s in forward and backward direction and returns the turned string as vector
vector<string> turn(string s, int i) {
	vector<string> res(2, s);

	res[0][i] = '0' + (res[0][i] - '0' + 1) % 10;// forward turn
	res[1][i] = '0' + (res[1][i] - '0' - 1 + 10) % 10;// backward turn

	return res;
}
/*
int main() {
	vector<string> deadends = {"0201","0101","0102","1212","2002"};
	string target = "0202";
	cout << openLock(deadends, target) << endl;

	return 0;
}*/
