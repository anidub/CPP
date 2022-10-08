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
/*https://leetcode.com/problems/jump-game/
 * You are given an integer array nums. You are initially positioned at the array's first index,
 * and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

 * https://leetcode.com/problems/jump-game/discuss/520481/C%2B%2B-easy-O(n)-solution-with-detailed-explanation
 *
 * For the last index, the minimum jump length required would be zero because you have reached the last index.
For each index or position that we go backwards(since we are iterating right to left), the minimum jump length required increases by 1.

We start from the second last index and increase minjump by 1 for each position. If at a particular index,
 the maximum jump length at that position is greater than or equal to the minimum jump length required,
  i.e., nums[i]>=minjump, then we can say that we can reach the last index from that position. Thus, we reduce the minimum jump length
  required to zero if the condition is
 satisfied so that for the next position when iterating backwards the minimum jump length required is 1 after incrementation.
 */
class JumpGame {
public:

	//TC:O(N), SC:O(1) USED
	bool canJumpBetter(vector<int> &nums) {
		int minJump = 0, i;
		for(i = nums.size() - 2; i >= 0; i--) {
			minJump++;
			if(nums[i] >= minJump)
				minJump = 0;
		}

		if(minJump == 0) return true;
		return false;

	}

 	bool canJump(vector<int>& nums) {
		int maxReach = 0;

		for(int i = 0; i < nums.size(); i++) {
			if(maxReach < i) return false;//// if previous maxLocation smaller than i, meaning we cannot reach location i, thus return false.
			if(maxReach >= nums.size() - 1) return true;
			maxReach = max(maxReach, i + nums[i]);
		}
		return true;
	}

};

/*
int main() {
	JumpGame jg;
	vector<int> nums = {2,3,1,1,4};
	cout << jg.canJump(nums) << endl;
	cout << jg.canJumpBetter(nums) << endl;

	return 0;
}
*/
