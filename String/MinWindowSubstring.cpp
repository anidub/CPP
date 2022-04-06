#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/minimum-window-substring/
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

https://leetcode.com/problems/minimum-window-substring/discuss/26917/16ms-simple-and-neat-c%2B%2B-solution-only-using-a-vector.-Detailed-explanation
https://www.youtube.com/watch?v=e1HlptlipB0 : well explained..just first 6 mins
 */
string minWindowSubstring(string s, string t) {
	if(s.empty() || t.empty()) return "";

	vector<int> remaining(128, 0);
	int required = t.size();
	for(int i = 0 ; i < required; i++)
		remaining[t[i]]++;

	int left = 0, min = INT_MAX, start = 0, i = 0;

	while(i <= s.size() && start < s.size()) {
		if(required) {
			if(i == s.size()) break;
			remaining[s[i]]--;
			if(remaining[s[i]] >= 0) required--;
			i++;
		} else {
			if(i - start < min) {
				min = i - start;
				left = start;
			}
			remaining[s[start]]++;
			if(remaining[s[start]] > 0 ) required++;
			start++;
		}
	}
	return min == INT_MAX ? "" : s.substr(left, min);
}
/*
int main() {
	cout << minWindowSubstring("ADOBECODEBANC", "ABC") << endl;

	return 0;
}*/
