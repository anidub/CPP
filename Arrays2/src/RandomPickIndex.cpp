#include <iostream>
#include <vector>
#include <stdlib.h>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;
/*https://leetcode.com/problems/random-pick-index/
 * Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.
Input
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
Output
[null, 4, 0, 2]

Explanation
Solution solution = new Solution([1, 2, 3, 3, 3]);
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(1); // It should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.

https://leetcode.com/problems/random-pick-index/discuss/88071/C%2B%2B_Time%3A-O(n)-Space%3A-O(n)_116ms_96.41_with-clear-explanation-by-probability
Reservoir sampling is a technique which is used to generate numbers randomly when we have a large pool of numbers.
explained in solution tab and above link
 */
class RandomPickIndex {
vector<int> nums;
public:
RandomPickIndex(vector<int> nums) {
	this->nums = nums;
}
//O(N), SC: O(1) to store nums
int pick(int target) {
	int n = 0, result = -1, len = nums.size();

	for(int i = 0; i < len; i++) {
		if(nums[i] != target) continue;
		n++;
		if(rand() % n == 0) result = i;
	}
	return result;
}

};
/*
int main() {
	RandomPickIndex *obj = new RandomPickIndex({1, 2, 3, 3, 3});
	obj->pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
	obj->pick(1); // It should return 0. Since in the array only nums[0] is equal to 1.
	cout << obj->pick(3) << endl; // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.

	return 0;
}
*/
