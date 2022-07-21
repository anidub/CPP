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
