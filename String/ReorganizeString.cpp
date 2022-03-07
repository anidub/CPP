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
/*https://leetcode.com/problems/reorganize-string/
 * Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.
"vvvlo"
"vlvov"
https://leetcode.com/problems/reorganize-string/discuss/335312/C%2B%2B-Beat-100
 */

//TC : O(N). SC(1) since vector(26) is fixed
string reorganizeString(string s) {
	if(s.empty()) return "";

	vector<int> cnt(26);
	int mostFreqChar = 0; int i = 0;

	for(char& c : s) {
		cnt[c - 'a']++;
		if(cnt[c - 'a'] > cnt[mostFreqChar])
			mostFreqChar = c - 'a';
	}

	if( 2 * cnt[mostFreqChar] - 1 > s.size()) return "";

	while(cnt[mostFreqChar]) {
		s[i] = ('a' + mostFreqChar);
		cnt[mostFreqChar]--;
		i += 2;
	}

	for(int j = 0; j < 26; j++) {
		while(cnt[j]) {
			if(i >= s.size()) i = 1;
			s[i] = ('a' + j);
			cnt[j]--;
			i += 2;
		}
	}
	return s;
}
/*
int main() {
	cout << reorganizeString("vvvlo") << endl;

	return 0;
}*/
