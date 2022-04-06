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

string getStringGaps(string s);
/*https://leetcode.com/problems/group-shifted-strings/
 * We can shift a string by shifting each of its letters to its successive letter.

For example, "abc" can be shifted to be "bcd".
We can keep shifting the string to form a sequence.

For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

https://www.youtube.com/watch?v=uEXJSRLqoKY : to understand

https://leetcode.com/problems/group-shifted-strings/discuss/67451/4ms-Easy-C%2B%2B-Solution-with-Explanations
 */
//TC : O(N * K): N is size of input and K is max length of string
//SC : O(N * K)
vector<vector<string>> groupShiftedStrings(vector<string>& strings) {
	if(strings.empty()) return {};

	unordered_map<string, vector<string>> mp;

	for(string &s : strings) {
		mp[getStringGaps(s)].push_back(s);
	}

	vector<vector<string>> groups;
	for(auto it : mp) {
		vector<string> group = it.second;
		sort(group.begin(), group.end());
		 groups.push_back(group);
	}
	return groups;
}
// this function is find gaps between letters and store that as key in map
string getStringGaps(string s) {
	if(s.size() == 0) return s;
	int n = s.size();
	string gaps;
	for(int i = 1; i < n; i++) {
		int diff = s[i] - s[i-1];
		if(diff < 0) diff += 26;
		gaps += 'a' + diff;
		gaps += ','; //for second gap
	}
	return gaps;
}
/*
int main() {
	vector<string> strs = {"abc","bcd","acef","xyz","az","ba","a","z"};
	groupShiftedStrings(strs);

	return 0;
}*/
