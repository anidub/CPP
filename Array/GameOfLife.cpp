#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <utility>

using namespace std;
/*
 * Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
 * https://www.youtube.com/watch?v=x1kRrOdcOAg
 *
 * idea is go in 8 directions. Any cell which comes to life mark as 2 and any cell with no life mark as 1. the video is great
 *
 */
bool isSafe(int x, int y, int R, int C) {
	return (x >= 0 && x < R && y >= 0 && y < C);
}

void gameOfLife(vector<vector<int>>& board) {
	int R = board.size(); int C = board[0].size();

	int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
	int dy[] = {0, 0, 1 ,-1, -1, 1, -1, 1};

	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			int liveCounts = 0;
			for(int k = 0; k < 8; k++) {
				if(isSafe(i + dx[k], j + dy[k], R, C) && abs(board[i + dx[k]][j + dy[k]]) == 1)
					liveCounts++;
			}

			if(board[i][j] == 0 && liveCounts == 3)
				board[i][j] = 2;
			if(board[i][j] == 1 && (liveCounts < 2 || liveCounts > 3))
				board[i][j] = -1;
		}
	}

	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			board[i][j] = board[i][j] > 0 ? 1 : 0;

}
/*
int main() {
	vector<vector<int>> board;
	vector<int> b1; b1.push_back(0);b1.push_back(1);b1.push_back(0);
	vector<int> b2; b2.push_back(0);b2.push_back(0);b2.push_back(1);
	vector<int> b3; b3.push_back(1);b3.push_back(1);b3.push_back(1);
	vector<int> b4; b4.push_back(0);b4.push_back(0);b4.push_back(0);
	board.push_back(b1);board.push_back(b2);board.push_back(b3);board.push_back(b4);
	gameOfLife(board);

	return 0;
}
*/
