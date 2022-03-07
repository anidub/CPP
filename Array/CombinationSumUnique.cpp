#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <deque>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/combination-sum-ii/
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6] ]

https://leetcode.com/problems/combination-sum-iii/discuss/60846/Accepted-0ms-c%2B%2B-solution-use-backtracking-easy-understand.
 */

void combinationSumUniqueUtil(vector<int>& candidates, int index, int target, vector<int> current, vector<vector<int>>& result) {
	if(target == 0) {
		result.push_back(current);
		return;
	}

	for(int i = index; i < candidates.size() && target >= candidates[i]; i++) {
		if(i == index ||  candidates[i] != candidates[i-1]) {
			current.push_back(candidates[i]);
			combinationSumUniqueUtil(candidates, i+1, target-candidates[i], current, result);
			current.pop_back();
		}
	}
}

vector<vector<int>> combinationSumUnique(vector<int>& candidates, int target) {
	vector<int> current;
	vector<vector<int>> result;
	if(candidates.empty()) return result;
	sort(candidates.begin(), candidates.end());

	combinationSumUniqueUtil(candidates, 0, target, current, result);
	return result;
}
/*
int main() {
	return 0;
}*/
