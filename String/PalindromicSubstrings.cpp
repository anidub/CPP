#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/palindromic-substrings/
 *Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
https://leetcode.com/problems/palindromic-substrings/discuss/153053/647.-Palindromic-Substrings-in-C%2B%2B-and-Java-and-Python
 */
void palindromic(string &s, int left, int right, int &cnt);

//TC: O(N^2), SC:O(1)
int countPalindromicSubstrings(string s) {
	if(s.empty()) return 0;
	int cnt = 0;

	for(int i = 0; i < s.length(); i++) {
		palindromic(s, i, i, cnt);//judge odd substring
		palindromic(s, i, i+1, cnt);//judge even substring
	}
	return cnt;
}

void palindromic(string &s, int left, int right, int &cnt) {//judge if a substring is palindromic
	while(left >= 0 && right < s.size() && s[left] == s[right]) {
		cnt++;
		left--;
		right++;
	}
}
/*
int main() {
	cout << countPalindromicSubstrings("abc") << endl;
	return 0;
}*/
