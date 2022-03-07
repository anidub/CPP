#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*
 *https://leetcode.com/problems/count-servers-that-communicate/
 *You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.
https://leetcode.com/problems/count-servers-that-communicate/discuss/437145/Simple-C%2B%2B-Solution-O(m*n)
 O(m*n)
 */

int countServers(vector<vector<int>>& grid) {
	int result = 0;
	if(grid.empty()) return result;
	int m = grid.size();
	int n = grid[0].size();

	vector<int> row(m, 0);
	vector<int> col(n, 0);

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == 1) {
				row[i]++;
				col[j]++;
			}
		}
	}

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == 1 && (row[i] > 1 || col[j] > 1))
				result++;
		}
	}
	return result;
}
/*
int main() {
	vector<vector<int>> grid;
	vector<int> nums; nums.push_back(1);nums.push_back(0);
	vector<int> nums1; nums1.push_back(0);nums1.push_back(1);
	grid.push_back(nums);grid.push_back(nums1);
	cout << countServers(grid) << endl;

	return 0;
}*/
