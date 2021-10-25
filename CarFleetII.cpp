#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/car-fleet-ii/
 * There are n cars traveling at different speeds in the same direction along a one-lane road. You are given an array cars of length n,
 * where cars[i] = [positioni, speedi] represents:
positioni is the distance between the ith car and the beginning of the road in meters. It is guaranteed that positioni < positioni+1.
speedi is the initial speed of the ith car in meters per second.
For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position.
Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the slowest car in the fleet.
Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides with the next car, or -1 if the
car does not collide with the next car. Answers within 10-5 of the actual answers are accepted.
Example 1:
Input: cars = [[1,2],[2,1],[4,3],[7,2]]
Output: [1.00000,-1.00000,3.00000,-1.00000]
Explanation: After exactly one second, the first car will collide with the second car,
and form a car fleet with speed 1 m/s. After exactly 3 seconds, the third car will collide with the fourth car, and form a car fleet with speed 2 m/s.
 *
 * https://leetcode.com/problems/car-fleet-ii/discuss/1085987/JavaC%2B%2BPython-O(n)-Stack-Solution
 */
//Time O(n) Space O(n)
vector<double> getCollisionTimes(vector<vector<int>>& A) {
	if(A.empty()) return {};

	int n = A.size(); vector<int> stack;
	vector<double> result(n, -1);

	for(int i = n-1; i >= 0; i--) {
		int curP = A[i][0], curSp = A[i][1];
		while(!stack.empty()) {
			int ahead = stack.back(), aheadP = A[ahead][0], aheadSp = A[ahead][1];
			if(curSp <= aheadSp || 1.0 * (aheadP - curP)/(curSp - aheadSp) >= result[ahead] && result[ahead] > 0)
				stack.pop_back();
			else
				break;
		}
		if(!stack.empty()) {
			int ahead = stack.back(), aheadP = A[ahead][0], aheadSp = A[ahead][1];
			result[i] = 1.0 * (aheadP - curP)/(curSp - aheadSp);
		}
		stack.push_back(i);
	}
	return result;
}
/*
int main() {
	vector<vector<int>> cars;
	vector<int> c1; c1.push_back(1);c1.push_back(2);
	vector<int> c2; c2.push_back(2);c2.push_back(1);
	vector<int> c3; c3.push_back(4);c3.push_back(3);
	vector<int> c4; c4.push_back(7);c4.push_back(2);
	cars.push_back(c1);cars.push_back(c2);cars.push_back(c3);cars.push_back(c4);
	getCollisionTimes(cars);
	return 0;
}
*/
