#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>

using namespace std;
/*https://leetcode.com/problems/palindrome-permutation/
 * Given a string s, return true if a permutation of the string could form a palindrome.
 * Input: s = "code"
Output: false
Input: s = "aab"
Output: true
https://leetcode.com/problems/palindrome-permutation/discuss/69591/My-simple-C%2B%2B-solution-using-a-hash-like-data-structure
 */
//TC:O(N), SC : O(1)
bool canPermutatePalindrome(string s) {
	int dict[256] = {0};
	for(char &c : s)
		dict[c]++;
	int cnt = 0;
	for(int i = 0; i < 256; i++)
		if(dict[i] % 2 != 0) cnt++;

	return cnt <= 1;
}
/*
int main() {
	cout << canPermutatePalindrome("aab") << endl;

	return 0;
}
*/
