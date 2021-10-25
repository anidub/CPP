#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/distance-between-bus-stops/
 * A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.

The bus goes along both directions i.e. clockwise and counterclockwise.

Return the shortest distance between the given start and destination stops.
Input: distance = [1,2,3,4], start = 0, destination = 2
Output: 3
Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.
Input: distance = [1,2,3,4], start = 0, destination = 3
Output: 4
Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.
https://leetcode.com/problems/distance-between-bus-stops/discuss/377568/C%2B%2B-one-pass
https://leetcode.com/problems/distance-between-bus-stops/discuss/949206/C%2B%2B
 *
 */

int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
	if(distance.size() == 0) return 0;
	int sum1 = 0; int sum2 = 0;
	if(start > destination)
		//swap(start, destination);//works

	for(int i = 0; i < distance.size(); i++) {
		if(i >= start && i < destination)
			sum1 += distance[i];
		else
			sum2 += distance[i];
	}
	return min(sum1, sum2);
}

int distanceBetweenBusStopsOther(vector<int>& distance, int start, int destination) {
	if(distance.size() == 0) return 0;
	int n = distance.size();
	int clockwise = start;	int clockwiseSum = 0;

	while(clockwise != destination) {
		clockwiseSum += distance[clockwise];
		clockwise++;
		clockwise = clockwise % n; //other wise will overflow
		cout << clockwise << endl;
	}

	int totalSum = 0;
	totalSum = accumulate(distance.begin(), distance.end(), 0);

	return min(clockwiseSum, totalSum - clockwiseSum);
}
/*
int main() {
	vector<int> distance;
	distance.push_back(1);distance.push_back(2);distance.push_back(3);distance.push_back(4);
	cout << distanceBetweenBusStops(distance, 0, 3) << endl;
	cout << distanceBetweenBusStopsOther(distance, 0, 3) << endl;

	return 0;
}*/
