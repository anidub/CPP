#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/132-pattern/
 * Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
Return true if there is a 132 pattern in nums, otherwise, return false.
Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
https://leetcode.com/problems/132-pattern/discuss/94071/Single-pass-C%2B%2B-O(n)-space-and-time-solution-(8-lines)-with-detailed-explanation.
 */
//time : O(N); space : O(N)
bool find132Pattern(vector<int>& nums) {
	int s3 = INT_MIN;
	stack<int> stk;
	for(int i = nums.size() - 1; i >=0; i--) {
		if(nums[i] < s3) return true;
		else {
			while(!stk.empty() && nums[i] > stk.top()) {
				s3 = stk.top();
				stk.pop();
			}
		}
		stk.push(nums[i]);
	}
	return false;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(-1);nums.push_back(3);nums.push_back(2);nums.push_back(0);
	cout << find132Pattern(nums) << endl;

	return 0;
}*/
