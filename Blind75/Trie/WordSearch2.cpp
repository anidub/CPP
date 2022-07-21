#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <string.h>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/word-search-ii/
 * Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
 The same letter cell may not be used more than once in a word.
 Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
 */
struct TrieNode {
	string *word;
	TrieNode *children[26];

	void addWord(string &word) {
		TrieNode *cur = this;
		for(char c : word) {
			c = c - 'a';
			if(cur->children[c] == nullptr)
				cur->children[c] = new TrieNode();
		}
		cur->word = &word;
	}

};

class WordSearch2 {
public:
	int m, n;
	int DIR[5] = {0, 1, 0, -1, 0};
	vector<string> ans;

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		if(words.empty()) return ans;
		m = board.size(), n = board[0].size();
		TrieNode trieNode;
		for(string &word : words) {
			trieNode.addWord(word);
		}
		for(int r = 0; r < m; r++) {
			for(int c = 0; c < n; c++) {
				dfs(r, c, board, &trieNode);
			}
		}
		return ans;
	}

private:
	void dfs(int r, int c, vector<vector<char>> &board, TrieNode *cur) {
		if(r < 0 || c < 0 || r == m || c == n || board[r][c] == '#' || cur->children[board[r][c] - 'a'] == nullptr)
			return;

		char orgChar = board[r][c];
		cur = cur->children[orgChar - 'a'];

		if(cur->word != nullptr) {
			ans.push_back(*cur->word);
			cur->word = nullptr; // Avoid duplication!
		}
		board[r][c] = '#'; // mark as visited!
		for(int i = 0; i < 4; i++) {
			dfs(r + DIR[i], c + DIR[i + 1], board, cur);
		}
		board[r][c] = orgChar;// restore org state
	}

};
