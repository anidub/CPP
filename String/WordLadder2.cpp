#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
#include <string.h>

using namespace std;
/*https://leetcode.com/problems/word-ladder-ii/
 * A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists.
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
https://leetcode.com/problems/word-ladder-ii/discuss/40434/C%2B%2B-solution-using-standard-BFS-method-no-DFS-or-backtracking
 */

//TC: O(NK^2 + a) N: number of words in wordList, K :  is the maximum length of a word, a =  is the number of possible paths from beginWord to endWord in the directed graph we have.
//SC : O(NK) read solution to understand time complexity
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> st(wordList.begin(),wordList.end());
	unordered_set<string> visited;
	vector<vector<string>> ans;
	queue<vector<string>> q;
	q.push({beginWord});

	while(!q.empty()) {
		int sz = q.size();
		while(sz--) {
			auto cur_path = q.front(); q.pop();
			string last = cur_path.back();
			for(int i = 0; i < last.size(); i++) {
				string tmp = last;
				for(char ch = 'a'; ch <= 'z'; ch++) {
					tmp[i] = ch;
					if(st.find(tmp) != st.end()) {
						visited.insert(tmp);
						auto new_path = cur_path;
						new_path.push_back(tmp);

						if(tmp == endWord)
							ans.push_back(new_path);
						else
							q.push(new_path);
					}
				}
			}
		}
		for(auto &str : visited) {
			st.erase(str);
		}
	}
	return ans;
}

/*
int main() {
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
	findLadders(beginWord, endWord, wordList);

	return 0;
}*/
