#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/container-with-most-water/
 * You are given an integer array height of length n.
 * There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
 */
class ContainerWithMostWater {
public:
	//TC:O(N), SC:O(1)
	int maxArea(vector<int>& height) {
		if(height.empty()) return 0;
		int i = 0, j = height.size() - 1;
		int water = 0;

		while(i < j) {
			int h = min(height[i], height[j]);
			water = max(water, (j - i) * h);

			while(i < j && height[i] <= h)
				i++;

			while(i < j && height[j] <= h)
				j--;
		}
		return water;
	}
};

/*
int main() {
	vector<int> nums = {1,8,6,2,5,4,8,3,7};
	ContainerWithMostWater cmw;
	cout << cmw.maxArea(nums) << endl;
}
*/
