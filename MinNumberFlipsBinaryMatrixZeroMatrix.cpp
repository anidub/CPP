#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_set>
#include <queue>

using namespace std;
/*WORKS
 * https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
 * Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.
Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.
A binary matrix is a matrix with all cells equal to 0 or 1 only.
A zero matrix is a matrix with all cells equal to 0.
Example 1:
Input: mat = [[0,0],[0,1]]
Output: 3
Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
 *
 * https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/discuss/823445/C%2B%2B-concise-bfs
 */
/*
using A = vector<vector<int>>;

A transfer(A mat, const int n, const int m, int i, int j) {
	auto res = mat;
	const vector<pair<int, int>> dirs = {{0, 1},{0, -1}, {1, 0}, {-1, 0}};
	res[i][j] ^= 1;

	for(auto [dx,dy] : dirs) {
		int x = i+dx; int y = j+dy;
		if(x >= 0 && x < n && y >= 0 && y < m)
			res[x][y] ^= 1;
	}
	return res;
}

A getNeighbors(A mat, int n, int m) {
	vector<A> res;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			res.emplace_back(transfer(mat, n, m, i, j));
		}
	}
	return res;
}

int minFlips(vector<vector<int>>& mat) {
	const n = mat.size(), m = mat[0].size();
	A dest = vector(n, vector(m, 0));
	if(dest == mat) return 0;
	queue<pair<A, int>> q;
	q.push(pair(mat, 0));
	set<A> visited = {mat};

	while(!q.empty()) {
		auto [a, step] = move(q.front());
		q.pop();
		for(auto neighbor : getNeighbors(a, n, m)) {
			if(neighbor == dest) return step+1;
			if(visited.count(neighbor)) continue;
			visited.insert(neighbor);
			q.push(pair(move(neighbor), step+1));
		}
	}
	return -1;
}


int main() {
	vector<vector<int>> mat;
	vector<int> v1; v1.push_back(1);v1.push_back(1);v1.push_back(1);
	vector<int> v2; v2.push_back(1);v2.push_back(0);v2.push_back(1);
	vector<int> v3; v3.push_back(0);v3.push_back(0);v3.push_back(0);
	mat.push_back(v1);mat.push_back(v2);mat.push_back(v3);

	cout << minFlips(mat) << endl;

	return 0;
}
*/
