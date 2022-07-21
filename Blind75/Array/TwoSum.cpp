#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/discuss/general-discussion/460599/blind-75-leetcode-questions
 * https://leetcode.com/problems/two-sum/
 *Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
 */

class TwoSum {
public:
	//TC:O(N), SC:O(N)
	vector<int> twoSum(vector<int>& nums, int target) {
		if(nums.empty()) return {};
		vector<int> result;

		unordered_map<int, int> val_indices;
		for(int i = 0; i < nums.size(); i++) {
			int k = target - nums[i];
			if(val_indices.find(k) != val_indices.end()) {
				result.push_back(val_indices[k]);
				result.push_back(i);
			}
			val_indices[nums[i]] = i;
		}
		return result;
 	}
};

/*
int main() {
	TwoSum ts;
	vector<int> nums = {2, 7 , 11, 15};
	ts.twoSum(nums, 9);
	return 0;
}*/
