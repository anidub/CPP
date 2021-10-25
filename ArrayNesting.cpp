#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/array-nesting/
 * A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.
Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.
Example 1:
Input: A = [5,4,0,3,1,6,2]
Output: 4
Explanation:
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
https://leetcode.com/problems/array-nesting/discuss/102473/JavaC%2B%2BPython-Straight-Forward
https://leetcode.com/problems/array-nesting/discuss/102456/Super-concise-C%2B%2B-solution
 */

int arrayNesting(vector<int>& nums){
	if(nums.empty()) return 0;
	int n = nums.size();
	vector<bool> seen(n);
	int result = 0;

	for(int i : nums) {
		int count = 0;
		while(!seen[i]) {
			seen[i] = true;
			count++;
			i = nums[i];
		}
		result = max(result, count);
	}
	return result;
}

int arrayNestingSpaceOptimal(vector<int>& nums){
	if(nums.empty()) return 0;
	int result = 1;

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] < 0 || nums[i] == i) continue;
		int count = 0; int k = i;
		while(nums[k] >= 0) {
			nums[k] = -nums[k];
			count++;
			k = -nums[k];
		}
		result = max(result, count);
	}
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(5);nums.push_back(4);nums.push_back(0);nums.push_back(3);nums.push_back(1);nums.push_back(6);nums.push_back(2);
	cout << arrayNesting(nums) << endl;
	cout << arrayNestingSpaceOptimal(nums) << endl;
	return 0;
}*/
