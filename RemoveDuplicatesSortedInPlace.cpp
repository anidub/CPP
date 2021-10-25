#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.

https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/587297/Simlpe-C%2B%2B-Implementation
https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/682430/C%2B%2B-solution
 */

int removeDuplicatesSortedSimple(vector<int>& nums) {
	if(nums.size() == 0 || nums.size() == 1) return nums.size();
	for(int i = 0; i < nums.size() - 1;) {
		if(nums[i] == nums[i+1]) {
			nums.erase(nums.begin() + i);
		} else
			i++;
	}
	return nums.size();
}

int removeDuplicatesSorted(vector<int>& nums) {
	if(nums.size() == 0 || nums.size() == 1) return nums.size();
	int shift = 0;
	for(int i = 1; i < nums.size(); i++) {
		if(nums[shift] != nums[i]) {
			nums[++shift] = i;
		}
	}
	return shift + 1;
}

/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(1);nums.push_back(2);
	cout << removeDuplicatesSortedSimple(nums) << endl;
	cout << removeDuplicatesSorted(nums) << endl;
	return 0;
}*/
