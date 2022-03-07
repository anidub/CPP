#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 * A conveyor belt has packages that must be shipped from one port to another within D days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.
Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

 https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/discuss/256729/JavaC%2B%2BPython-Binary-Search
 */
int shipWithinDays(vector<int>& weights, int D) {
	if(weights.empty()) return 0;

	int left = 0, right = 0;
	for(int& w : weights) {
		left = max(left, w);
		right += w;
	}

	while(left < right) {
		int mid = (left + right)/2;
		int days = 0, cur = 0;
		for(int& w : weights) {
			if(cur + w > mid) {
				days++;
				cur = 0;
			}
			cur += w;
		}
		if(days > D) left = mid+1;
		else right = mid;
	}
	return left;
}
/*
int main() {
	vector<int> weights;
	weights.push_back(1);weights.push_back(2);weights.push_back(3);weights.push_back(4);weights.push_back(5);
	weights.push_back(6);weights.push_back(7);weights.push_back(8);weights.push_back(9);weights.push_back(10);

	cout << shipWithinDays(weights, 5) << endl;
}*/
