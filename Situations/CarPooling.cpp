#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <sstream>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/car-pooling/
 *There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
https://leetcode.com/problems/car-pooling/discuss/1669644/Well-Explained-2-WaysJava-C%2B%2BPythonJavaScript-oror-Easy-for-mind-to-Accept-it : used
https://www.youtube.com/watch?v=Z_YMtLAmLrM : well explained
 */
//Time Complexity :- BigO(n), where n is the number of trips.
//Space Complexity :- BigO(max(n, 1001)) SINCE 1000 is the limit in question for distance
bool carPooling(vector<vector<int>> &trips, int capacity) {
	if(trips.empty()) return false;
	int timeStamp[1001] = {0};

	int in_car = 0;

	for(auto &t : trips) {// find out the number of the **net increase** passengers for each stop
		timeStamp[t[1]] += t[0];
		timeStamp[t[2]] -= t[0];
	}

	  for(int &i : timeStamp) {// from start to end, for each stop we calculate the number of passengers in the car.
		in_car += timeStamp[i];
		if(in_car > capacity) return false;// once the number of passengers in the car exceeds the capacity
	}
	return true;
}
/*
int main() {
	vector<vector<int>> trips = {{2,1,5},{3,3,7}};
	cout << carPooling(trips, 3) << endl;

	return 0;
}*/
