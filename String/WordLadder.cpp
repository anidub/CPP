#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/word-ladder/
 * A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS
 */

//Time Complexity = O(n * m * m * 26).For word we need O(m) time where m is the word length.
//For word comparison we again need extra O(m) time.And finally we are checking for every 26 character i.e., O(26)

int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> dict(wordList.begin(), wordList.end());
	int ladder = 1;
	queue<string> todo;
	todo.push(beginWord);

	while(!todo.empty()) {
		int n = todo.size();
		for(int i = 0; i < n; i++) {
			string word = todo.front();
			todo.pop();
			if(word == endWord) return ladder;
			dict.erase(word);
			for(int j = 0; j < word.size(); j++) {
				char c = word[j];
				for(int k = 0; k < 26; k++) {//try all 26 alphabets
					word[j] = k + 'a';
					if(dict.find(word) != dict.end())
						todo.push(word);
				}
				word[j] = c;
			}
		}
		ladder++;
	}
	return 0;
}
/*
int main() {
	vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
	cout << wordLadderLength("hit", "cog", wordList) << endl;

	return 0;
}*/
