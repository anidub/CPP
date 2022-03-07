#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <deque>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * Given an array of integers, 1 <= a[i] <= n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
Could you do it without extra space and in O(n) runtime?
Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/218343/C%2B%2B-Radix-Sort
https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/249676/C%2B%2B-solution
 *
 */

vector<int> findDuplicatesOrderN(vector<int>& nums) {
	if(nums.size() == 0) return {};
	vector<int> result;

	for(int n : nums) {
		n = abs(n);
		nums[n-1] = -nums[n-1];
		if(nums[n-1] > 0)
			result.push_back(n);
	}
	return result;
}
//uses radix sort. the constraint in problem is num in nums can be no more than size of nums
vector<int> findDuplicatesRadixSort(vector<int>& nums) {
	if(nums.size() == 0) return {};
	vector<int> result;
	int i = 0;
	while(i < nums.size()) {
		while(nums[i] != nums[nums[i] - 1]) {
			//swap(nums[i], nums[nums[i] - 1]); //works
		}
	}

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] != i+1)
			result.push_back(nums[i]);
	}
	return result;
}
/*
int main () {
	vector<int> nums;
	nums.push_back(4);nums.push_back(3);nums.push_back(2);nums.push_back(7);nums.push_back(8);
	nums.push_back(2);nums.push_back(3);nums.push_back(1);
	findDuplicatesOrderN(nums);
	return 0;
}
*/
