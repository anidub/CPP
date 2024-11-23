#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <stack>
#include <utility>
#include <list>
#include <iterator>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/design-tic-tac-toe/
 * Implement the TicTacToe class:

TicTacToe(int n) Initializes the object the size of the board n.
int move(int row, int col, int player) Indicates that the player with id player plays at the cell (row, col) of the board. The move is guaranteed to be a valid move.

 *
 * Input
["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
[[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
Output
[null, 0, 0, 0, 0, 0, 0, 1]

if row == col then diag else if (row + col == size - 1) then antidiagonal
basically keep a vector row and vector col. Increments row,col, diag, anti_diag for player 1 while same decrement both player 2;
if row, col, diag, anti == size then return player 1 else if they = -size then return player 2
else draw return 0


https://www.youtube.com/watch?v=3iONGQqlj_I
https://leetcode.com/problems/design-tic-tac-toe/discuss/81913/Simple-O(1)-time-C%2B%2B-solution-following-provided-hints
 */

//TC: O(1), SC : O(N)

class TicTacToe {
private:
	vector<int> rows;
	vector<int> cols;
	int diagonal, anti_diagonal;
	int sz;
public:
	TicTacToe(int n) : sz(n) {
		rows.resize(n);
		cols.resize(n);
		diagonal = anti_diagonal = 0;
	}

	int move(int row, int col, int player) {
		if(player == 1) {
			rows[row]++, cols[col]++;
			if(row == col) diagonal++;
			if(row + col == sz - 1) anti_diagonal++;
			if(rows[row] == sz || cols[col] == sz || diagonal == sz || anti_diagonal == sz) return 1;
		} else {
			rows[row]--, cols[col]--;
			if(row == col) diagonal--;
			if(row + col == sz - 1) anti_diagonal--;
			if(rows[row] == -sz || cols[col] == -sz || diagonal == -sz || anti_diagonal == -sz)
				return 2;
		}
		return 0;
	}
};
/*
int main() {
	TicTacToe *ticTacToe = new TicTacToe(3);
	ticTacToe->move(0, 0, 1);
	ticTacToe->move(0, 2, 2);
	ticTacToe->move(2, 2, 1);
	ticTacToe->move(1, 1, 2);
	ticTacToe->move(2, 0, 1);
	ticTacToe->move(1, 0, 2);
	cout << ticTacToe->move(2, 1, 1) << endl;

	return 0;
}*/
