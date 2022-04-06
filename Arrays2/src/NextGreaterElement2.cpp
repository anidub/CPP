#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;

/*https://leetcode.com/problems/next-greater-element-ii/
 * Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
 * Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.

https://leetcode.com/problems/next-greater-element-ii/discuss/98270/JavaC%2B%2BPython-Loop-Twice

Loop once, we can get the Next Greater Number of a normal array.
Loop twice, we can get the Next Greater Number of a circular array
 */
//Time O(N) for one pass Space O(N) in worst case
vector<int> nextGreaterElements(vector<int>& nums) {
	if(nums.empty()) return {};
	int n = nums.size();
	vector<int> stack, res(n, -1);

	for(int i = 0; i < n * 2; i++) {
		while(!stack.empty() && nums[stack.back()] < nums[i % n]) {
			res[stack.back()] = nums[i % n];
			stack.pop_back();
		}
		stack.push_back(i % n);
	}
	return res;
}

/*
int main() {
	vector<int> nums = {1,2,3,4,3};
	nextGreaterElements(nums);

	return 0;
}*/
