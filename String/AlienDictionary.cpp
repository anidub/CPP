#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/alien-dictionary/
 * graph problem
 * There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary, where the strings in words are sorted lexicographically by the rules of this new language.

Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there is no solution, return "". If there are multiple solutions, return any of them.

A string s is lexicographically smaller than a string t if at the first letter where they differ, the letter in s comes before the letter in t in the alien language. If the first min(s.length, t.length) letters are the same, then s is smaller if and only if s.length < t.length.
Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"

https://www.youtube.com/watch?v=6kTZYvNNyps : to understand problem
https://leetcode.com/problems/alien-dictionary/discuss/157298/C%2B%2B-BFS-and-Topoligical-Sort-with-explanation
 */
//time complexity O(n), space complexity O(n)
string alienOrder(vector<string>& words) {
	if(words.empty()) return "";
	unordered_map<char, unordered_set<char>> graph;
	unordered_map<char, int> indegree;

	for(int i = 0; i < words.size(); i++) {
		for(int j = 0; j < words[i].size(); j++) {
			char c = words[i][j];
			indegree[c] = 0;
		}
	}

	for(int i = 0; i < words.size() - 1; i++) {
		string cur = words[i];
		string nex = words[i+1];
		int len = min(cur.size(), nex.size());
		for(int j = 0; j < len; j++) {
			if(cur[j] != nex[j]) {
				unordered_set<char> set = graph[cur[j]];
				if(set.find(nex[j]) == set.end()) {
					graph[cur[j]].insert(nex[j]);
					indegree[nex[j]]++;
				}
				break;

			}
			if(j == len - 1 && cur.size() > nex.size()) return "";
		}
	}

	string ans;
	queue<char> q;
	for(auto& e : indegree) {
		if(e.second == 0)
			q.push(e.first);
	}

	while(!q.empty()) {
		char cur = q.front();
		ans += cur;
		q.pop();
		if(graph[cur].size() != 0) {
			for(auto& e : graph[cur]) {
				indegree[e]--;
				if(indegree[e] == 0)
					q.push(e);
			}
		}
	}
	return ans.length() == indegree.size() ? ans : "";
}
/*
int main() {
	vector<string> words = {"wrt","wrf","er","ett","rftt"};
	cout << alienOrder(words) << endl;

	return 0;
}*/
