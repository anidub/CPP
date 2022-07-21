#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/k-diff-pairs-in-an-array/
 * Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
https://leetcode.com/problems/k-diff-pairs-in-an-array/discuss/100111/O(n)-concise-solution-C%2B%2B
 */
//O(N)
int findPairs(vector<int>& nums, int k) {
	if(k < 0) return 0;
	unordered_map<int, int> mp;
	int result = 0;

	for(int i = 0; i < nums.size(); i++) {
		mp[nums[i]]++;
	}

	if(k != 0) {
		for(auto it = mp.begin(); it != mp.end(); it++) {
			if(mp.find(it->first+k) != mp.end())
				result++;
		}
	} else {
		for(auto it = mp.begin(); it != mp.end(); it++) {
			if(it->second > 1)
				result++;
		}
	}
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(3);nums.push_back(1);nums.push_back(4);nums.push_back(1);nums.push_back(5);
	cout << findPairs(nums, 2) << endl;

	return 0;
}*/
