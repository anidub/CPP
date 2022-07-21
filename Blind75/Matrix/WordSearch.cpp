#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/word-search/
 * Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or
 vertically neighboring. The same letter cell may not be used more than once.
 Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
https://leetcode.com/problems/word-search/solution/
 */
class WordSearch {
public:
	//TC:O(N * 3 ^ L), SC:O(L)
	bool exist(vector<vector<char>>& board, string word) {
		if(board.empty() || board[0].size() == 0) return false;

		for(int i = 0; i < board.size(); i++) {
			for(int j = 0; j < board[0].size(); j++) {
				if(check(board,i, j, word))
					return true;
			}
		}
		return false;
	}

private:
	bool check(vector<vector<char>> &board, int i, int j, string word) {
		if(!word.size()) return true;

		if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[0])
			return false;

		char c = board[i][j];
		board[i][j] = '*';

		string s = word.substr(1);

		bool ret = check(board, i - 1, j, word) || check(board, i, j + 1, word) || check(board, i + 1, j, word) || check(board, i, j - 1, word);

		board[i][j] = c;

		return ret;
	}
};
/*
int main() {
	WordSearch sm;
	vector<vector<char>> mat = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

	sm.exist(mat, "ABCCED");
}
*/
