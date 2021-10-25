#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/valid-triangle-number/
 * Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
https://leetcode.com/problems/valid-triangle-number/discuss/398569/c%2B%2B-O(n2)
https://leetcode.com/problems/valid-triangle-number/discuss/104183/C%2B%2B-Clean-Code : using binary search
 */

int getTriangles(vector<int>& nums) {
	if(nums.empty()) return 0;
	sort(nums.begin(), nums.end());
	int count = 0;

	for(int i = nums.size() - 1; i > 1; i--) {
		int left = 0; int right = i-1;
		while(left < right) {
			if(nums[left] + nums[right] > nums[i]) {
				count += right - left;
				right--;
			} else
				left++;
		}
	}
	return count;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(2);nums.push_back(3);nums.push_back(4);
	cout << getTriangles(nums) << endl;
	return 0;
}
*/
