#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
 * You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.
Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/discuss/951980/C%2B%2B-Three-passes-O(NlogN)
 */
//// Time: O(NlogN) Space: O(N)
int minMountainArrayRemovals(vector<int>& A) {
	if(A.empty()) return 0;
	int N = A.size(), ans = N;
	vector<int> a(N), b(N), v;

	for(int i = 0; i < N; i++) {
		int x = A[i];
		auto it = lower_bound(begin(v), end(v), x);
		a[i] = it - begin(v);
		if(it != end(v)) *it = x;
		else v.push_back(x);
	}

	v.clear();

	for(int i = N-1; i >= 0; i--) {
		int x = A[i];
		auto it = lower_bound(begin(v), end(v), x);
		b[i] = it - begin(v);
		if(it != end(v)) *it = x;
		else v.push_back(x);
	}

	for(int i = 1; i < N; i++) {
		if(a[i] && b[i])
			ans = min(ans, N - (a[i] + b[i] + 1));
	}
	return ans;
}
/*
int main() {
	vector<int> A;
	A.push_back(2);A.push_back(1);A.push_back(1);A.push_back(5);A.push_back(6);
	A.push_back(2);A.push_back(3);A.push_back(1);
	cout << minMountainArrayRemovals(A) << endl;
	return 0;
}
*/
