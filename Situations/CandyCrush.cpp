#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_set>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/candy-crush/
 * This question is about implementing a basic elimination algorithm for Candy Crush.

Given an m x n integer array board representing the grid of candy where board[i][j] represents the type of candy. A value of board[i][j] == 0 represents that the cell is empty.

The given board represents the state of the game following the player's move. Now, you need to restore the board to a stable state by crushing candies according to the following rules:

If three or more candies of the same type are adjacent vertically or horizontally, crush them all at the same time - these positions become empty.
After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, then these
candies will drop until they hit a candy or bottom at the same time. No new candies will drop outside the top boundary.
After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
If there does not exist more candies that can be crushed (i.e., the board is stable), then return the current board.
You need to perform the above rules until the board becomes stable, then return the stable board.

Input: board = [[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],
[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]
Output: [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],[310,0,0,113,314],[410,0,0,213,414],
[610,211,112,313,614],[710,311,412,613,714],[810,411,512,713,1014]]
https://leetcode.com/problems/candy-crush/discuss/805400/concise-c%2B%2B-code
 */
enum class CC_DIR {
	right,
	down
};

int cc_row, cc_col;

bool crush(vector<vector<int>>& board);
bool canCrush(vector<vector<int>>& board, int i, int j, CC_DIR dir);
void drop(vector<vector<int>>& board);

// TC: O(mn)^2 .We need O(M*N)to scan the board, and we might crush only 3 candies repeatedly., SC: O(1);
vector<vector<int>> candyCrush(vector<vector<int>>& board) {
	if(board.empty()) return {};
	cc_row = board.size(), cc_col = board[0].size();
	while(crush(board)) {
		drop(board);
	}
	return board;
}

bool crush(vector<vector<int>>& board) {
	bool ret = false;
	for(int i = 0; i < cc_row; i++) {
		for(int j = 0; j < cc_col; j++) {
			int val = abs(board[i][j]);
			if(canCrush(board, i, j, CC_DIR::right)) {
				ret = true;
				board[i][j] = board[i][j+1] = board[i][j+2] = -val;
			}
			if(canCrush(board, i, j, CC_DIR::down)) {
				ret = true;
				board[i][j] = board[i+1][j] = board[i+2][j] = -val;
			}
		}
	}
	return ret;
}

bool canCrush(vector<vector<int>>& board, int i, int j, CC_DIR dir) {
	int val = abs(board[i][j]);
	if(val == 0) return false;

	if(CC_DIR::right == dir) {
		return j < cc_col - 2 && val == abs(board[i][j+1]) && val == abs(board[i][j+2]);
	} else if(CC_DIR::down == dir) {
		return i < cc_row - 2 && val == abs(board[i+1][j]) && val == abs(board[i+2][j]);
	}
	return false;
}

void drop(vector<vector<int>>& board) {
	for(int j = 0; j < cc_col; j++) {
		int offset = cc_row - 1;
		for(int i = cc_row - 1; i >= 0; i--) {
			if(board[i][j] > 0) {
				board[offset][j] = board[i][j];
				offset--;
			}
		}
		while(offset >= 0) {
			board[offset][j] = 0;
			offset--;
		}
	}
}

/*
int main() {
	vector<vector<int>> board = {{110,5,112,113,114},{210,211,5,213,214},{310,311,3,313,314},{410,411,412,5,414},{5,1,512,3,3},
								{610,4,1,613,614},{710,1,2,713,714},{810,1,2,1,1},{1,1,2,2,2},{4,1,4,4,1014}};

	candyCrush(board);
	return 0;
}*/
