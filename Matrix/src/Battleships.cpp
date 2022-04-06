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
/*https://leetcode.com/problems/battleships-in-a-board/
 * Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).
https://www.youtube.com/watch?v=74NuFEdzs6A : explained
https://leetcode.com/problems/battleships-in-a-board/discuss/90935/O(n2)-time-and-O(1)-space-without-modifying-the-board : used
 */
//TC : O(NM). SC: O(1)
int countBattleships(vector<vector<char>>& board) {
	if(board.empty()) return 0;
	int m = board.size(), n = board[0].size();
	int count = 0;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if( board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.')  )
					count++;
		}
	}
	return count;
}
/*
int main() {
	vector<vector<char>> board = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
	cout << countBattleships(board) << endl;

	return 0;
}*/
