#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/get-equal-substrings-within-budget/
 * You are given two strings s and t of the same length. You want to change s to t. Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is, the absolute difference between the ASCII values of the characters.
You are also given an integer maxCost.
Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of twith a cost less than or equal to maxCost.
If there is no substring from s that can be changed to its corresponding substring from t, return 0.
 * Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.
https://leetcode.com/problems/get-equal-substrings-within-budget/discuss/428054/Easy-C%2B%2B-Solution-8ms-sliding-window
https://leetcode.com/problems/get-equal-substrings-within-budget/discuss/392837/JavaC%2B%2BPython-Sliding-Window
 */

//O(N)
int equalSubStringBudget(string s, string t, int maxCost) {
	int left = 0, right = 0;
	int maxLen = 0, count = 0;
	int cost = 0;

	while(right < s.size()) {
		cost += abs(s[right] - t[right]);
		if(cost <= maxCost) {
			count++;
			maxLen = max(maxLen, count);
		} else {
			count++;
			while(cost > maxCost) {
				cost -= abs(s[left] - t[left]);
				count--;
				left++;
			}
		}
		right++;
	}
	return maxLen;
}

//O(N)
int equalSubstringOther(string s, string t, int maxCost) {
	int n = s.size();
	int i = 0, j;
	for(j = 0; j < n; j++) {
		maxCost -= abs(s[j] - t[j]);
		if(maxCost < 0) {
			maxCost += abs(s[i] - t[i]);
			i++;
		}
	}
	return j-i;
}

/*
int main() {
	string s = "abcd";
	string t = "bcdf";
	cout << equalSubStringBudget(s, t, 3) << endl;
	cout << equalSubstringOther(s, t, 3) << endl;
	return 0;
}
*/
