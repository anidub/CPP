#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <utility>
#include <unordered_map>
#include <math.h>       /* atan2 */

using namespace std;
/*https://leetcode.com/problems/maximum-number-of-visible-points/
 * You are given an array points, an integer angle, and your location, where location = [posx, posy] and points[i] = [xi, yi] both denote integral coordinates on the X-Y plane.

Initially, you are facing directly east from your position. You cannot move from your position, but you can rotate. In other words, posx and posy cannot be changed. Your field of view in degrees is represented by angle, determining how wide you can see from any given view direction. Let d be the amount in degrees that you rotate counterclockwise. Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].
 You can see some set of points if, for each point, the angle formed by the point, your position, and the immediate east direction from your position is in your field of view.

There can be multiple points at one coordinate. There may be points at your location, and you can always see these points regardless of your rotation. Points do not obstruct your vision to other points.

Return the maximum number of points you can see.
Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
Output: 3
Explanation: The shaded region represents your field of view. All points can be made visible in your field of view, including [3,3] even though [2,2] is in front and in the same line of sight.
https://leetcode.com/problems/maximum-number-of-visible-points/discuss/894732/Python-C%2B%2B-3-Simple-Steps
Asked lot in google
 */
const double pi = M_PI;

double angle_from_me(vector<int>& point, int &x1, int &y1);
/*
 * Time Complexity: O(n·log(n))
Space Complexity: O(n)
 */
int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int x1 = location[0], y1 = location[1];

        vector<vector<int>> points_not_me;
        // 1. Count and remove any points that are at your location.
        int points_on_me = 0;
        for(auto p : points) {
            if(p == location) points_on_me++;
            else points_not_me.push_back(p);
        }
        points = points_not_me;

        // 2. Calculate the angle between you and each point.
        //    i.  Sort the angles from smallest to largest.
        //    ii. Extend angles [0, 40, 355] -> [0, 40, 355, 360, 400, 715]
        //        This allows us to see that 355 is close to 0.
        vector<double> angles;
        for(auto p : points) {
            angles.push_back(angle_from_me(p, x1, y1));
            angles.push_back(angles.back() + 360);
        }
        sort(angles.begin(), angles.end());

        // 3. Use a sliding window to count the most points that can be observed.
        //    The sliding window [i,j] changes size so that all angles[i:j] are visible.
        int most_points_observable = 0, i = 0, j = 0;
        int size = angles.size();
        while(j < size) {
        	 // Increase window size (increasing j while i is constant)
            while(j < size && (angles[j] - angles[i] <= angle)) j++;
            most_points_observable = max(j - i, most_points_observable);
            // Decrease window size (increasing i while j is constant)
            while(i < j && j < size && (angles[j] - angles[i] > angle)) i++;
        }
        return points_on_me + most_points_observable;
    }

    // Returns the angle between you and point in degrees.
    double angle_from_me(vector<int>& point, int &x1, int &y1) {
        int x2 = point[0];
        int y2 = point[1];
        int height = y2 - y1;
        int width = x2 - x1;
        double alpha = atan2(height, width) * (180 / pi);
        return (alpha >= 0) ? alpha : alpha + 360;

    }
/*
int main() {
	vector<vector<int>> points = {{2,1},{2,2},{3,3}};
	vector<int> location; location.push_back(1);location.push_back(1);
	cout << visiblePoints(points, 90, location);

}*/
