#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 *https://leetcode.com/problems/monotonic-array/
 *https://leetcode.com/problems/monotonic-array/An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
Return true if and only if the given array A is monotonic.
Input: [1,2,2,3]
Output: true
Input: [6,5,4,4]
Output: true
 */
bool isMonotonic(vector<int>& A) {
	if(A.size() == 0) return false;
	bool ascending = true;
	bool descending = true;

	for(int i = 0; i < A.size() - 1; i++) {
		if(ascending && A[i] > A[i+1])
			ascending = false;

		if(descending && A[i] > A[i+1])
			descending = false;
	}

	return ascending || descending;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(2);nums.push_back(3);
	cout << isMonotonic(nums) << endl;
}*/
