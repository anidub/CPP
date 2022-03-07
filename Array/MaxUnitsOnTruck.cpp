#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/maximum-units-on-a-truck/
 * You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
https://leetcode.com/problems/maximum-units-on-a-truck/discuss/1001160/c%2B%2Bgreedybeginner-friendly
 *
 */
static bool mySortFunc(vector<int>& a, vector<int>& b) {
	return a[1] > b[1];
}

//TC : O(NlogN), where N is the number of elements in boxTypes, SC : O(1), we are always using constant amount of space (ignoring the space required by the sort algorithm)
int getMaxUnits(vector<vector<int>>& boxTypes, int truckSize) {
	if(boxTypes.empty()) return truckSize;

	sort(boxTypes.begin(), boxTypes.end(), mySortFunc);
	int ans = 0;
	for(auto box : boxTypes) {
		int x = min(box[0], truckSize);
		ans += x * box[1];
		truckSize -= x;
		if(!truckSize) break;
	}
	return ans;
}
/*
int main() {
	vector<vector<int>> boxTypes = {{1,3},{2,2},{3,1}};
	cout << getMaxUnits(boxTypes, 4) << endl;

	return 0;
}*/
