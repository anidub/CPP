#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/bulb-switcher-iii/
 * There is a room with n bulbs, numbered from 1 to n, arranged in a row from left to right. Initially, all the bulbs are turned off.
At moment k (for k from 0 to n - 1), we turn on the light[k] bulb. A bulb change color to blue only if it is on and all the previous bulbs (to the left) are turned on too.
Return the number of moments in which all turned on bulbs are blue.
Input: light = [2,1,3,5,4]
Output: 3
Explanation: All bulbs turned on, are blue at the moment 1, 2 and 4.
https://leetcode.com/problems/bulb-switcher-iii/discuss/532538/JavaC%2B%2BPython-Straight-Forward-O(1)-Space
 */

int numTimesAllBlue(vector<int>& light) {
	if(light.empty()) return 0;
	int right = 0;
	int result = 0;
	for(int i = 0; i < light.size(); i++) {
		right = max(right, light[i]);
		if(right == i+1)
			result++;
	}
	return result;
}
/*
int main() {
	vector<int> light;
	light.push_back(2);light.push_back(1);light.push_back(3);
	light.push_back(5);light.push_back(4);
	cout << numTimesAllBlue(light);
	return 0;
}
*/
