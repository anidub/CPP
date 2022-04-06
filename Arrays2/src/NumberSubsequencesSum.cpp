#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
 *You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target
Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]

https://www.youtube.com/watch?v=xCsIkPLS4Ls
https://www.youtube.com/watch?v=GVhvTNyPIzE : used
https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/discuss/709227/JavaC%2B%2BPython-Two-Sum
Sort input A first,
For each A[i], find out the maximum A[j]
that A[i] + A[j] <= target.

For each elements in the subarray A[i+1] ~ A[j],
we can pick or not pick,
so there are 2 ^ (j - i) subsequences in total.
So we can update res = (res + 2 ^ (j - i)) % mod.

We don't care the original elements order,
we only want to know the count of sub sequence.
So we can sort the original A, and the result won't change.

 */
//Time O(NlogN) Space: O(N)
int numSubSeq(vector<int> &nums, int target) {
	if(nums.empty()) return 0;
	const int mod = 1e9 + 7;
	vector<int> exps(nums.size(), 1);

	for(int i = 1; i < exps.size(); i++)
		exps[i] = (2 * exps[i - 1]) % mod;

	sort(nums.begin(), nums.end());
	int left = 0, right = nums.size() - 1;
	int count = 0;

	while(left <= right) {
		if(nums[left] + nums[right] > target) right--;
		else {
			count = (count + exps[right - left]) % mod;
			left++;
		}
	}
	return count;
}
/*
int main() {
	vector<int> nums = {3, 3, 6 ,8};
	cout << numSubSeq(nums, 10) << endl;

	return 0;
}
*/
