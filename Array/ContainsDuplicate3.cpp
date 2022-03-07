#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <set>
#include <queue>

using namespace std;
/*
 * https://leetcode.com/problems/contains-duplicate-iii/
 * Given an integer array nums and two integers k and t, return true if there are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.
Example 1:
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
https://leetcode.com/problems/contains-duplicate-iii/discuss/61641/C%2B%2B-using-set-(less-10-lines)-with-simple-explanation.
 */
//time: O(n*log(k))
bool containsDuplicate3(vector<int>& nums, int k, int t) {
	if(nums.empty()) return true;
	set<int> window;// set is ordered automatically
	for(int i = 0; i < nums.size(); i++) {
		long n = nums[i];
		if(i > k)
			window.erase(nums[i-k-1]);// keep the set contains nums i j at most k

		auto pos = window.lower_bound(n - t);// x-nums[i] >= -t ==> x >= nums[i]-t
		// x - nums[i] <= t ==> |x - nums[i]| <= t
		if(pos != window.end() && (*pos - n) <= t)
			return true;
		window.insert(n);
	}
	return false;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);nums.push_back(1);
	cout << containsDuplicate3(nums, 3, 0);

	return 0;
}*/
