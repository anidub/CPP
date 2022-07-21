#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <queue>
#include <set>

using namespace std;
/*https://leetcode.com/problems/minimum-knight-moves/
 * In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]
https://www.youtube.com/watch?v=R8-5Z0cpl3E : used
https://leetcode.com/problems/minimum-knight-moves/discuss/501701/Clean-and-Concise-C%2B%2B-Solution-BFS : similar
 */
//O( max(|x||y|) ^ 2), SC : O( max(|x||y|) ^ 2)
int minKnightMoves(int x, int y) {
	x = abs(x), y = abs(y);

	vector<pair<int, int>> dirs = {{-2, -1}, {-2, 1}, {2, -1}, {-1, -2}, {2, 1}, {-1, 2}, {1, -2}, {1, 2}};

	queue<pair<int, int>> q;
	q.push({0, 0});
	set<pair<int, int>> visited;//In C++ unordered_sets only work with primitive data types.need hashing function to the unordered_set for the pair of coordinates that has minimal collisions.
	visited.insert({0, 0});
	int steps = 0;

	while(!q.empty()) {
		int sz = q.size();

		for(int i = 0; i < sz; i++) {
			auto p = q.front(); q.pop();
			int curX = p.first, curY = p.second;
			if(curX == x && curY == y) return steps;

			for(auto dir : dirs) {
				int newX = curX + dir.first, newY =  curY + dir.second;
				pair<int, int> newP = {newX, newY};
				if(visited.find(newP) != visited.end() || newX < -1  || newY < -1) //so it does not out of bounds as x,y are absolute vals
					continue;
				q.push({newX, newY});
				visited.insert(newP);
			}
		}
		steps++;
	}
	return 0;
}
/*
int main() {
	cout << minKnightMoves(2, 1) << endl;

	return 0;
}*/
