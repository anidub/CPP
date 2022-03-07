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
/*https://leetcode.com/problems/n-queens/
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
https://leetcode.com/problems/n-queens/discuss/1223934/C%2B%2B-oror-Commented
 */

vector<vector<string>> resultNQueen;

void printNQueen(vector<vector<string>> resultNQueen) {
	for(auto& i : resultNQueen) {
		for(auto& k : i){
		cout << k << ",";
		}
		cout << endl;

	}
	return;
}

bool canPlaceQueen(vector<string>& board, int row, int index) {
	 //check up in the column;
	for(int i = row; i >= 0; i--) {
		if(board[i][index] == 'Q')
			return false;
	}

	 //check diagoanlly up left
	for(int i = row, j = index; i >= 0 && j >= 0; i--,j--) {
		if(board[i][j] == 'Q')
			return false;
	}
	 //check diagonally up right
	for(int i = row, j = index; i >= 0 && j < board.size(); i--,j++) {
		if(board[i][j] == 'Q')
			return false;
	}
    //we wont check down because we are placing the queens from top to bottom
    //i.e first row to last row so we dont have any queens down the side
    //so if some queen is placed down afterwards it checks with this queen too
	return true;
}

void findPlaces(vector<string> board, int row) {
	if(row == board.size()) {
		resultNQueen.push_back(board);
		return;
	}

	for(int i = 0; i < board.size(); i++) {
		//if i can place queen in the row at some pos i
		if(canPlaceQueen(board, row, i)) {
			board[row][i] = 'Q';//place queen in next row
			findPlaces(board, row+1);//back to normal to find other places
			board[row][i] = '.';
		}
	}
}

vector<vector<string>> solveNQueen(int n) {
	 //since it is not possible to place n queens
	if(n == 0 || n == 2 || n == 3)
		return resultNQueen;

    //initialize board
    //if n=3 then  {...,...,...}
	vector<string> board(n, string(n, '.'));
	findPlaces(board, 0);
	printNQueen(resultNQueen);
	return resultNQueen;
}
/*
int main() {
	solveNQueen(4);
	return 0;
}*/
