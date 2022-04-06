#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <queue>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/minesweeper/
 * You are given an m x n char matrix board representing the game board where:

'M' represents an unrevealed mine,
'E' represents an unrevealed empty square,
'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
'X' represents a revealed mine.
You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').

Return the board after revealing this position according to the following rules:

If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.
https://leetcode.com/problems/minesweeper/discuss/613483/C%2B%2B-Easy-to-understand-DFS-solution

 */
vector<pair<int, int>> mines_dir = { {-1,0}, {-1, 1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };

bool isValid(vector<vector<char>>& board, int i, int j) {
	return ( i >= 0 && i < board.size() && j >= 0 && j < board[0].size() );
}

int hasAdjacentMine(vector<vector<char>>& board, int i, int j) {
	int count = 0;
	for(int k = 0; k < 8; k++) {
		int I = i + mines_dir[k].first;
		int J = j + mines_dir[k].second;
		if(isValid(board, I, J) && board[I][J] == 'M')
			count++;
	}
	return count;

}

void updateBoardDFS(vector<vector<char>>& board, vector<vector<bool>> visited, int i, int j) {
	if(min(i, j) < 0 || i >= board.size() || j >= board[0].size() || visited[i][j]  ) return;

	visited[i][j] = true;

	if(board[i][j] == 'M') {
		board[i][j] = 'X';
		return;
	}

	if(board[i][j] == 'E') {
		int c = hasAdjacentMine(board, i, j);
		if(c == 0) {
			board[i][j] = 'B';
			for(int k = 0; k < 8; k++) {
				updateBoardDFS(board, visited, i + mines_dir[k].first, j + mines_dir[k].second);
			}
		} else {
			board[i][j] = c + '0';
			return;
		}
	}

}
//TC: O(MN) | SC: O(M+N)
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    updateBoardDFS(board, visited, click[0], click[1]);
}

/*
int main() {
	vector<vector<char>> board = {{'E','E','E','E','E'}, {'E','E','M','E','E'}, {'E','E','E','E','E'},
			{'E','E','E','E','E'}};
	vector<int> click = {3, 0};
	updateBoard(board, click);
	return 0;
}*/
