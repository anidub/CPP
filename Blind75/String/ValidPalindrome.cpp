#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/valid-palindrome/
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
 *  and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
 */
class ValidPalindrome {
public:
	//TC:O(N), SC:O(1)
	bool isValidPalindrome(string s) {
		if(s.empty()) return false;

		int left = 0, right = s.length() - 1;
		while(left < right) {
			while(left < right && !isalnum(s[left]))
				left++;

			while(left < right && !isalnum(s[right]))
				right--;

			if(tolower(s[left]) != tolower(s[right]))
				return false;
			left++;
			right--;
		}
		return true;
	}
};
/*
int main() {
	ValidPalindrome vp;
	cout << vp.isValidPalindrome("A man, a plan, a canal: Panama") << endl;
}*/
