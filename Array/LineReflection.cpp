#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>
#include <set>

using namespace std;
/* 356. Line Reflection
 * https://www.cnblogs.com/grandyang/p/5579271.html
 * Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:

Input: [[1,1],[-1,1]]
Output: true
Example 2:

Input: [[1,1],[-1,-1]]
Output: false
Follow up:
Could you do better than O( n 2)?

Hint:

Find the smallest and largest x-value for all points.
If there is a line then it should be at y = (minX + maxX) / 2.
For each point, make sure that it has a reflected point in the opposite side.
This question gave us a bunch of points, asking us whether there is a straight line parallel to the y-axis
so that all the points are symmetric about the straight line. The hints in the question are quite adequate,
 we just need to follow the hinted steps to solve the problem. First, we find the maximum and minimum values ​​of the abscissa of all points,
 then the average of the two is the abscissa of the middle straight line,
and then we traverse each point, and if we can find another point that is linearly symmetrical, return true. Otherwise, it returns false
 */
bool isReflection(vector<pair<int, int>>& points) {
	if(points.empty()) return false;
	unordered_map<int, set<int>> mp;
	int mx = INT_MAX, mn = INT_MIN;

	for(auto p : points) {
		mx = max(mx, p.first);
		mn = min(mn, p.first);
		mp[p.first].insert(p.second);
	}

	double y = (double)(mx + mn)/2;

	for(auto p : points) {
		int t = 2 * y - p.first;
		if(!mp.count(t) || !mp[t].count(p.second))
			return false;
	}
	return true;
}
/*
int main() {
	vector<pair<int, int>> points;
	pair<int, int> p1; p1.first = 1; p1.second = 1;
	pair<int, int> p2; p2.first = -1; p2.second = 1;
	points.push_back(p1); points.push_back(p1);
	cout << isReflection(points) << endl;
	return 0;
}*/
