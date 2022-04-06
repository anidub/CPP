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
/*https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 * You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
Input: s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/discuss/294893/JavaC%2B%2BPython-Two-Pointers-and-Stack-Solution
 */
//TC : O(N), SC : O(1)
string removeAdjDuplicates(string s) {
    if(s.empty()) return "";
    int i = 0, n = s.size();

    for(int j = 0; j < n; j++) {
    	s[i] = s[j];
    	if(i > 0 && s[i] == s[i-1]) {
    		i -= 2;
    	}
    	i++;
    }
    return s.substr(0, i);
}
//TC : for one pass Space O(N) for output
string removeAdjDupsStack(string s) {
	if(s.empty()) return "";

	string res = "";
	for(char &c : s) {
		if(res.size() && c == res.back())
			res.pop_back();
		else
			res.push_back(c);
	}
	return res;
}
/*
int main() {
	cout << removeAdjDuplicates("abbaca") << endl;
	cout << removeAdjDupsStack("abbaca") << endl;

	return 0;
}*/
