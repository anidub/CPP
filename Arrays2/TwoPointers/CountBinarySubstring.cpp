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
/*https://leetcode.com/problems/count-binary-substrings/
 *Give a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.
Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
well explained:
https://leetcode.com/problems/count-binary-substrings/discuss/1172566/Count-Binary-Strings-or-Short-and-Simple-w-Explanation-and-Comments-or-Beats-100
 */
//TC : O(N)
int countBinarySubstrings(string& s) {
	if(s.empty()) return 0;
	 // we start from first character - so curConsecutive = 1
	int curConsecutive = 1, prevConsecutive = 0, ans = 0;
	for(int i = 1; i < s.size(); i++) {
		if(s[i] != s[i-1]) {// whenever current & previous don't match
			ans += min(curConsecutive, prevConsecutive);// number of substring formed is minimum of cur & prev count
			prevConsecutive = curConsecutive;// previous consecutive streak will become current consecutive and,
			curConsecutive = 1;// current streak will be resetted
		} else
			curConsecutive++;
	}
	ans += min(prevConsecutive, curConsecutive);// required to include count from last two groups of consecutive characters.
	return ans;
}
/*
int main() {
	string s = "00110011";
	cout << countBinarySubstrings(s) << endl;
	return 0;
}*/
