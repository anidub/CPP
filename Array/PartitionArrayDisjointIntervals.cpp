#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/partition-array-into-disjoint-intervals/
 * Given an array nums, partition it into two (contiguous) subarrays left and right so that:
Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.
Example 1:
Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
https://leetcode.com/problems/partition-array-into-disjoint-intervals/discuss/647096/C%2B%2B-or-Not-the-best-one-or-Easy-to-understand

https://leetcode.com/problems/partition-array-into-disjoint-intervals/discuss/176791/c%2B%2B-simple-fast-solutions.-With-description.-O(n)-time-O(1)-space
If we know the maximum value upto and including point p, we can then check that everything above point p is greater or equal to that maximum.
If we do find a value at point p2 below our maximum, then our point p must be wrong. However point p2 could be a valid solution,
 and thus we can continue to check further right of point p2 to confirm there is nothing below the maximum value to the left of p2.
 Thus we can repeatably try points until we find our answer.

Since we're searching to the right, we should therefore choose the left most point as our initial guess. After that, all we need
to do is ensure we have a maximum value for the range [0, p],
 which is actually quite simple to do as we move left to right.
 */
//O(n) time , O(1) space
int partitionDisjointIntervalsOptimum(vector<int>& A) {
	if(A.empty()) return 0;
	int index = 0;
	int imax_before  = A[0], imax_after  = A[0];

	for(int i = 1; i < A.size(); i++) {
		// If we ever find a value less than the maximum value upto our current guess, then our guess must be wrong
		if(A[i] < imax_before) {
			 // Update our guess and record the maximum value to the left of our new guess
			index = i;
			imax_before = imax_after;
		} else {
			imax_after = max(imax_after, A[i]);
		}
	}
	return index+1;
}

int partitionArrayDisjoint(vector<int>& A) {
	if(A.empty()) return 0;
	int n = A.size();
	vector<int> left(n, 0);
	vector<int> right(n, 0);

	left[0] = A[0];
	for(int i = 1; i < n; i++) {
		left[i] = max(A[i], left[i-1]);
	}

	right[n-1] = A[n-1];
	for(int i = n-2; i >= 0; i--) {
		right[i] = min(A[i], right[i+1]);
	}

	for(int i = 0; i < n; i++) {
		if(left[i] <= right[i+1])
			return i+1;
	}
	return -1;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(5);nums.push_back(0);nums.push_back(3);nums.push_back(8);nums.push_back(6);
	cout << partitionArrayDisjoint(nums) << endl;
	cout << partitionDisjointIntervalsOptimum(nums) << endl;
	return 0;
}*/
