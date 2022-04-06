#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/minimum-area-rectangle/
 * You are given an array of points in the X-Y plane points where points[i] = [xi, yi].

Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.

https://leetcode.com/problems/minimum-area-rectangle/discuss/900264/IntuitiveWith-PicturesC%2B%2BJavaExplanation
 * https://leetcode.com/problems/minimum-area-rectangle/discuss/1306328/C%2B%2B-Solution-using-Hash-Map : used
 *
 */
//Time Complexity : O(N^2), Space Complexity : O(N)
int minAreaRectangle(vector<vector<int>> &points) {
	if(points.empty()) return 0;

	unordered_map<int, unordered_set<int>> mp;

	for(auto &p : points) {
		mp[p[0]].insert(p[1]);
	}
    /*
        A ----------------------------D
        |(x1, y1)             (x2, y1)|
        |                             |
        |(x1, y2)             (x2, y2)|
        C ----------------------------B
    */

	int ans = INT_MAX;

	for(int i = 0; i < points.size() - 1; i++) {
		for(int j = i + 1; j < points.size(); j++) {
			int x1 = points[i][0];
			int y1 = points[i][1];
			int x2 = points[j][0];
			int y2 = points[j][1];

			if( (x1 != x2) && (y1 != y2) ) {
				if(mp[x1].find(y2) != mp[x1].end() && mp[x2].find(y1) != mp[x2].end())
					ans = min(ans, abs(x1 - x2) * abs(y1 - y2));
			}
		}
	}
	return ans == INT_MAX ? 0 : ans;
}
/*
int main() {
	vector<vector<int>> nums = {{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}};
	cout << minAreaRectangle(nums) << endl;

	return 0;
}
*/
