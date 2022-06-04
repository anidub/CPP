#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <set>

using namespace std;
#define ll long long
/*
 * https://leetcode.com/problems/4sum/
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
https://leetcode.com/problems/4sum/discuss/8563/Clean-C%2B%2B-19ms-backtracking-81.90 : DFS

https://leetcode.com/problems/4sum/discuss/1546550/C%2B%2B-oror-two-pointer-oror-Beats-more-then-88-oror-very-simple-to-understand : USED
 */
//O(N3)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	if(nums.empty()) return {};
	set<vector<int>> s;
	sort(nums.begin(), nums.end());
	int n = nums.size();

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			int start = j+1;
			int end = n-1;

			while(start < end) {
				ll sum = (ll)nums[i] + (ll)nums[j] + (ll)nums[start] + (ll)nums[end];
				if(sum < target) start++;
				else if(sum > target) end--;
				else{
					vector<int> temp = {nums[i], nums[j], nums[start], nums[end]};
					s.insert(temp);
					start++; end--;
				}
			}
		}
	}
	vector<vector<int>> ans(s.begin(), s.end());
	return ans;
}
/*
int main() {
	vector<int> nums; nums.push_back(1);nums.push_back(0);nums.push_back(-1);nums.push_back(0);nums.push_back(-2);nums.push_back(2);
	fourSum(nums, 0);
	return 0;
}*/
