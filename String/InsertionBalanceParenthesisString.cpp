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
/*https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
 * Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
You can insert the characters '(' and ')' at any position of the string to balance it if needed.
Return the minimum number of insertions needed to make s balanced.

https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/discuss/780366/C%2B%2B-O(n)-oror-Proper-explaination-oror-Without-Stack
1. We get an open bracket
In this, we have 2 things to understand

For every open bracket, we need 2 closed brackets.
req += 2
Now if I have an odd number of closed brackets, this means that we have one ) for one of the (, and now we have another open bracket. As the question says Any left parenthesis '(' must have a corresponding two consecutive right parenthesis ')), so we need to give a ) to the existing open bracket, and then process the new one.
ans++ => We added a new closed bracket req-- => the existing lonely ) is paired and not needed now
2. We encounter a closed bracket
In this, we again have two things to understand:

If we encounter a lone warrior, basically a ) when req = 0, this means we can manually add a ( and then say that we encountered ().
ans++ => We added a new open bracket
req++ => Another closed bracket is required as we have ()
Otherwise, we directly reduce the number of required closed brackets.
req--
 */
//TC: O(N), SC: O(1)
int minInsertions(string s) {
	if(s.empty()) return 0;

	int manual_add = 0;
	int req_close = 0;

	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '(') {
			req_close += 2;

			if(req_close % 2 != 0) {
				manual_add++;
				req_close--;
			}
		} else {
			if(req_close == 0) {
				manual_add++;
				req_close++;
			} else
				req_close--;
		}
  	}
	return manual_add + req_close;
}
/*
int main() {
	cout << minInsertions("(()))") << endl;

	return 0;
}*/
