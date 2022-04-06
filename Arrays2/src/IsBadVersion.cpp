#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;
/*https://leetcode.com/problems/first-bad-version/
 * You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

 Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
https://leetcode.com/problems/first-bad-version/discuss/606080/Java-Binary-Search-Clean-code-O(logN)
 */
bool isBadVersion(int n);
//TC: O(LOGN), SC: O(1)
/*WORKS!!
bool firstBadVersion(int n) {
	int left = 0, right = n;
	int ans;
	while(left <= right) {
		int mid = left + (right - left) / 2;
		if(isBadVersion(mid)) {
			ans = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return ans;
}*/
/*
int main() {
	cout << firstBadVersion(5) << endl;

	return 0;
}*/
