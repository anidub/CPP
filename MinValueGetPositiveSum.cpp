#include <iostream>
#include <vector>

using namespace std;
/*
 * Given an array of integers nums, you start with an initial positive value startValue.

In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).

Return the minimum positive value of startValue such that the step by step sum is never less than 1.



Example 1:

Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
                step by step sum
                startValue = 4 | startValue = 5 | nums
                  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
                  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
                  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
                  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
                  (4 +2 ) = 6  | (5 +2 ) = 7    |   2


 * https://www.youtube.com/watch?v=RarK0CNiQbk
 * https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/discuss/585560/C%2B%2BJava-O(n)
 */

int minStartVale(vector<int>& nums) {
	if(nums.size() == 0)
		return -1;
	int min_value = 0;
	int running_sum = 0;
	for(int n : nums) {
		running_sum += n;
		min_value = std::min(min_value, running_sum);
	}
	return 1 - min_value;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(-3);nums.push_back(2);nums.push_back(-3);nums.push_back(4);nums.push_back(2);
	cout << minStartVale(nums) << endl;

	return 0;
}
*/
