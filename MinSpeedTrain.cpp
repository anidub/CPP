#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
 * You are given a floating-point number hour, representing the amount of time you have to reach the office. To commute to the office, you must take n trains in sequential order. You are also given an integer array dist of length n, where dist[i] describes the distance (in kilometers) of the ith train ride.

Each train can only depart at an integer hour, so you may need to wait in between each train ride.

For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours before you can depart on the 2nd train ride at the 2 hour mark.
Return the minimum positive integer speed (in kilometers per hour) that all the trains must travel at for you to reach the office on time, or -1 if it is impossible to be on time.

Tests are generated such that the answer will not exceed 107 and hour will have at most two digits after the decimal point.

Example 1:
Input: dist = [1,3,2], hour = 6
Output: 1
Explanation: At speed 1:
- The first train ride takes 1/1 = 1 hour.
- Since we are already at an integer hour, we depart immediately at the 1 hour mark. The second train takes 3/1 = 3 hours.
- Since we are already at an integer hour, we depart immediately at the 4 hour mark. The third train takes 2/1 = 2 hours.
- You will arrive at exactly the 6 hour mark.
 *https://leetcode.com/problems/minimum-speed-to-arrive-on-time/discuss/1224648/C%2B%2B-Binary-search. : used
 *https://leetcode.com/problems/minimum-speed-to-arrive-on-time/discuss/1224661/C%2B%2B-Binary-Search
 */
//Time Complexity: O(N lg K) where N = number of trains, K = range of solution space
int minSpeedArriveTrain(vector<int>& dist, double hour) {
	if(dist.empty()) return 0;
	int low = 1, high = 1e9 + 7;

	while(low < high) {
		int mid = (low + high)/2;
		double total = 0;
		for(int i = 0; i < dist.size(); i++) {
			total = ceil(total);
			int d = dist[i];
			total += d * 1.0/mid;
		}
		if(total > hour)
			low = mid+1;
		else
			high = mid;
	}
	if(low > 1e9) return -1;
	return low;
}
/*
int main() {
	vector<int> dist;
	dist.push_back(1);dist.push_back(3);dist.push_back(2);
	cout << minSpeedArriveTrain(dist, 6) << endl;

	return 0;
}
*/
