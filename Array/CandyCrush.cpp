#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <deque>
#include <utility>

using namespace std;
/*
 https://just4once.gitbooks.io/leetcode-notes/content/leetcode/two-pointers/723-candy-crush.html
 This question is about implementing a basic elimination algorithm for Candy Crush.

Given a 2D integer array board representing the grid of candy, different positive integers board[i][j] represent different types of candies. A value of board[i][j] = 0 represents that the cell at position (i, j) is empty. The given board represents the state of the game following the player's move. Now, you need to restore the board to a stable state by crushing candies according to the following rules:

If three or more candies of the same type are adjacent vertically or horizontally, "crush" them all at the same time - these positions become empty.
After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, then these candies will drop until they hit a candy or bottom at the same time. (No new candies will drop outside the top boundary.)
After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
If there does not exist more candies that can be crushed (ie. the board is stable), then return the current board.
You need to perform the above rules until the board becomes stable, then return the current board.

Example:

Input:
board =
[[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]
Output:
[[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],[310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],[710,311,412,613,714],[810,411,512,713,1014]]


 Mark the crushed candidate directly on the board by negating the value
We check in group of 3, if they are the same absolute value, we mark them for crushing step
Time complexity O((rc)^2), because it costs 3rc to scan the whole board then we call at most rc/3 times
Space complexity O(1)

for iterative: http://shibaili.blogspot.com/2019/01/723-candy-crush.html
https://www.youtube.com/watch?v=p4jExm5Zf6Q


Java:
	public static void main(String[] args) {
		System.out.println("Hello World");
		int[][] board = {{110,5,112,113,114},{210,211,5,213,214},{310,311,3,313,314},{410,411,412,5,414},{5,1,512,3,3},
		                {610,4,1,613,614},{710,1,2,713,714},{810,1,2,1,1},{1,1,2,2,2},{4,1,4,4,1014}};
		int[][] output = candyCrush(board);

	}

	 public static int[][] candyCrush(int[][] board) {
        int r = board.length, c = board[0].length;
        boolean crush = false;
        System.out.println(" begin start ");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
             System.out.print(board[i][j]+ " ");
            }
            System.out.println(" ");
        }
        System.out.println(" begin end ");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                // check horizontal line
                int v = Math.abs(board[i][j]);
                if (v == 0) continue;
                if (j + 2 < c && v == Math.abs(board[i][j + 1]) && v == Math.abs(board[i][j + 2])) {
                    crush = true;
                    board[i][j] = board[i][j + 1] = board[i][j + 2] = -v;
                }
                // check vertical line
                if (i + 2 < r && v == Math.abs(board[i + 1][j]) && v == Math.abs(board[i + 2][j])) {
                    crush = true;
                    board[i][j] = board[i + 1][j] = board[i + 2][j] = -v;
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
             System.out.print(board[i][j]+ " ");
            }
            System.out.println(" ");
        }
        // crush candy
        for (int j = 0; j < c; j++) {
            int id = r - 1;
            System.out.println("id:" + id);
            for (int i = r - 1; i >= 0; i--) {
                System.out.print("before board[i][j]:" + board[i][j]);
                if (board[i][j] > 0) {
                    board[id][j] = board[i][j];
                    id--;
                }
                System.out.println(" and after board[i][j]:" + board[i][j]);
            }
            System.out.println("id:" + id);

            while (id >= 0){
                board[id][j] = 0;
                id--;
            }
            System.out.println("------------");
        }
        return crush ? candyCrush(board) : board;
    }

 */

vector<vector<int>> candyCrush(vector<vector<int>>& board) {
	int r = board.size(); int c = board[0].size();
	bool crush = false;

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			int v = abs(board[i][j]);
			if(v == 0) continue;
			if(j+2 < c && v == abs(board[i][j+1])  && v == abs(board[i][j+2])) {
				crush = true;
				board[i][j] = -v;
				board[i][j+1] = -v;
				board[i][j+2] = -v;
			}

			if(i+2 < r && v == abs(board[i+1][j]) &&  v == abs(board[i+2][j])) {
				crush = true;
				board[i][j] = -v;
				board[i+1][j] = -v;
				board[i+2][j] = -v;
			}
		}
	}

	for(int j = 0; j < c; j++) {
		int index = r-1;
		for(int i = r-1; i >= 0; i--) {
			if(board[i][j] > 0) {
				board[index][j] = board[i][j];
				index--;
			}
		}
		while(index >= 0) {
			board[index][j] = 0;
			index--;
		}
	}

	return crush ? candyCrush(board) : board;
}


/*
int main() {
	vector<vector<int>> candy;
	vector<int> nums1;
	nums1.push_back(110);nums1.push_back(5);nums1.push_back(112);nums1.push_back(113);nums1.push_back(114);
	vector<int> nums2;
	nums2.push_back(210);nums2.push_back(211);nums2.push_back(5);nums2.push_back(213);nums2.push_back(214);
	vector<int> nums3;
	nums3.push_back(310);nums3.push_back(311);nums3.push_back(3);nums3.push_back(313);nums3.push_back(314);
	vector<int> nums4;
	nums4.push_back(410);nums4.push_back(411);nums4.push_back(412);nums4.push_back(5);nums4.push_back(414);
	vector<int> nums5;
	nums5.push_back(5);nums5.push_back(1);nums5.push_back(512);nums5.push_back(3);nums5.push_back(3);
	vector<int> nums6;
	nums6.push_back(610);nums6.push_back(4);nums6.push_back(1);nums6.push_back(613);nums6.push_back(614);
	vector<int> nums7;
	nums7.push_back(710);nums7.push_back(1);nums7.push_back(2);nums7.push_back(713);nums7.push_back(714);
	vector<int> nums8;
	nums8.push_back(810);nums8.push_back(1);nums8.push_back(2);nums8.push_back(1);nums8.push_back(1);
	vector<int> nums9;
	nums9.push_back(1);nums9.push_back(1);nums9.push_back(2);nums9.push_back(2);nums9.push_back(2);
	vector<int> nums10;
	nums10.push_back(4);nums10.push_back(1);nums10.push_back(4);nums10.push_back(4);nums10.push_back(1014);

	candy.push_back(nums1);candy.push_back(nums2);candy.push_back(nums3);candy.push_back(nums4);candy.push_back(nums5);
	candy.push_back(nums6);candy.push_back(nums7);candy.push_back(nums8);candy.push_back(nums9);candy.push_back(nums10);
	candyCrush(candy);
	int r = candy.size();
	int c = candy[0].size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
         cout << candy[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}
*/
