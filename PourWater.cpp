#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

/*
 * https://aaronice.gitbook.io/lintcode/array/pour-water
 * We are given an elevation map,heights[i]representing the height of the terrain at that index. The width at each index is 1. AfterVunits of water fall at indexK, how much water is at each index?
Water first drops at indexKand rests on top of the highest terrain or water at that index. Then, it flows according to the following rules:
If the droplet would eventually fall by moving left, then move left.
Otherwise, if the droplet would eventually fall by moving right, then move right.
Otherwise, rise at it's current position.
Here, "eventually fall" means that the droplet will eventually be at a lower level if it moves in that direction. Also, "level" means the height of the terrain plus any water in that column.
We can assume there's infinitely high terrain on the two sides out of bounds of the array. Also, there could not be partial water being spread out evenly on more than 1 grid block - each unit of water has to be in exactly one block.
 * Input:
 heights = [2,1,1,2,1,2,2], V = 4, K = 3

Output:
 [2,2,2,3,2,2,2]
 https://zxi.mytechroad.com/blog/simulation/leetcode-755-pour-water/
 https://walkccc.me/LeetCode/problems/0755/
 * check solution with example and simulation
 */

//Time complexity: O(VK) Space complexity: O(1)
vector<int> pourWater(vector<int>& heights, int V, int K) {
	if(heights.empty()) return {};

	for(int i = 0; i < V; i++) {
		int cur = K;

		// Move left
		while(cur > 0 && heights[cur] >= heights[cur-1])
			cur--;
		cout << " cur after left :" << cur << endl;

		// Move right
		while(cur < heights.size()-1 && heights[cur] >= heights[cur+1])
			cur++;
		cout << " cur after right :" << cur << endl;

		// Move until K
		while(cur > K && heights[cur] >= heights[cur-1])
			cur--;
		cout << " cur after left K :" << cur << endl;

		heights[cur]++;
	}

	return heights;
}
/*
int main() {
	vector<int> heights;
	heights.push_back(2);heights.push_back(1);heights.push_back(1);
	heights.push_back(2);heights.push_back(1);heights.push_back(2);heights.push_back(2);
	pourWater(heights, 4, 3);

	for(int& i : heights)
		cout << i << " ";

	return 0;
}
*/
