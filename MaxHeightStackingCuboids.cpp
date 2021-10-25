#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
 *Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.
Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
https://www.youtube.com/watch?v=rhEZhtoe_EQ
https://leetcode.com/problems/maximum-height-by-stacking-cuboids/discuss/970293/JavaC%2B%2BPython-DP-Prove-with-Explanation
https://leetcode.com/problems/maximum-height-by-stacking-cuboids/discuss/1048537/C%2B%2B-concise
 */
int maxHeightStackingCuboids(vector<vector<int>>& cuboids) {
	if(cuboids.empty()) return 0;
	for(auto& a : cuboids)
		sort(begin(a), end(a));
	cuboids.push_back({0, 0, 0});
	sort(begin(cuboids), end(cuboids));
	int n = cuboids.size();
	vector<int> lis(n); int res = 0;

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2])
			lis[j] = max(lis[j], cuboids[j][2] + lis[i]); //[j][2] since it the max element after sorting which we will use as height
		}
		res = max(res, lis[i]);
	}
	return res;
}
/*
int main() {
	vector<vector<int>> cuboids;
	vector<int> c1; c1.push_back(50);c1.push_back(45);c1.push_back(20);
	vector<int> c2; c2.push_back(95);c2.push_back(37);c2.push_back(53);
	vector<int> c3; c3.push_back(45);c3.push_back(23);c3.push_back(12);
	cuboids.push_back(c1);cuboids.push_back(c2);cuboids.push_back(c3);
	cout << maxHeightStackingCuboids(cuboids) << endl;

	return 0;
}*/
