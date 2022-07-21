#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/single-element-in-a-sorted-array/
 * You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/1587257/C%2B%2B-EASY-Intuitive-Solutionoror-2-approaches-oror-Binary-Search-oror-TC%3AO(log(N))-SC%3AO(1)
 */
//Time Complexity: O(Log(N)) Space Complexity: O(1)
int singleNonDuplicate(vector<int>& nums) {
	if(nums.empty()) return 0;

	int low = 0, high = nums.size() - 2;

	while(low <= high) {
		int mid = low + (high - low) / 2;

		if( (mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
			(mid % 2 == 1 && nums[mid] == nums[mid - 1]) ) {
			low = mid + 1;
		} else
			high = mid - 1;
	}
	return nums[low];
}

/*
int main() {
	vector<int> nums = {1, 1, 2, 3, 3, 4 ,4, 8, 8};
	cout << singleNonDuplicate(nums) << endl;

	return 0;
}*/
