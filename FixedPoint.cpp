#include <iostream>
#include <vector>

using namespace std;


/*
 * [Leetcode 1064] Fixed Point
 * Given an array A of distinct integers sorted in ascending order, return the smallest index i that satisfies A[i] == i.  Return -1 if no such i exists.
 * Input: [-10,-5,0,3,7]
Output: 3
Explanation:
For the given array, A[0] = -10, A[1] = -5, A[2] = 0, A[3] = 3, thus the output is 3.
https://xingxingpark.com/Leetcode-1064-Fixed-Point/
 *
 */
int fixedpoint(vector<int>& nums) {
	if(nums.size() == 0)
		return 0;
	int left = 0; int right = nums.size()-1;
	while(left + 1 < right) {
		int mid = left + (right-left)/2;
		if(nums[mid] >= mid) {
			right = mid;
		} else {
			left = mid;
		}
	}
	if(nums[left] == left)
		return left;
	else if(nums[right] == right)
		return right;

	return -1;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(-10);nums.push_back(-5);nums.push_back(0);nums.push_back(3);nums.push_back(7);

	cout << fixedpoint(nums) << endl;
} */
