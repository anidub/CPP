#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
 * You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
 */

typedef pair<int, pair<int, int>> pi;

//TC: O(N), SC:O(N)
vector<int> smallestRangeKLists(vector<vector<int>>& nums) {
	if(nums.empty()) return {};

	int mx = INT_MIN, mn = INT_MAX;
	priority_queue<pi, vector<pi>, greater<pi>> pq;

	for(int i = 0; i < nums.size(); i++) {
		pq.push({nums[i][0], {i, 0}});
		mx = max(mx, nums[i][0]);
		mn = min(mn, nums[i][0]);
	}
	int a = mn, b = mx;

	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if(cur.second.second + 1 < nums[cur.second.first].size()) {
			int r = cur.second.first, c = cur.second.second + 1;
			pq.push({nums[r][c], {r, c}});
			mn = pq.top().first;
			mx = max(mx, nums[r][c]);
			if(b - a > mx - mn) {
				b = mx;
				a = mn;
			}
		} else
			break;
	}
	return {a, b};
}
/*
int main() {
	vector<vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
	smallestRangeKLists(nums);
	return 0;
}*/
