#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <utility>

using namespace std;
/*
 * Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c%2B%2B-solution-use-backtracking-easy-understand.
 * O(#candidates^(target/min of candidates))
 *  O(#candidates^target) because the height of the tree would be target and degree of each node would be number of candidates. Space complexity is O(target)
 */

void combinationSumUtil(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& combination, int begin) {
	if(!target) {
		result.push_back(combination);
		return;
	}

	for(int i = begin; i != candidates.size() && target >= candidates[i]; i++) {
		combination.push_back(candidates[i]);
		combinationSumUtil(candidates, target - candidates[i], result, combination, i);
		combination.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> result;
	vector<int> combination;
	combinationSumUtil(candidates, target, result, combination, 0);
	return result;
}
/*
int main() {

	vector<int> candidates;
	candidates.push_back(2);candidates.push_back(3);candidates.push_back(6);candidates.push_back(7);
	combinationSum(candidates, 7);
	return 0;
}
*/
