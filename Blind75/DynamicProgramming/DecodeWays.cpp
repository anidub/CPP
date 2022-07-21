#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/decode-ways/
 * A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse
of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

 * https://leetcode.com/problems/decode-ways/discuss/30451/Evolve-from-recursion-to-dp
 */
class DecodeWays {
public:
	//O(2 ^ N), SC:O(N)
	int numDecodeWaysResursion(string s) {
		return s.empty() ? 0 : numDecodeWaysRecursion(0, s);
	}

	//TC:O(N), SC:O(N)
	int numDecodeWaysMemo(string s) {
		int n = s.size();
		vector<int> memo(n + 1, -1);
		memo[n] = 1;
		return s.empty() ? 0 : numDecodeWaysMemo(0, s,  memo);
	}

private:
	int numDecodeWaysRecursion(int p, string &s) {
        int n = s.size();
        if(p == n) return 1;
        if(s[p] == '0') return 0;

        int res = numDecodeWaysRecursion(p + 1, s);

        if( p < n - 1 && ( (s[p] == '1') || ( s[p] == '2' && s[p + 1] < '7') )  )
            res += numDecodeWaysRecursion(p + 2, s);

        return res;
	}

	int numDecodeWaysMemo(int i, string &s, vector<int> &memo) {
		if(memo[i] > -1) return memo[i];
		if(s[i] == '0') return memo[i] = 0;

		int res = numDecodeWaysMemo(i + 1, s, memo);

		if(i < s.size() - 1 &&  (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
			res += numDecodeWaysMemo(i + 2, s, memo);

		return memo[i] = res;
	}
};

/*
int main() {
	string s = "12";
	DecodeWays dw;
	cout << dw.numDecodeWaysResursion(s) << endl;
	cout << dw.numDecodeWaysMemo(s) << endl;
}
*/
