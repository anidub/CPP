#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/circular-array-loop/
 * You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:

If nums[i] is positive, move nums[i] steps forward, and
If nums[i] is negative, move nums[i] steps backward.
Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.
 * Input: nums = [2,-1,1,2,2]
Output: true
Explanation:
There is a cycle from index 0 -> 2 -> 3 -> 0 -> ...
The cycle's length is 3.
https://leetcode.com/problems/circular-array-loop/discuss/556819/C%2B%2B-100-time-100-space-2-pointers-...Well-Commented-Code
 */
int next(vector<int>& nums, int i) {
	int n = nums.size();
	return (n + nums[i] + i) % n;
}

bool circularArray(vector<int>& nums) {
	if(nums.empty()) return false;
	int n = nums.size();

	vector<bool> visited(n, 0);

	for(int i = 0; i < n; i++)
		nums[i] = nums[i] % n; // steps of size greater than n circle back, so taking remainder

	for(int i = 0; i < n; i++) {
		int slow = i;// initializing slow and fast
		int fast = i;
		 if(visited[slow]) continue;// already visited, no point running slow-fast algorithm again

		 // condition inside ensures that all elements are positive or all negative
		 // 2 negatives / 2 positives multilplied will give +ve as output
		 //we need to ensure all elements slow, next(fast), next(next(fast)) are same sign
		 // we don't need to check next(slow) because it is some previous fast (so already checked)
		while(nums[slow] * nums[next(nums, fast)] > 0 && nums[slow] * nums[next(nums, next(nums, fast))] > 0) {
			// one step for slow
			slow = next(nums, slow);
			// two steps for fast
			fast = next(nums, next(nums, fast));

			// if already visited break
			if(visited[slow]) break;
			visited[slow] = 1;
			if(slow == fast) {
				if(slow == next(nums, slow))// single length
					return false;
				return true;// found a loop
			}
		}
	}
	return false;//no loop found
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(-1);nums.push_back(1);nums.push_back(2);nums.push_back(2);
	cout << circularArray(nums) << endl;

	return 0;
}*/
