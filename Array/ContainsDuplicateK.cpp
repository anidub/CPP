#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/contains-duplicate-ii/
 * Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true
https://leetcode.com/problems/contains-duplicate-ii/discuss/501105/C%2B%2B-solution.
https://leetcode.com/problems/contains-duplicate-ii/discuss/61546/C%2B%2B-short-solution.

 */
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	if(nums.size() == 0) return false;
	set<int> set1;
	for(int i = 0; i < nums.size(); i++) {
		if(set1.find(nums[i]) != set1.end())
			return true;
		set1.insert(nums[i]);
		if(set1.size() > k)
			set1.erase(nums[i-k]);
	}
	return false;
}


bool containsNearbyDupOptimal(vector<int>& nums, int k) {
	if(nums.size() == 0) return false;
	unordered_map<int, int> umap;

	for(int i = 0; i < nums.size(); i++) {
		if(umap.find(nums[i]) != umap.end() && i - umap[nums[i]] <= k)
			return true;
		umap[nums[i]] = i;
	}
	return false;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);nums.push_back(1);
	cout << containsNearbyDuplicate(nums, 3) << endl;
	cout << containsNearbyDupOptimal(nums, 3) << endl;
	return 0;
}
*/
