#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/trapping-rain-water/
 *Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 *Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
 */
//TC:O(N), SC:O(1)
int trappingRainWater(vector<int>& height) {
	if(height.empty()) return 0;
	int water = 0, l = 0, r = height.size() - 1, minHeight = 0;

	while(l < r) {
		while(l < r && height[l] <= minHeight)
			water += minHeight - height[l++];

		while(l < r && height[r] <= minHeight)
			water += minHeight - height[r--];
		minHeight = min(height[l++], height[r--]);
	}
	return water;
}

/*
int main() {
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << trappingRainWater(height) << endl;

	return 0;
}*/
