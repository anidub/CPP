#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/minimize-deviation-in-array/
 * You are given an array nums of n positive integers.
You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.
Return the minimum deviation the array can have after performing some number of operations.
Example 1:

Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
https://leetcode.com/problems/minimize-deviation-in-array/discuss/955262/C%2B%2B-intuitions-and-flip
 */
//tc O(nlogn) due to priority queue, Space O(n)
int minDeviationArray(vector<int>& nums) {
	if(nums.empty()) return 0;
	int res = INT_MAX, min_n = INT_MAX;
	priority_queue<int> pq;

	for(int& n : nums) {
		n = n % 2 == 1 ? n * 2 : n;
		pq.push(n);
		min_n = min(min_n, n);
	}

	while(pq.top() % 2 == 0) {
		res = min(res, pq.top() - min_n);
		min_n = min(min_n, pq.top() / 2);
		pq.push(pq.top() / 2);
		pq.pop();
	}

	return min(res, pq.top() - min_n);
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);nums.push_back(4);
	cout << minDeviationArray(nums) << endl;
	return 0;
}
*/
