#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/
 *et's define a function countUniqueChars(s) that returns the number of unique characters on s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
Given a string s, return the sum of countUniqueChars(t) where t is a substring of s.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/discuss/224001/C%2B%2B-Solution-8ms-by-%22Contribution%22 : used
https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/discuss/1505263/Single-pass-O(n)-time-and-O(1)-space-solution-with-detailed-explanation
https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/discuss/128952/C%2B%2BJavaPython-One-pass-O(N)
 */

const int mod = 1000000007;

int uniqueLetterString(string s) {
	if(s.empty()) return 0;
	int n = s.length();

	vector<int> L(n, -1), R(n, -1);
	vector<int> lastL(26, -1), lastR(26, n);
	int ans = 0;

	for(int i = 0; i < n; i++) {
		L[i] = i - lastL[s[i] - 'A'];
		lastL[s[i] - 'A'] = i;
	}

	for(int i = n-1; i >= 0; i--) {
		R[i] = lastR[s[i] - 'A'] - i;
		lastR[s[i] - 'A'] = i;
	}

	for(int i = 0; i < n; i++) {
		ans = (ans + (L[i] * R[i]) % mod) % mod;
	}
	return ans;
}
/*
int main() {
	cout << uniqueLetterString("ABC") << endl;

	return 0;
}*/
