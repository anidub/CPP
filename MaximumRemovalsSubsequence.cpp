#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/maximum-number-of-removable-characters/
 * You are given two strings s and p where p is a subsequence of s. You are also given a distinct 0-indexed integer array removable containing a subset of indices of s (s is also 0-indexed).
You want to choose an integer k (0 <= k <= removable.length) such that, after removing k characters from s using the first k indices in removable, p is still a subsequence of s. More formally, you will mark the character at s[removable[i]] for each 0 <= i < k, then remove all marked characters and check if p is still a subsequence.
Return the maximum k you can choose such that p is still a subsequence of s after the removals.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
Example 1:

Input: s = "abcacb", p = "ab", removable = [3,1,0]
Output: 2
Explanation: After removing the characters at indices 3 and 1, "abcacb" becomes "accb".
"ab" is a subsequence of "accb".
If we remove the characters at indices 3, 1, and 0, "abcacb" becomes "ccb", and "ab" is no longer a subsequence.
Hence, the maximum k is 2.
https://leetcode.com/problems/maximum-number-of-removable-characters/discuss/1268805/c%2B%2B-oror-binary-search : used
https://leetcode.com/problems/maximum-number-of-removable-characters/discuss/1268472/C%2B%2B-Binary-Answer
 */
int isSubSequence(string s1, string s2) {
	int m = s1.length(), n = s2.length(), j = 0;

	for(int i = 0; i < n && j < n; i++) {
		if(s1[j] == s2[i])
			j++;
	}
	return j == m;
}
// Time: O(NlogN)
// Space: O(N)
int maximumRemovals(string s, string p, vector<int>& removable) {
	if(s.length () == 0 || p.length() == 0) return 0;
	int left = 0, right = removable.size();
	string copy = s;

	while(left <= right) {
		int mid = (left + right)/2;
		for(int i = 0; i < mid; i++)
			copy[removable[i]] = '*';

		if(isSubSequence(p, copy))//if p is subsequence of string after mid number of removals then we should look for if it's possible to remove more characters
			left = mid+1;
		else {
			//if p is not a subsequence of string it means that we have certainly removed more characters from string
			//so we must decrease our size of removal characters and hence we  add all characters we removed earlier.
                for(int i=0;i<mid;i++) copy[removable[i]] = s[removable[i]];
			for(int i = 0; i < mid; i++)
				copy[removable[i]] = s[removable[i]];
			right = mid-1;
		}
	}
	return right;
}
/*
int main() {
	string s = "abcacb";
	string p = "ab";
	vector<int> removable;
	removable.push_back(3);removable.push_back(1);removable.push_back(0);
	cout << maximumRemovals(s, p, removable) << endl;

	return 0;
}
*/
