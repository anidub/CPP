#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <queue>
#include <set>

using namespace std;
/*https://leetcode.com/problems/robot-room-cleaner/
 * You are controlling a robot that is located somewhere in a room. The room is modeled as an m x n binary grid where 0 represents a wall and 1 represents an empty slot.

The robot starts at an unknown location in the room that is guaranteed to be empty, and you do not have access to the grid, but you can move the robot using the given API Robot.

You are tasked to use the robot to clean the entire room (i.e., clean every empty cell in the room). The robot with the four given APIs can move forward, turn left, or turn right. Each turn is 90 degrees.

When the robot tries to move into a wall cell, its bumper sensor detects the obstacle, and it stays on the current cell.
Input: room = [[1,1,1,1,1,0,1,1],[1,1,1,1,1,0,1,1],[1,0,1,1,1,1,1,1],[0,0,0,1,0,0,0,0],[1,1,1,1,1,1,1,1]], row = 1, col = 3
Output: Robot cleaned all rooms.
Explanation: All grids in the room are marked by either 0 or 1.
0 means the cell is blocked, while 1 means the cell is accessible.
The robot initially starts at the position of row=1, col=3.
From the top left corner, its position is one row below and three columns right.

https://leetcode.com/problems/robot-room-cleaner/discuss/1335015/C%2B%2B%3A-Backtracking-with-pledge-algorithm

TC: O(N - M) N : number of cells and M : number of obstacles
SC: O(N- M)
 */
class Robot {
  public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();
    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();
    // Clean the current cell.
    void clean();
};

class RobotClean {

private:
	set<pair<int,int>> cleanedCell;
	vector<vector<int>> directions {{-1,0}, {0,1}, {1,0}, {0,-1}};

	void goBack(Robot &robot) {
		robot.turnRight();
		robot.turnRight();
		robot.move();
		robot.turnRight();
		robot.turnRight();
	}

	void cleanCell(Robot &robot, int row, int col, int dir) {
		cleanedCell.insert({row, col});
		robot.clean();

		for(int i = 0; i < 4; i++) {
			int newD = (dir + i) % 4;
			int newRow = row + directions[newD][0];
			int newCol = col + directions[newD][1];

			if(!cleanedCell.count({newRow, newCol}) && robot.move()) {
				cleanCell(robot, newRow, newCol, newD);
			}
			robot.turnRight();
		}
		goBack(robot);
	}
public:
    void cleanRoom(Robot& robot) {
        cleanCell(robot, 0, 0, 0);
       // cleanCell(robot,0,0,0);
    }
};
/*
int main() {

	return 0;
}*/
