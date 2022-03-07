#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/number-of-squareful-arrays/
 * An array is squareful if the sum of every pair of adjacent elements is a perfect square.
Given an integer array nums, return the number of permutations of nums that are squareful.
Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
Example 1:

Input: nums = [1,17,8]
Output: 2
Explanation: [1,8,17] and [17,8,1] are the valid permutations.
https://leetcode.com/problems/number-of-squareful-arrays/discuss/238562/C%2B%2BPython-Backtracking
 *
 */

unordered_map<int, int> numSquarefulArraysCount;
unordered_map<int, unordered_set<int>> numSquarefulArraysCand;
int res = 0;

void numSquarefulArraysDFS(int x, int left) {
	numSquarefulArraysCount[x]--;
	if(!left) res++;
	for(auto& y : numSquarefulArraysCand[x])
		if(numSquarefulArraysCount[y] > 0)
			numSquarefulArraysDFS(y, left-1);
	numSquarefulArraysCount[x]++;
}
//It's O(N!) if we have N different numbers and any pair sum is square.
//We can easily make case for N = 3 like [51,70,30].
int numSquarefulArrays(vector<int>& nums) {
	if(nums.empty()) return 0;
	for(int& i : nums)
		numSquarefulArraysCount[i]++;

	for(auto& i : numSquarefulArraysCount) {
		for(auto& j : numSquarefulArraysCount) {
			int x = i.first, y = j.first, s = sqrt(x+y);
			if(s*s == x+y)
				numSquarefulArraysCand[x].insert(y);
		}
	}
	for(auto& e : numSquarefulArraysCount)
		numSquarefulArraysDFS(e.first, nums.size()-1);
	return res;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(17);nums.push_back(8);
	cout << numSquarefulArrays(nums) << endl;
	return 0;
}*/
