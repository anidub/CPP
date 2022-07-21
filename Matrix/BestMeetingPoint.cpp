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
/*https://leetcode.com/problems/best-meeting-point/
 * Given an m x n binary grid grid where each 1 marks the home of one friend, return the minimal total travel distance.

The total travel distance is the sum of the distances between the houses of the friends and the meeting point.

The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
Input: grid = [[1,0,0,0,1],
				[0,0,0,0,0],
				[0,0,1,0,0] ]
Output: 6
Explanation: Given three friends living at (0,0), (0,4), and (2,2).
The point (0,2) is an ideal meeting point, as the total travel distance of 2 + 2 + 2 = 6 is minimal.
So return 6.

https://www.youtube.com/watch?v=yKVzFQ4fcYA : well explained
https://leetcode.com/problems/best-meeting-point/discuss/74240/Accepted-C%2B%2B-solution
 */
//TC: O(MNLOGMN), SC: O(MN)
int minTotalDistance(vector<vector<int>>& grid) {
	if(grid.empty()) return 0;

	vector<int> row;
	vector<int> col;

	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			if(grid[i][j]) {
				row.push_back(i);
				col.push_back(j);
			}
		}
	}
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());

	int mid_row = row.size() % 2 ? row[row.size() / 2] : (row[row.size() / 2] + row[row.size() / 2 - 1] ) / 2;
	int mid_col = col.size() % 2 ? col[col.size() / 2] : (col[col.size() / 2] + col[col.size() / 2 - 1] ) / 2;

	int dist = 0;

	for(int i = 0; i < row.size(); i++)
		dist += abs(mid_row - row[i]);

	for(int j = 0; j < col.size(); j++)
		dist += abs(mid_col - col[j]);

	return dist;
}
/*
int main() {
	vector<vector<int>> grid = {{1,0,0,0,1},{0,0,0,0,0},{0,0,1,0,0}};
	cout << minTotalDistance(grid) << endl;

	return 0;
}*/
