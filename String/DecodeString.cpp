#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>

using namespace std;
/*https://leetcode.com/problems/decode-string/
 *Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

https://leetcode.com/problems/decode-string/discuss/87544/Clean-C%2B%2B-Recursive-Solution-with-Explanation
Every time we meet a '[', we treat it as a subproblem so call our recursive function to get the content in that '[' and ']'. After that, repeat that content for 'num' times.
Every time we meet a ']', we know a subproblem finished and just return the 'word' we got in this subproblem.
Please notice that the 'pos' is passed by reference, use it to record the position of the original string we are looking at.

https://leetcode.com/problems/decode-string/discuss/472087/0ms-C%2B%2B-solution-using-one-stack : iterative

O(N) : TC
 */
string decodeStringHelper(int& pos, string s);

string decodeString(string s) {
	int pos = 0;
	return decodeStringHelper(pos, s);
}

string decodeStringHelper(int& pos, string s) {
	string word = "";
	int num = 0;

	for(; pos < s.size(); pos++) {
		char cur = s[pos];
		if(cur == '[') {
			pos++;
			string curStr = decodeStringHelper(pos, s);
			for(; num > 0; num--)
				word += curStr;
		} else if(cur >= '0' && cur <= '9') {
			num = num * 10 + cur - '0';
		} else if(cur == ']') {
			return word;
		} else {
			word += cur;
		}
	}
	return word;
}
/*
int main() {
	cout << decodeString("3[a]2[bc]") << endl;

	return 0;
}*/
