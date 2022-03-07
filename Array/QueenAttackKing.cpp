#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <deque>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/queens-that-can-attack-the-king/
 * On an 8x8 chessboard, there can be multiple Black Queens and one White King.

Given an array of integer coordinates queens that represents the positions of the Black Queens, and a pair of coordinates king that represent the
position of the White King, return the coordinates of all the queens (in any order) that can attack the King.
Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
Output: [[0,1],[1,0],[3,3]]
Explanation:
The queen at [0,1] can attack the king cause they're in the same row.
The queen at [1,0] can attack the king cause they're in the same column.
The queen at [3,3] can attack the king cause they're in the same diagnal.
The queen at [0,4] can't attack the king cause it's blocked by the queen at [0,1].
The queen at [4,0] can't attack the king cause it's blocked by the queen at [1,0].
The queen at [2,4] can't attack the king cause it's not in the same row/column/diagonal as the king.

https://leetcode.com/problems/queens-that-can-attack-the-king/discuss/403755/C%2B%2B-Tracing //used
https://leetcode.com/problems/queens-that-can-attack-the-king/discuss/406187/4ms-c%2B%2B
 *
 */
vector<vector<int>> queenAttackKing(vector<vector<int>>& queens, vector<int>& king) {
	if(queens.size() == 0 || king.size() == 0) return {};
	bool board[8][8] = {};
	vector<vector<int>> result;

	for(auto& q : queens) {
		board[q[0]][q[1]] = true;
	}

	for(int i = -1; i <= 1; i++) {
		for(int j = -1; j <= 1; j++) {
			if(i == 0 && j == 0) continue; //since we want to ignore king itself in loop
			auto x = king[0] + i;
			auto y = king[1] + j;
			while(min(x,y) >= 0 && max(x,y) < 8) {
				if(board[x][y]) {
					result.push_back({x,y});
					break;
				}
				x += i;
				y += j;
			}
		}
	}
	for(auto& r : result) {
		for(auto& i : r) {
			cout << " " <<  i;
		}
		cout << endl;
	}
	return result;
}
/*
int main() {
	vector<vector<int>> queens;
	vector<int> king; king.push_back(0);king.push_back(0);

	vector<int> nums1; nums1.push_back(0); nums1.push_back(1);
	vector<int> nums2; nums2.push_back(1); nums2.push_back(0);
	vector<int> nums3; nums3.push_back(4); nums3.push_back(0);
	vector<int> nums4; nums4.push_back(0); nums4.push_back(4);
	vector<int> nums5; nums5.push_back(3); nums5.push_back(3);
	vector<int> nums6; nums6.push_back(2); nums6.push_back(4);

	queens.push_back(nums1);queens.push_back(nums2);queens.push_back(nums3);
	queens.push_back(nums4);queens.push_back(nums5);queens.push_back(nums6);
	queenAttackKing(queens, king);

	return 0;
}*/
