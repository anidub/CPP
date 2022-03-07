#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <stack>

using namespace std;
/*
 * https://xingxingpark.com/Leetcode-1063-Number-of-Valid-Subarrays/
 * Given an array A of integers, return the number of non-empty continuous subarrays that satisfy the following condition:
The leftmost element of the subarray is not larger than other elements in the subarray.
Example 1:
Input: [1,4,2,5,3]
Output: 11
Explanation: There are 11 valid subarrays: [1],[4],[2],[5],[3],[1,4],[2,5],[1,4,2],[2,5,3],[1,4,2,5],[1,4,2,5,3].
 */
//time: O(n), space : O(n)
int numberValidSubarrays(vector<int>& nums) {
	if(nums.empty()) return 0;
	stack<int> stk;
	int count = 0;
	for(int& num : nums) {
		while(!stk.empty() && num < stk.top()) {
			stk.pop();
		}
		stk.push(num);
		count += stk.size();
	}
	return count;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(4);nums.push_back(2);nums.push_back(5);nums.push_back(3);
	cout << numberValidSubarrays(nums) << endl;

	return 0;
}*/
