#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <queue>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/snakes-and-ladders/
 * find steps required to reach from bottom left to top left
 * Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation:
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.

https://leetcode.com/problems/snakes-and-ladders/discuss/722918/c%2B%2B-bfs-easy-solution-with-explanation
https://www.youtube.com/watch?v=zWS2fCJGxmU : well explained
 */
pair<int, int> findCoordinates(int cur, int n);
//TC: O(n^2)
int snakesAndLaddersSteps(vector<vector<int>>& board) {
	if(board.empty()) return -1;
	int n = board.size();
	queue<int> q;
	vector<vector<bool>> visited(n, vector<bool>(n));// so that we are not trapped in a loop
	q.push(1); visited[n - 1][0] = true;//bottom left element
	int steps = 0;

	while(!q.empty()) {// work until the queue is empty
		int sz = q.size();
		for(int i = 0; i < sz; i++) {// for each step use all the elements in the queue
			int x = q.front(); q.pop();
			if(x == n * n) return steps;
			for(int k = 1; k <= 6; k++) {// all possible moves dice has 1 to 6
				if(k + x > n * n) break; // out of bounds
				pair<int, int> p = findCoordinates(x + k, n); //x + k : next element

				if(visited[p.first][p.second]) continue;
				visited[p.first][p.second] = true;

				if(board[p.first][p.second] != -1)// mean snake or ladder present at this place
					q.push(board[p.first][p.second]);
				else // its -1 and unvisited
					q.push(k + x);
			}
		}
		steps++;
	}
	return -1;
}

pair<int, int> findCoordinates(int cur, int n) {// find the coordinates given integer
	int r = n - (cur - 1)/n - 1; // from try and hit
	int c = (cur - 1) % n;
	if(r % 2 == n % 2) // if r == odd
		return {r, n - c - 1};
	else
		return {r, c};
}
/*
int main() {
	vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,35,-1,-1,13,-1}, {-1,-1,-1,-1,-1,-1}
	, {-1,15,-1,-1,-1,-1}};
	cout << snakesAndLaddersSteps(board) << endl;

	return 0;
}*/
