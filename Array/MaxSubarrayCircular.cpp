#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_set>
#include <set>

using namespace std;
/*https://leetcode.com/problems/maximum-sum-circular-subarray/
 * Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/633058/Java-or-C%2B%2B-or-Python3-or-With-detailed-explanation-or-O(N)-time-or-O(1)
 *
 */
//Time :- O(N) Space :- O(1)
int maxSubArrayCircular(vector<int>& nums) {
	if(nums.empty()) return 0;
	int maxSoFar = nums[0], maxTotal = nums[0];
	int minSoFar = nums[0], minTotal = nums[0];
	int sum = nums[0];

	for(int i = 1; i < nums.size(); i++) {
		maxSoFar = max(nums[i], maxSoFar + nums[i]);
		maxTotal = max(maxTotal, maxSoFar);

		minSoFar = min(nums[i], minSoFar + nums[i]);
		minTotal = min(minTotal, minSoFar);

		sum += nums[i];
	}

	if(sum == minTotal) return maxTotal;
	return max(maxTotal, sum - minTotal);
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(-2);nums.push_back(3);nums.push_back(-2);
	cout << maxSubArrayCircular(nums) << endl;
	return 0;
}*/
