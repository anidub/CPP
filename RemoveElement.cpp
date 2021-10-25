#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/remove-element/
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length. For example if you return 2 with nums = [2,2,3,3] or nums = [2,2,0,0], your answer will be accepted.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3]
Explanation: Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
Note that the order of those five elements can be arbitrary. It doesn't matter what values are set beyond the returned length.

https://leetcode.com/problems/remove-element/discuss/589775/C%2B%2B-simple-solution
https://leetcode.com/problems/remove-element/discuss/607745/C%2B%2B-or-easy-solution

 */
int removeElement(vector<int>& nums, int val) {
	if(nums.size() == 0) return 0;
	if(nums.size() == 1 && nums[0] == val) return 0;

	for(auto it = nums.begin(); it != nums.end(); it++) {
		if(*it == val) {
			nums.erase(it);
			it--;
		}
	}
	return nums.size();
}

int removeElementOther(vector<int>& nums, int val) {
	if(nums.size() == 0) return 0;
	if(nums.size() == 1 && nums[0] == val) return 0;

	int i = 0, j = 0, n = nums.size();
	while(i < n) {
		if(nums[i] != val) {
			nums[i] = nums[j];
			j++;
		}
		i++;
	}
	return j;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(0);nums.push_back(1);nums.push_back(2);nums.push_back(2);
	nums.push_back(3);nums.push_back(0);nums.push_back(4);nums.push_back(2);
	cout << removeElement(nums, 2) << endl;
	cout << removeElementOther(nums, 2) << endl;
	return 0;
}*/
