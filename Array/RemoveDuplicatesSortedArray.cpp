#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3]
Explanation: Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively. It doesn't matter what you leave beyond the returned length.
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/27976/3-6-easy-lines-C%2B%2B-Java-Python-Ruby
O(N)
 */
int removeDuplicatesSortedArrayMoreThan2(vector<int>& nums) {
	if(nums.empty()) return 0;
	int counter = 0;
	for(int& n : nums) {
		if(counter < 2 || n > nums[counter-2])
			nums[counter++] = n;
	}
	return counter;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(1);nums.push_back(1);nums.push_back(2);nums.push_back(2);nums.push_back(3);
	cout << removeDuplicatesSortedArrayMoreThan2(nums) << endl;
	return 0;
}*/
