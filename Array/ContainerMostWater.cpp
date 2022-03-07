#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/container-with-most-water/
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
 https://leetcode.com/problems/container-with-most-water/discuss/6090/Simple-and-fast-C%2B%2BC-with-explanation
 https://leetcode.com/problems/container-with-most-water/discuss/6260/Sharing-my-simple-C%2B%2B-solution
 */

int maxAreaUnderWater(vector<int>& height) {
	if(height.empty()) return 0;
	int i = 0, j = height.size() - 1;
	int water = 0;
	while(i < j) {
		int h = min(height[i], height[j]);
		water = max(water, (j-i) * h);
		while(height[i] <= h && i < j)
			i++;
		while(height[j] <= h && i < j)
			j--;
	}
	return water;
}
/*
int main() {
	vector<int> height;
	height.push_back(1);height.push_back(8);height.push_back(6);
	height.push_back(2);height.push_back(5);height.push_back(4);
	height.push_back(8);height.push_back(3);height.push_back(7);

	cout << maxAreaUnderWater(height) << endl;
	return 0;
}*/

