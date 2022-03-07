#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/valid-palindrome/
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
https://leetcode.com/problems/valid-palindrome/discuss/40335/C%2B%2B-two-pointers
 */
//TC: O(N)
bool isValidPalindrome(string s) {
	if(s.empty()) return false;

	int l = 0, r = s.size() - 1;
	while(l < r) {
		while(l < r && !isalnum(s[l]))
			l++;
		while(l < r && !isalnum(s[r]))
			r--;

		if( tolower(s[l++]) != tolower(s[r--]) )
			return false;
	}
	return true;
}
/*
int main() {
	cout << isValidPalindrome("A man, a plan, a canal: Panama") << endl;

	return 0;
}*/
