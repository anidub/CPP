#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/
 * Understand KMP algo
 * You are given a 2D integer array groups of length n. You are also given an integer array nums.
You are asked if you can choose n disjoint subarrays from the array nums such that the ith subarray is equal to groups[i] (0-indexed), and if i > 0, the (i-1)th subarray appears before the ith subarray in nums (i.e. the subarrays must be in the same order as groups).
Return true if you can do this task, and false otherwise.
Note that the subarrays are disjoint if and only if there is no index k such that nums[k] belongs to more than one subarray. A subarray is a contiguous sequence of elements within an array.
Example 1:
Input: groups = [[1,-1,-1],[3,-2,0]], nums = [1,-1,0,1,-1,-1,3,-2,0]
Output: true
Explanation: You can choose the 0th subarray as [1,-1,0,1,-1,-1,3,-2,0] and the 1st one as [1,-1,0,1,-1,-1,3,-2,0].
These subarrays are disjoint as they share no common nums[k] element.
https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/discuss/1074946/C%2B%2B-Simple-Search-%2B-KMP
https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/discuss/1074544/C%2B%2B-KMP-Solution-or-O(M%2BN)-Time-or-O(N)-Space
https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/discuss/1074554/simple-CPP-solution-using-STL-search-function
 */
bool arrayCanChoose(vector<vector<int>>& groups, vector<int>& nums, int i = 0, int j = 0) {
	if(i >= groups.size())
		return true;

	for(; j <= nums.size() - groups[i].size(); j++) {
		for(auto gi = 0; gi <= groups[i].size(); gi++) {
			if(gi == groups[i].size())
				return arrayCanChoose(groups, nums, i+1, j + groups[i].size());
			if(nums[j + gi] != groups[i][gi])
				break;
		}
	}
	return false;
}

bool arrayCanChoose_kmp(vector<vector<int>>& groups, vector<int>& nums, int i = 0, int j = 0) {
	int n = nums.size();
	int index = 0;
	for(auto& group: groups) {
		int m = group.size();
		vector<int> arr(m, 0);
		int i = 0, j = 1;
		while(j < m){
			if(group[i] == group[j]) {
				i++;
				arr[j] = i;
				j++;
			} else if(i == 0) {
				arr[j] = 0;
				j++;
			} else {
				i = arr[i-1];
			}
		}
		j = 0;
		while(index < n) {
			if(nums[index] == group[j]) {
				j++;
				index++;
			}
			if(j == m)
				break;
			if(index < n && nums[index] != group[j]) {
				if(j > 0)
					j = arr[j-1];
				else
					index++;
			}
		}
		if(j != m)
			return false;
	}
	return true;
}
/*
int main() {
	vector<vector<int>> groups;
	vector<int> group; group.push_back(1);group.push_back(-1);group.push_back(-1);
	vector<int> group1; group1.push_back(3);group1.push_back(-2);group1.push_back(0);
	groups.push_back(group); groups.push_back(group1);

	vector<int> nums;
	nums.push_back(1);nums.push_back(-1);nums.push_back(0);nums.push_back(1);nums.push_back(-1);
	nums.push_back(-1);	nums.push_back(3);nums.push_back(-2);nums.push_back(0);

	//cout << arrayCanChoose(groups, nums);

	cout << arrayCanChoose_kmp(groups, nums);

	return 0;
}
*/
