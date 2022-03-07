#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>

using namespace std;
/*https://leetcode.com/problems/longest-palindromic-substring/
 * Given a string s, return the longest palindromic substring in s.
 * Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

 * https://leetcode.com/problems/longest-palindromic-substring/discuss/2929/Accepted-4ms-c%2B%2B-solution. : comments
 */
string expand(string& s, int l, int r);

string longestPalindrome(string s) {
	string ret;
	for(int i = 0; i < s.length(); i++) {
		string tmp = expand(s, i, i);//find the middle of a palindrome
		if(tmp.length() > ret.length())
			ret = tmp;

		tmp = expand(s, i, i+1);//expand from the middle out
		if(tmp.length() > ret.length())
			ret = tmp;
	}
	return ret;
}

string expand(string& s, int l, int r) {
	if(r > s.size()) return "";
	while(l >= 0 && r < s.size() && s[l] == s[r]) {
		l--;
		r++;
	}
	return s.substr(l+1, r - l - 1);
}


//method 2 https://leetcode.com/problems/longest-palindromic-substring/discuss/2923/Simple-C%2B%2B-solution-(8ms-13-lines)
string longestPalindrome2(string s) {
    if (s.size()<=1)
        return s;
    int min_left=0;
    int max_len=1;
    int max_right=s.size()-1;
    for (int mid=0;mid<s.size();){
        int left=mid;
        int right=mid;
        while (right<max_right && s[right+1]==s[right])
            right++; // Skip duplicate characters in the middle
        mid=right+1; //for next iter
        while (right<max_right && left>0 && s[right+1]==s[left-1]){
            right++;
            left--;
        } // Expand the selection as long it is a palindrom
        int new_len=right-left+1; //record best palindro
        if (new_len>max_len){
            min_left=left;
            max_len=new_len;
        }
    }
    return s.substr(min_left, max_len);
}
/*Using dp
 * https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
 * https://www.youtube.com/watch?v=UflHuQj6MVA : well expalined
 */
string longestPalindromicSubstring(string str) {
	if(str.empty()) return "";
	int n = str.size();
	bool table[n][n];

	memset(table, 0, sizeof(table));
	int maxLength = 1;

	for(int i = 0; i < n; i++)
		table[i][i] = true;

	int start = 0;
	for(int i = 0; i < n-1; i++) {
		if(str[i] == str[i+1]) {
			table[i][i+1] = true;
			start = i;
			maxLength = 2;
		}
	}

	for(int k = 3; k <= n; k++) {
		for(int i = 0; i < n - k + 1; i++) {
			int j = i + k - 1;
			if(table[i+1][j-1] && str[i] == str[j]) {
				table[i][j] = true;
				if(k > maxLength) {
					start = i;
					maxLength = k;
				}
			}
		}
	}
	return str.substr(start, maxLength);
}
/*
int main() {
	string s = "babad";
	cout << longestPalindromicSubstring("ac") << endl;
	cout << longestPalindrome(s) << endl;

	return 0;
}*/
