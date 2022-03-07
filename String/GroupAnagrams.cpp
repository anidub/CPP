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
/*https://leetcode.com/problems/group-anagrams/
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

https://leetcode.com/problems/group-anagrams/discuss/19200/C%2B%2B-unordered_map-and-counting-sort : comments
 */


string countSort(string s);

//TC: ON(LOGN) SC: O(N)
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	if(strs.empty()) return {};
	unordered_map<string, vector<string>> mp;
	for(string &s : strs) {
		string t = s;
		sort(t.begin(), t.end());//mp[countSort(s)].push_back(s); if only lower case as its faster
		mp[t].push_back(s);
	}
	vector<vector<string>> res;
	for(auto &p : mp) {
		res.push_back(p.second);
	}
	return res;
}

string countSort(string s) {
	int charExist[26] = {0};
	for(int i = 0; i < s.size(); i++)
		charExist[s[i] - 'a']++;

	int j = 0;
	string res;
	while(j < 26) {
		if(charExist[j] == 0)
			j++;
		else {
			res.push_back(j + 'a');
			charExist[j]--;
		}
	}
	return res;
}
/*
int main() {
	vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
	groupAnagrams(strs);
	return 0;
}*/
