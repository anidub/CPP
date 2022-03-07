#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/robot-bounded-in-circle/
 * On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:

The north direction is the positive direction of the y-axis.
The south direction is the negative direction of the y-axis.
The east direction is the positive direction of the x-axis.
The west direction is the negative direction of the x-axis.
The robot can receive one of three instructions:

"G": go straight 1 unit.
"L": turn 90 degrees to the left (i.e., anti-clockwise direction).
"R": turn 90 degrees to the right (i.e., clockwise direction).
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
 *Input: instructions = "GGLLGG"
Output: true
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"G": move one step. Position: (0, 2). Direction: North.
"L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: West.
"L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: South.
"G": move one step. Position: (0, 1). Direction: South.
"G": move one step. Position: (0, 0). Direction: South.
Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (0, 2) --> (0, 1) --> (0, 0).
Based on that, we return true.
https://leetcode.com/problems/robot-bounded-in-circle/discuss/1676710/Well-Detailed-Explaination-JAVA-C%2B%2B-oror-Easy-for-mind-to-Accept-it ::used

       N (0)
           |
   W (1) ------ E (3)
           |
        S (2)

        https://leetcode.com/problems/robot-bounded-in-circle/discuss/1680010/Detailed-Explanation-or-CPP-or-Thought-Process
 */
//Time Complexity :- BigO(N) Space Complexity :- BigO(1)
bool isRobotBounedCircle(string instructions) {
	if(instructions.empty()) return false;

	vector<vector<int>> dir = {{0,1}, {-1,0}, {0,-1}, {1,0}};//// Up, left, down, right
	int i = 0;
	int x = 0;
	int y = 0;

	for(int s = 0; s < instructions.length(); s++) {
		if(instructions.at(s) == 'L')
			i = (i + 1) % 4;//To avoid array out of bound exception, we are moduling by 4
		else if(instructions.at(s) == 'R')
			i = (i + 3) % 4;//One Right Turn = 3 times left Turn. (i+1)%4 represents one "L" turn, while (i+3)%4 represents one right Turn (i.e. 3"L" turns).
		else {
			x = x + dir[i][0];
			y = y + dir[i][1];
		}
	}
	// If the robot perform 1 rotation, it means  "i != 0" then it will gauranteed perform a circle & after certain rotation it will come back to the origin.
	        // But if "i is  0" , it mean's robot is moving straight, hence there is no cycle. It will never come back to origin.
	return x == 0 && y == 0 && i != 0;// (x == 0 && y == 0) We are checking is our intial position from where we started and end position where we are finishing both are same!

}

/*
int main() {
	cout << isRobotBounedCircle("GGLLGG") << endl;

	return 0;
}
*/
