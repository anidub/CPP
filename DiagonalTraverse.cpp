#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/diagonal-traverse-ii/
 * Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.
 * Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]
https://leetcode.com/problems/diagonal-traverse-ii/discuss/599471/C%2B%2B-Single-pass-solution-using-BFS-308ms-(99.72)
https://leetcode.com/problems/diagonal-traverse-ii/discuss/597698/JavaC%2B%2B-HashMap-with-Picture-Clean-code-O(N)
 */
vector<int> diagonalTraverseOrder(vector<vector<int>>& nums) {
	if(nums.empty()) return {};
	queue<pair<int, int>> q;
	vector<int> result;
	int m = nums.size();
	q.push({0, 0});

	while(!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		result.push_back(nums[p.first][p.second]);

		if(p.second == 0 && p.first+1 < m) q.push({p.first+1, p.second});

		if(p.second + 1 < nums[p.first].size())  q.push({p.first, p.second+1});
	}
	return result;
}

vector<int> diagonalTraverseOrderMap(vector<vector<int>>& nums) {
	if(nums.empty()) return {};
	vector<int> result;
	int m = nums.size();
	int maxKey = 0;
	unordered_map<int, vector<int>> map;

	for(int r = nums.size()-1; r >= 0; r--) {
		for(int c = 0; c < nums[r].size(); c++) {
			map[r+c].push_back(nums[r][c]);
			maxKey = max(maxKey, r + c);
		}
	}

	for(int key = 0; key <= maxKey; key++) {
		for(int v : map[key])
			result.push_back(v);
	}
	return result;
}
/*
int main() {
	//[[1,2,3],[4,5,6],[7,8,9]]
	vector<vector<int>> nums;
	vector<int> n1; n1.push_back(1);n1.push_back(2);n1.push_back(3);
	vector<int> n2; n2.push_back(4);n2.push_back(5);n2.push_back(6);
	vector<int> n3; n3.push_back(7);n3.push_back(8);n3.push_back(9);
	nums.push_back(n1);nums.push_back(n2);nums.push_back(n3);
	diagonalTraverseOrder(nums);
	diagonalTraverseOrderMap(nums);
	return 0;
}
*/
