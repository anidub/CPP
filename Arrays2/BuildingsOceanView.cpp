#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/buildings-with-an-ocean-view/
 * There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.
Input: heights = [4,2,3,1]
Output: [0,2,3]
Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.

https://leetcode.com/problems/buildings-with-an-ocean-view/discuss/1625988/C%2B%2B-Solution-or-Time-%3A-O(N)-Space-%3A-O(1)
 */

//TC : O(N), SC : O(1)
vector<int> findBuildings(vector<int> heights) {
	if(heights.empty()) return {};
	vector<int> res;
	int maxHeight = INT_MIN;

	for(int i = heights.size() - 1; i >= 0; i--) {
		if(heights[i] > maxHeight) {
			maxHeight = heights[i];
			res.push_back(i);
		}
	}
	reverse(res.begin(), res.end());
	return res;
}
/*
int main() {
	vector<int> heights = {4, 2, 3, 1};
	findBuildings(heights);

	return 0;
}*/
