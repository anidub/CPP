#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
 * You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/discuss/935956/C%2B%2B-O(n)-Two-Sum-and-Hash-Map : comments
        // example
        // [1,1,4,2,3] , x=5
        // target = sum(nums)-x, which is => 6 in this case
        // we will try to find longest subarray with given target
        // max length with target is 3 [1,1,4]
        // our ans is nums.size()-3 => 2
 */
//O(N)
int minOperationReduceXZero(vector<int>& nums, int x) {
	if(nums.empty()) return -1;
	int sum = 0, left = 0, right = 0, n = nums.size();
	int cur = 0; int result = -1;
	for(int& i : nums) sum += i;
	if(x > sum) return -1;

	for(; right < n; right++) {
		cur += nums[right];
		while(cur > sum -  x && left <= right){
			cur -= nums[left];
			left++;
		}
		if(cur == sum - x)
			result = max(result, right - left + 1);
	}
	if(result == -1) return result;
	return n - result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(1);nums.push_back(4);
	nums.push_back(2);nums.push_back(3);
	cout << minOperationReduceXZero(nums, 4) << endl;
	return 0;
}*/
