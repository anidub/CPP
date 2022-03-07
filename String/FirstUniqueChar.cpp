#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/first-unique-character-in-a-string/
 * Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
 * Input: s = "leetcode"
Output: 0

https://leetcode.com/problems/first-unique-character-in-a-string/discuss/515034/C%2B%2B-O(n)-4-Lines-solution-Beats-97 : used

 */
int findFirstUnique(string s) {
	if(s.empty()) return -1;
	vector<int> v(26, 0);

	for(char& c : s)
		v[c - 'a']++;

	for(int i = 0; i < s.length(); i++) {
		char c = s[i];
		if(v[c - 'a'] == 1) return i;
	}
	return -1;
}
/*
int main() {
	cout << findFirstUnique("leetcode") << endl;

	return 0;
}*/
