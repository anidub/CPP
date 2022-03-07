#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_set>
#include <queue>

using namespace std;
/*1274-Number of Ships in a Rectangle
 * On the sea represented by a cartesian plane, each ship is located at an integer point, and each integer point may contain at most 1 ship.

You have a function Sea.hasShips(topRight, bottomLeft) which takes two points as arguments and returns true if and only if there is at least one ship in the rectangle represented by the two points, including on the boundary.

Given two points, which are the top right and bottom left corners of a rectangle, return the number of ships present in that rectangle. It is guaranteed that there are at most 10 ships in that rectangle.

Submissions making more than 400 calls to hasShips will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.
 *
 * Input:
ships = [[1,1],[2,2],[3,3],[5,5]], topRight = [4,4], bottomLeft = [0,0]
Output: 3
Explanation: From [0,0] to [4,4] we can count 3 ships within the range.
https://nagato1208.github.io/2019/12/01/leetcode-1274-Number-of-Ships-in-a-Rectangle/
 * https://github.com/wisdompeak/LeetCode/blob/master/Recursion/1274.Number-of-Ships-in-a-Rectangle/1274.Number-of-Ships-in-a-Rectangle.cpp // used
 */
/*
class Sea {
public:
	bool hasShips(vector<int> topRight, vector<int> bottomLeft);
};*/
/*
int countShips(Sea sea, vector<int>& topRight, vector<int>& bottomLeft) {
	int x1 = bottomLeft[0], x2 = topRight[0];
	int y1 = bottomLeft[1], y2 = bottomLeft[1];

	int x3 = (x1+x2)/2, y3 = (y1+y2)2;

	if(x1 == x2 & y1 == y2) return sea.hasShips(topRight, bottomLeft);

	int a,b,c,d;
	if(x3 >= x1 && y3 >= y1 && sea.hasShips({x3, y3}, {x1,y1}))
			a = countShips(sea, {x3,y3}, {x1,y1});
	if(x2 >= x3+1 && y2 >= y1 && sea.hasShips({x2,y3}, {x3+1, y1}))
		b = countShips(sea, {x2, y3}, {x3+1, y1});
	if(x3 >= x1 && y2 >= y3+1 && sea.hasShips({x3,y2}, {x1,y3+1}))
		c = countShips(sea, {x3, y2}, {x1, y3+1});
	if(x2 >= x3+1 && y2 >= y3+1 && sea.hasShips({x2,y2}, {x3+1, y3+1}))
		d = countShips(sea, {x2,y2}, {x3+1, y3+1});

		return a+b+c+d;
}


int main() {

	return 0;
}
*/
