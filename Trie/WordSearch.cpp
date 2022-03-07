#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/word-search-ii/
 * Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
https://leetcode.com/problems/word-search-ii/discuss/878708/C%2B%2BPython-Backtracking-with-Trie-Clean-and-Concise

Time: O(M * N * 4 * 3^(L-2) + S), where M*N <= 12*12 is total number of cells in the board, L <= 10 is the maximum length of words, S <= 3 * 10^5 is sum length of all words.
 Explain: Firstly, we can choose M*N cells of the board as starting position, we have 4 choices to go neighbors of the first cell, each of neighbors have total 3 choices to go to their neighbors (exclude their previous neighbor) and so on.
 S : to build trie

 Space: O(S)
Explain: The main space consumed by the algorithm is the Trie data structure we build. In the worst case where there is no overlapping of prefixes among the words, the Trie would have as many nodes as the letters of all words.
 */
struct TrieNode {
	string *word;
	TrieNode *children[26] = {};

	void addWord(string& word) {
		TrieNode *cur = this;
		for(char c : word) {
			c = c - 'a';
			if(cur->children[c] == nullptr)
				cur->children = new TrieNode();
			cur = cur->children[c];
		}
		cur->word = &word;
	}
};

int m, n;
int DIR[5] = {0, 1, 0, -1, 0};
vector<string> wordSearchResult;

void findWordSearchDFS(vector<vector<char>>& board, int r, int c, TrieNode *trieNode);

vector<string> findWordSearch(vector<vector<char>>& board,  vector<string>& words) {
	m = board.size(), n = board[0].size();
	TrieNode trieNode;
	for(string& word : words) {
		trieNode.addWord(word);
	}
	for(int r = 0; r < m; r++) {
		for(int c = 0; c < n; c++) {
			findWordSearchDFS(board, r, c, &trieNode);
		}
	}
	return wordSearchResult;
}

void findWordSearchDFS(vector<vector<char>>& board, int r, int c, TrieNode *cur) {
	if(r < 0 || r == m || c < 0 || c == n || board[r][c] == '#' || cur->children[board[r][c] - 'a'] == nullptr) return;

	char orgChar = board[r][c];
	cur = cur->children[orgChar - 'a'];
	if(cur->word != nullptr) {
		wordSearchResult.push_back(*cur->word);
		cur->word = nullptr;// Avoid duplication!
	}
	board[r][c] = '#'; // mark as visited!
	for(int i = 0; i < 4; i++)
		findWordSearchDFS(board, r + DIR[i], c + DIR[i+1], cur);
	board[r][c] = orgChar;// restore org state
}
/*
int main() {



	return 0;
}*/
