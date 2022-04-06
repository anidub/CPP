#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/add-bold-tag-in-string/
 * You are given a string s and an array of strings words. You should add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in words. If two such substrings overlap, you should wrap them together with only one pair of closed bold-tag. If two substrings wrapped by bold tags are consecutive, you should combine them.

Return s after adding the bold tags.

Input: s = "abcxyz123", words = ["abc","123"]
Output: "<b>abc</b>xyz<b>123</b>"
https://leetcode.com/problems/add-bold-tag-in-string/discuss/104295/C%2B%2B-Clean-Code-Merge-Intevals : comments
 */
//TC: O(N), SC: O(N)
string addBoldTag(string s, vector<string>& dict) {
	if(s.empty()) return ""; //ask interviewer
	if(dict.empty()) return s;

	vector<pair<int, int>> pos;
	for(auto &w : dict) {
		int len = w.length();
		for(size_t i = 0; (i = s.find(w, i)) != string::npos; i++) {
			pos.push_back({i, i + len});
		}
	}
	sort(pos.begin(), pos.end());
	vector<pair<int, int>> merged;

	for(int i = 0; i < pos.size(); i++) {
		if(merged.empty() || merged.back().second < pos[i].first)
			merged.push_back(pos[i]);
		else
			merged.back().second = max(merged.back().second, pos[i].second);
	}

	for(auto it = merged.rbegin(); it != merged.rend(); it++) {
		s.insert(it->second, "</b>");
		s.insert(it->first, "<b>");
	}
	return s;
}
/*
int main() {
	vector<string> words = {"abc","123"};
	cout << addBoldTag("abcxyz123", words) << endl;

	return 0;
}*/
