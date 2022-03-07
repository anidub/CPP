#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <set>

using namespace std;
/*https://leetcode.com/problems/rectangle-area-ii/
 * We are given a list of (axis-aligned) rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] , where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner of the ith rectangle.

Find the total area covered by all rectangles in the plane. Since the answer may be too large, return it modulo 109 + 7.

Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
Output: 6
Explanation: As illustrated in the picture.
https://leetcode.com/problems/rectangle-area-ii/discuss/665264/Concise-C%2B%2B-solution-(sliced-by-y-lines-explanation-and-comments)
 */

int overlappingRectanlges(vector<vector<int>>& rectangles) {
    // sort by bottome left x
    sort(rectangles.begin(), rectangles.end());

    // collect and sort all unique y's
    set<long> ys;
    for (auto& rec : rectangles)
      ys.insert(rec[1]), ys.insert(rec[3]);

    long res = 0, mod = 1e9+7;
    long pre_y = 0; // previous y in ys
    long x_cover = 0; // total length in x covered at pre_y

    for (int y : ys) {
      (res += x_cover*(y - pre_y)) %= mod; // collect areas in [pre_y, y]

      x_cover = 0;
      vector<int> cur(2,0); // current x-interval
      for (auto& rec : rectangles) {
        if (rec[1] > y || rec[3] <= y) continue; // skip rectangles which have no overlap with y

        // compute x_cover (by merging x-intervals)
        if (cur[1] < rec[0]) { // new interval doesn't intersect cur
          x_cover += (rec[2] - rec[0]);
          cur = {rec[0], rec[2]};
        }
        else if (cur[1] < rec[2]) { // new interval intersects cur
          x_cover += (rec[2] - cur[1]);
          cur[1] = rec[2];
        }
      }

      pre_y = y;
    }

    return res;
}
/*
int main() {
	vector<vector<int>> input;
	vector<int> i1; i1.push_back(0);i1.push_back(0);i1.push_back(2);i1.push_back(2);
	vector<int> i2; i2.push_back(1);i2.push_back(0);i2.push_back(2);i2.push_back(3);
	vector<int> i3; i3.push_back(1);i3.push_back(0);i3.push_back(3);i3.push_back(1);
	input.push_back(i1);input.push_back(i2);input.push_back(i3);
	cout << overlappingRectanlges(input) << endl;

	return 0;
}*/
