#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/implement-strstr/
 * Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP
 */
//TC:O(MN) SC:O(1)
int strStr1(string haystack, string needle) {
	if(needle.empty()) return 0;

	int m = haystack.size(), n = needle.size();
	for(int i = 0; i <= m - n; i++) {
		int j = 0;
		for(; j < n; j++) {
			if(haystack[i + j] != needle[j])
				break;
		}
		if(j == n) return i;
	}
	return -1;
}
/*
int main() {
	cout << strStr1("hello", "ll") << endl;

	return 0;
}
*/
