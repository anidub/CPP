#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/combination-sum-iv/
 * Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.
 * Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

 * https://leetcode.com/problems/combination-sum-iv/discuss/85036/1ms-Java-DP-Solution-with-Detailed-Explanation
 */
class CombinationSum4 {
public:
	//TC:O(T * N), SC:O(T)Let T be the target value, and N be the number of elements in the input array.
	int combinationSum4(vector<int> &nums, int target) {
		if(target == 0) return 1;

		int res = 0;
		for(int i = 0; i < nums.size(); i++) {
			if(target >= nums[i]) {
				res += combinationSum4(nums, target - nums[i]);
			}
		}
		return res;
	}

	//TC:O(T * N), SC:O(T)
	int combinationSum4Memo(vector<int> &nums, int target) {
		vector<int> memo(target + 1, -1);
		memo[0] = 1;
		return combinationSum4Memo(nums, target, memo);
	}

private:
	int combinationSum4Memo(vector<int> &nums, int target, vector<int> &memo) {
		if(memo[target] != -1) return memo[target];

		int res = 0;
		for(int i = 0; i < nums.size(); i++)  {
			if(target >= nums[i])
				res += combinationSum4Memo(nums, target - nums[i], memo);
		}
		memo[target] = res;
		return res;
	}
};
/*
int main() {
	CombinationSum4 cs;
	vector<int> nums = {1, 2, 3};
	cout << cs.combinationSum4(nums, 4) << endl;

	cout << cs.combinationSum4Memo(nums, 4) << endl;
}
*/
