#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/check-if-it-is-a-straight-line/
 * You are given an array coordinates, coordinates[i] = [x, y],
 * where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
 * Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
 *https://leetcode.com/problems/check-if-it-is-a-straight-line/discuss/820825/C%2B%2B-simple-and-clear-solution
 	The idea is if points are on same line they have same slope.
 	//https://www.youtube.com/watch?v=PsZ_MmFBzJA
 */

bool checkStraightLine(vector<vector<int>>& coordinates) {
	if(coordinates.size() <= 2) return true;

	float x = coordinates[0][0] - coordinates[1][0];
	float y = coordinates[0][1] - coordinates[0][1];

	for(int i = 2; i < coordinates.size(); i++) {
		if(x == 0)
			if(coordinates[i][0] - coordinates[i-1][0] != 0)
				return false;
		if(y == 0)
			if(coordinates[i][1] - coordinates[i-1][1] != 0)
				return false;

		float g = y*1.0/x;
		if(x != 0 && y != 0)
			if(((coordinates[i][1] - coordinates[i-1][1]) * 1.0 /
					(coordinates[i][0] - coordinates[i-1][0])*1.0) != g)
					return false;
	}
	return true;
}

float get_slope(vector<int>& p1, vector<int>& p2) {
	if(p1[0] == p2[0])
		return INT_MAX;
	return (float) (p2[1] - p1[1])/(p2[0] - p1[0]);
}
//https://www.youtube.com/watch?v=PsZ_MmFBzJA
bool checkStraightLineOther(vector<vector<int>>& coordinates) {
	if(coordinates.size() <= 2) return true;
	float slope = get_slope(coordinates[0], coordinates[1]);
	for(int i = 2; i < coordinates.size(); i++) {
		float m = get_slope(coordinates[i], coordinates[0]);
		if(m != slope)
			return false;
	}
	return true;
}

/*
int main() {
	vector<vector<int>> coordinates;
	vector<int> nums; nums.push_back(1);nums.push_back(2);
	vector<int> nums1; nums1.push_back(2);nums1.push_back(3);
	vector<int> nums2; nums2.push_back(3);nums2.push_back(4);
	vector<int> nums3; nums3.push_back(4);nums3.push_back(5);
	vector<int> nums4; nums4.push_back(5);nums4.push_back(6);
	vector<int> nums5; nums5.push_back(6);nums5.push_back(7);

	cout << checkStraightLine(coordinates) << endl;
	cout << checkStraightLineOther(coordinates) << endl;

	return 0;
}*/

