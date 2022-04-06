#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/valid-palindrome-iii/
 * Given a string s and an integer k, return true if s is a k-palindrome.

A string is k-palindrome if it can be transformed into a palindrome by removing at most k characters from it.
Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.

https://leetcode.com/problems/valid-palindrome-iii/solution/
 */


vector<vector<int>> memo;

int checkPalindromeRemovals(string &s, int i, int j);
//TC: O(N^2), SC : O(N^2)
bool isValidPalindromeK(string s, int k) {
	if(s.empty()) return false;

	int n = s.length();
	memo.resize(n, vector<int>(n, -1));

    // Return true if the minimum cost to create a palindrome by only deleting the letters is less than or equal to `k`.
	return checkPalindromeRemovals(s, 0, n-1) <= k;
}

int checkPalindromeRemovals(string &s, int i, int j) {
	if(i == j)// Base case, only 1 letter remaining.
		return 0;

	if(i == j - 1)// Base case 2, only 2 letters remaining.
		return s[i] != s[j];

	if(memo[i][j] != -1)// Return the precomputed value if exists.
		return memo[i][j];

	// Case 1: Character at `i` equals character at `j`
	if(s[i] == s[j])
		return memo[i][j] = checkPalindromeRemovals(s, i+1, j-1);

	// Case 2: Character at `i` does not equal character at `j`.Either delete character at `i` or delete character at `j`
	// and try to match the two pointers using recursion.We need to take the minimum of the two results and add 1 representing the cost of deletion.
		return memo[i][j] = 1 + min( checkPalindromeRemovals(s, i+1, j), checkPalindromeRemovals(s, i, j-1) );
}

//TC: O(N^2), SC : O(N)
bool isValidPalindromeAfterRemovalSpaceOptimal(string s, int k) {
	if(s.empty()) return false;

	int n = s.length();

	vector<int> memo(n, 0);
	int temp, prev;

	for(int i = n - 2; i >= 0; i--) {
		prev = 0;
		for(int j = i + 1; j < n; j++) {
			temp = memo[j];

			if(s[i] == s[j])
				memo[j] = prev;
			else
				memo[j] = 1 + min(memo[j], memo[j-1]);

			prev = temp;
		}
	}
	return memo[n - 1] <= k;
}

/*
int main() {
	cout << isValidPalindromeK("abcdeca", 2) << endl;
	cout << isValidPalindromeAfterRemovalSpaceOptimal("abcdeca", 2);

	return 0;
}*/
