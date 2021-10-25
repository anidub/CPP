#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
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
https://leetcode.com/problems/4sum/discuss/8686/C%2B%2B-implementation-with-carefully-pruning-accelerates-a-lot-!-from-100ms-to-16ms-!
https://leetcode.com/problems/4sum/discuss/8563/Clean-C%2B%2B-19ms-backtracking-81.90 : DFS
 */
//O(N3)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;
	int n = nums.size();
	if(n < 4) return result;
	sort(nums.begin(), nums.end());

	for(int i = 0; i < n-3; i++) {
		if(i > 0 && nums[i] == nums[i-1]) continue;
		if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
		if(nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;
		for(int j = i+1; j < n-2; j++) {
			if(j > i+1 && nums[j] == nums[j-1]) continue;
			if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
			if(nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;
			int left = j+1, right = n-1;
			while(left < right) {
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if(sum < target) left++;
				else if(sum > target) right--;
				else {
					result.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
					left++; right--;
					while(left < right && nums[left] == nums[left-1]) left++;
					while(left < right && nums[right] == nums[right+1]) right--;
				}
			}
		}
	}
	return result;
}
/*
int main() {
	vector<int> nums; nums.push_back(1);nums.push_back(0);nums.push_back(-1);nums.push_back(0);nums.push_back(-2);nums.push_back(2);
	fourSum(nums, 0);
	return 0;
}
*/
