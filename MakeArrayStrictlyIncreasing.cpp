#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>
#include <map>

using namespace std;
/*https://leetcode.com/problems/make-array-strictly-increasing/
 * Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
If there is no way to make arr1 strictly increasing, return -1.
Example 1:

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
https://leetcode.com/problems/make-array-strictly-increasing/discuss/377629/C%2B%2B-memo-with-maps
 */
/* Complexity analysis
//This algorithm is O(n*m*log(m) where n is the size of arr1 and m is the size of arr2.

Take a look at the inner loop. It does at most O(log m) work because
 of the upper_bound binary search. The inner loop is done at most m + 1 times. The outer loop is done exactly n times.
*/
int helperMakeArrayStrictlyIncreasing(map<pair<int, int>, int> m, int prev, int i, vector<int>& arr1, vector<int>& arr2) {
	if(i >= arr1.size()) return 0;

	if(m.find({i, prev}) != m.end()) return m[{i, prev}];

	int ans = 2000;//2000 is the upper bound constraint in question
	int f = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

	if(arr1[i] > prev)
		ans = min(ans, helperMakeArrayStrictlyIncreasing(m, arr1[i], i+1, arr1, arr2));

	if(f < arr2.size())
		ans = min(ans, helperMakeArrayStrictlyIncreasing(m, arr2[f], i+1, arr1, arr2) + 1);

	return m[{i, prev}] = ans;
}

int makeArrayStrictlyIncreasing(vector<int>& arr1, vector<int>& arr2) {
	sort(arr2.begin(), arr2.end());

	map<pair<int, int>, int> m;
	int ans = helperMakeArrayStrictlyIncreasing(m, INT_MIN, 0, arr1, arr2);

	return ans >= 2000 ? -1 : ans;
}
/*
int main() {
	vector<int> v1; v1.push_back(1);v1.push_back(5);v1.push_back(3);v1.push_back(6);v1.push_back(7);
	vector<int> v2; v2.push_back(1);v2.push_back(6);v2.push_back(3);v2.push_back(3);
	cout << makeArrayStrictlyIncreasing(v1, v2) << endl;

	return 0;
}*/
