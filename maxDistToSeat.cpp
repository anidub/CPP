#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/maximize-distance-to-closest-person/
 * You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).
There is at least one empty seat, and at least one person sitting.
Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
Return that maximum distance to the closest person.
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.

https://leetcode.com/problems/maximize-distance-to-closest-person/discuss/137912/JavaC%2B%2BPython-One-pass-Easy-Understood comments
 */


int maxDistToSeat(vector<int>& seats) {
	if(seats.empty()) return 0;
	int dist = -1;
	int j = -1;
	if(seats[0] == 1) j = 0;
	for(int i = 1; i < seats.size(); i++) {
		if(seats[i] == 1){
			if(j == -1)
				dist = max(dist, i);
			else
				dist = max(dist, (i-j)/2);
			j = i;
		}
	}
	if(seats[seats.size()-1] == 0) {
		int k = seats.size() - 1 - j;
		dist = max(dist, k);
	}
	return dist;
}
/*
int main() {
	vector<int> seats;
	seats.push_back(1);seats.push_back(0);seats.push_back(0);seats.push_back(0);
	seats.push_back(1);seats.push_back(0);seats.push_back(1);
	cout << maxDistToSeat(seats) << endl;
	return 0;
}*/
