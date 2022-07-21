#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
 * Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit
 * Input: nums = [8,2,4,7], limit = 4
Output: 2
Explanation: All subarrays are:
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4.
Therefore, the size of the longest subarray is 2.
https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/discuss/678355/Easy-to-understand-C%2B%2B-solution%3A-deque-multiset
 */
//TC:(N) , SC:O(N)
int longestSubarrayAbosulteDifference(vector<int>& nums, int limit) {
	if(nums.empty()) return 0;
	deque<int> maxdq, mindq;
	int j = 0, ans = 0;

	for(int i = 0; i < nums.size(); i++) {
		while(!maxdq.empty() && nums[i] > maxdq.back()) maxdq.pop_back();
		while(!mindq.empty() && nums[i] < mindq.back()) mindq.pop_back();

		maxdq.push_back(nums[i]);
		mindq.push_back(nums[i]);

		while(maxdq.front() - mindq.front() > limit) {
			if(maxdq.front() == nums[j]) maxdq.pop_front();
			if(mindq.front() == nums[j]) mindq.pop_front();
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	return ans;
}
/*
int main() {
	vector<int> nums = {8, 2, 4 ,7};
	cout << longestSubarrayAbosulteDifference(nums, 4) << endl;
}*/
