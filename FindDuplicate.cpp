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
 * https://leetcode.com/problems/find-the-duplicate-number/
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
 * https://leetcode.com/problems/find-the-duplicate-number/discuss/401785/Easy-to-understand-C%2B%2B-Solution-8ms-beats-97
 *
 */
int findDuplicate(vector<int>& nums) {
	if(nums.empty()) return -1;



	int slow = 0, fast = 0;

	while(true) {
		slow = nums[slow];
		fast = nums[nums[fast]];
		if(slow == fast) break;
	}

	fast = 0;
	while(slow != fast) {
		slow = nums[slow];
		fast = nums[fast];
	}
	return slow;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(3);nums.push_back(1);nums.push_back(3);nums.push_back(4);nums.push_back(2);
	cout << findDuplicate(nums) << endl;

	return 0;
}
*/
