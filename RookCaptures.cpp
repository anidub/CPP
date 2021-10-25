#include <iostream>
#include <vector>

using namespace std;

/*
 * Available Captures for Rook
 * https://leetcode.com/problems/available-captures-for-rook/
 * On an 8 x 8 chessboard, there is one white rook.
 * There also may be empty squares, white bishops, and black pawns.
 *   These are given as characters 'R', '.', 'B', and 'p' respectively.
 *   Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four
 cardinal directions (north, east, west, and south),
 then moves in that direction until it chooses to stop, reaches the edge of the board,
  or captures an opposite colored pawn by moving to the same square it occupies.
    Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.

https://leetcode.com/problems/available-captures-for-rook/discuss/242924/C%2B%2BJava-search-and-capture
 works
 */

int capture(vector<vector<char>>& board, int x, int y, int dx, int dy) {
    while(x > 0 && x < board.size() && y > 0 && y < board[x].size() && board[x][y] != 'B') {
        if(board[x][y] == 'p')
            return 1;
        x = x + dx;
        y = y + dy;
    }
    return 0;
}

int numRookCaptures(vector<vector<char>>& board) {
    if(board.size() == 0 || board[0].size() == 0)
        return 0;
    for(auto i = 0; i < board.size(); i++) {
        for(auto j = 0; j < board[0].size(); j++) {
            if(board[i][j] == 'R')
                return capture(board, i, j, 0, 1) + capture(board, i, j, 0, -1) + capture(board, i, j, 1, 0) + capture(board, i, j, -1, 0);
        }
    }
    return 0;
}


/*
int main {
	return 0;
}*/
