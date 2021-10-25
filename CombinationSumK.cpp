#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <deque>
#include <utility>

using namespace std;

/*
 * https://leetcode.com/problems/combination-sum-iii/
 * Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
https://leetcode.com/problems/combination-sum-iii/discuss/60769/C%2B%2B-simple-backtracking-solution.
 */

void combinationSum3Util(vector<int>& candidates, int index, int k, int target, vector<int>& current, vector<vector<int>>&result) {
	if(k < 0 || target < 0)
		return;
	if(target == 0 && k == 0){
		result.push_back(current);
		return;
	}

	for(int i = index; i < candidates.size(); i++) {
		current.push_back(candidates[i]);
		combinationSum3Util(candidates, i+1, k-1, target-candidates[i], current, result);
		current.pop_back();
	}
}

vector<vector<int>> combinationSum3(int k, int n) {
	vector<int> candidates;
	for(int i = 1; i <= 9; i++)
		candidates.push_back(i);

	vector<int> current;
	vector<vector<int>> result;
	combinationSum3Util(candidates, 0, k, n, current, result);
	return result;
}
/*
int main() {

	return 0;
}*/
