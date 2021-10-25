#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/maximum-subarray/
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
https://leetcode.com/problems/maximum-subarray/discuss/762682/C%2B%2B-O(n)
https://leetcode.com/problems/maximum-subarray/discuss/553352/c%2B%2B-0ms-greedy
https://leetcode.com/problems/maximum-subarray/discuss/20452/C%2B%2B-DP-and-Divide-and-Conquer
 */

int maxSubArray(vector<int>& nums) {
	if(nums.empty()) return INT_MIN;
	int result = INT_MIN;
	int current = 0;

	for(int i : nums) {
		current = max(i, current + i);
		cout << "current:" << current << endl;
		result = max(result, current);
		cout << "result:" << result << endl;
	}
	return result;
}

//DP //https://leetcode.com/problems/maximum-subarray/discuss/20452/C%2B%2B-DP-and-Divide-and-Conquer
int maxSubArrayOther(vector<int>& nums) {
    int sum = 0, smax = INT_MIN;
    for (int num : nums) {
        sum += num;
        smax = max(smax, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return smax;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(-2);nums.push_back(1);nums.push_back(-3);nums.push_back(4);
	nums.push_back(-1);nums.push_back(2);nums.push_back(1);nums.push_back(-5);
	nums.push_back(4);

	cout << maxSubArray(nums);
	return 0;
}
*/
