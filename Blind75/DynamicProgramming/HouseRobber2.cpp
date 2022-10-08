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
/*https://leetcode.com/problems/house-robber-ii/
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
 * That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected,
 *  and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount
of money you can rob tonight without alerting the police.

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

 * https://leetcode.com/problems/house-robber-ii/discuss/59921/9-lines-0ms-O(1)-Space-C%2B%2B-solution
 * Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them together and thus the solution is now the maximum of

Rob houses 0 to n - 2;
Rob houses 1 to n - 1.
 */

class HouseRobber2 {
public:
	//TC:O(N), SC:O(1)
	int robRb(vector<int> &nums) {
		int n = nums.size();
		if(n < 2) return n ? nums[0] : 0;

		return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
	}

private:
	int rob(vector<int> &nums, int left, int right) {
		int prev = 0, cur = 0;

		for(int i = left; i <= right; i++) {
			int tmp = max(prev + nums[i], cur);
			prev = cur;
			cur = tmp;
		}
		return cur;
	}
};

/*
int main() {
	vector<int> nums = {2,3,2};
	HouseRobber2 hs2;
	cout << hs2.robRb(nums) << endl;

}
*/
