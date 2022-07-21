#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/palindromic-substrings/
 * Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

 */
class PalindromicSubstrings {
public:
	//TC:O(N ^ 2), SC:O(1)
	int countSubstrings(string s) {
		if(s.empty()) return 0;
		int cnt = 0;
		for(int i = 0; i < s.length(); i++) {
			palindrominc(s, i, i, cnt);//even
			palindrominc(s, i, i + 1, cnt);//odd
		}
		return cnt;
	}
private:
	void palindrominc(string s, int left, int right, int &cnt) {
		while(left >= 0 && right < s.length() && s[left] == s[right]) {
			cnt++;
			left--;
			right++;
		}
	}
};
/*
int main() {
	PalindromicSubstrings ps;
	cout << ps.countSubstrings("abc") << endl;

}
*/
