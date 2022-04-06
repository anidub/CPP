#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/split-array-with-equal-sum/
 * Given an integer array nums of length n, return true if there is a triplet (i, j, k) which satisfies the following conditions:

0 < i, i + 1 < j, j + 1 < k < n - 1
The sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) is equal.
A subarray (l, r) represents a slice of the original array starting from the element indexed l to the element indexed r.

Input: nums = [1,2,1,2,1,2,1]
Output: true
Explanation:
i = 1, j = 3, k = 5.
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1

https://leetcode.com/problems/split-array-with-equal-sum/discuss/101481/Simple-Java-solution-O(n2) : comments
https://leetcode.com/problems/split-array-with-equal-sum/discuss/1353399/C%2B%2B-clean-code-with-hash-set

Explanation: solution
 */
//TC: O(n^2), SC: O(N) (can be avoid is used input param itself)
bool splitArray(vector<int>& nums) {
	if(nums.size() < 7) return false;
	int n = nums.size();
	vector<int> sums(n, nums[0]);

	for(int i = 1; i < n; i++) {
		sums[i] = sums[i - 1] + nums[i];
	}

	for(int j = 3; j < n - 3; j++) {
		unordered_set<int> st;

		for(int i = 1; i < j - 1; i++) {
			if(sums[i - 1] == sums[j - 1] - sums[i])
				st.insert(sums[i - 1]);
		}
		for(int k = j + 2; k < n - 1; k++) {
			if(sums[n - 1] - sums[k] == sums[k - 1] - sums[j] && st.count(sums[k - 1] - sums[j] ) )
				return true;
		}
	}
	return false;
}
/*
int main() {
	vector<int> nums = {1, 2, 1, 2, 1, 2, 1};
	cout << splitArray(nums) << endl;

	return 0;
}*/
