#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
/*Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 * Input: s = "aba"
Output: true

https://leetcode.com/problems/valid-palindrome-ii/discuss/107717/C%2B%2BJava-Clean-Code-2-liner-Generic-for-%22you-may-delete-at-most-N-character%22
// d: num of chars you can delete at most
 */
bool validPalindromeChars(string& s, int i, int j, int d);

//TC:  O(2^d * N) 2^d, since we have the option of picking the i-th character or j-th character, leading to two recursive branches potentially at each level. assuming d << N.
bool validPalindromeAtmostOneChar(string s) {
	return validPalindromeChars(s, 0, s.length() - 1, 1);
}

bool validPalindromeChars(string& s, int i, int j, int d){
	if(i >= j) return true;
	if(s[i] == s[j])
		return validPalindromeChars(s, i+1, j-1, d);
	else
		return d > 0 && (validPalindromeChars(s, i, j-1, d-1) || validPalindromeChars(s, i+1, j, d-1));
}
//Iterative/Time complexity - O(N) Space complexity - O(1)//https://leetcode.com/problems/valid-palindrome-ii/discuss/1324407/C%2B%2B-solution-or-Two-pointer-Approach
bool isp(string s, int l, int r);
bool validPalindromeIterative(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        if (s[i] != s[j]) return isp(s, i + 1, j) || isp(s, i, j - 1);
    return true;
}

bool isp(string s, int l, int r) {
    for (int i = l, j = r; i < j; i++, j--)
        if (s[i] != s[j]) return false;
    return true;
}
/*
int main() {
	cout << validPalindromeAtmostOneChar("abca") << endl;
	return 0;
}*/
