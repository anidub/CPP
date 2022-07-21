#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/longest-palindromic-substring/
 * Given a string s, return the longest palindromic substring in s.
 *
 * Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
https://leetcode.com/problems/longest-palindromic-substring/discuss/2928/Very-simple-clean-java-solution
 */
class LongestPalindromicSubstring {
public:
	//TC:O(N^2), SC:O(1)
	string longestPalindrome(string s) {
		if(s.empty()) return "";
		int len = s.length();
		if(len < 2) return s;

		int start = 0, maxLen = 0;
		for(int i = 0; i < len - 1; i++) {
			extendPalindrome(s, i, i,start, maxLen);//even
			extendPalindrome(s, i, i + 1, start, maxLen);//odd
		}
		return s.substr(start, maxLen);
	}
private:
	void extendPalindrome(string &s, int left, int right, int &start, int &maxLen) {
		while(left >= 0 && right < s.length() && s[left] == s[right]) {
			left--;
			right++;
		}
		if(maxLen < right - left - 1) {
			start = left + 1;
			maxLen = right - left - 1;
		}
	}
};
/*
int main() {
	LongestPalindromicSubstring lps;
	cout << lps.longestPalindrome("babad") << endl;
}*/
