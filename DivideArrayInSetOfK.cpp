#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>
#include <map>

using namespace std;
/*
 * https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
 * Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into sets of k consecutive numbers
Return True if it is possible. Otherwise, return False.
Example 1:
Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/discuss/770938/C%2B%2B-solution-using-ordered-maps
https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/discuss/470238/JavaC%2B%2BPython-Exactly-Same-as-846.-Hand-of-Straights
 */
//Time O(MlogM + MK), where M is the number of different cards.
bool isPossibleDivide(vector<int>& nums, int k) {
	if(nums.empty()) return 0;
	int n = nums.size();
	if(n % k != 0) return false;

	map<int, int> map;
	for(int& i : nums)
		map[i]++;

	int length = n/k;

	for(int i = 1; i <= length; i++) {
		auto it = map.begin();
		int tmp = it->first;
		for(int j = tmp; j < tmp+k; j++) {
			if(map.find(j) == map.end())
				return false;
			map[j]--;
			if(map[j] == 0)
				map.erase(j);
		}
	}
	return true;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);nums.push_back(3);
	nums.push_back(4);nums.push_back(4);nums.push_back(5);nums.push_back(6);
	cout << isPossibleDivide(nums, 3) << endl;
	return 0;
}*/
