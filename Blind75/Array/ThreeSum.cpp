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
/*https://leetcode.com/problems/3sum/
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

https://leetcode.com/problems/3sum/solution/
 */
class ThreeSum {
public:
	//TC:O(N^2) ,SC:O(N)
	vector<vector<int>> threeSum(vector<int> &nums) {
		if(nums.empty()) return {};
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size() - 1; i++) {
			if(i > 0 && nums[i] == nums[i - 1]) continue;
			threeSumHelper(nums, -nums[i], i + 1, result);
		}
		return result;
	}

	vector<vector<int>> threeSumUsingSet(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSum(nums, i, result);
            }
        return result;
	}
private:
	void threeSumHelper(vector<int> &nums, int targetSum, int left, vector<vector<int>> &result) {
		int right = nums.size() - 1;

		while(left < right) {
			int curSum = nums[left] + nums[right];
			if(curSum == targetSum) {
				result.push_back({nums[left], nums[right], -targetSum});
				left++; right--;
				while(left < right && nums[left] == nums[left - 1])
					left++;
				while(left < right && nums[right] == nums[right + 1])
					right--;
			} else if(curSum < targetSum)
				left++;
			else
				right--;
		}
	}

    void twoSum(vector<int>& nums, int i, vector<vector<int>> &result) {
        unordered_set<int> seen;
        for (int j = i + 1; j < nums.size(); ++j) {
            int complement = -nums[i] - nums[j];
            if (seen.count(complement)) {
            	result.push_back({nums[i], complement, nums[j]});
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                    ++j;
                }
            }
            seen.insert(nums[j]);
        }
    }
};
/*
int main() {
	ThreeSum ts;
	vector<int> nums = {-1,0,1,2,-1,-4};
	ts.threeSum(nums);
	ts.threeSumUsingSet(nums);

	return 0;
}*/
