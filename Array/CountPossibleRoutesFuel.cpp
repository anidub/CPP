#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/count-all-possible-routes/
 * You are given an array of distinct positive integers locations where locations[i] represents the position of city i. You are also given integers start, finish and fuel representing the starting city, ending city, and the initial amount of fuel you have, respectively.
At each step, if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length and move to city j. Moving from city i to city j reduces the amount of fuel you have by |locations[i] - locations[j]|. Please notice that |x| denotes the absolute value of x.
Notice that fuel cannot become negative at any point in time, and that you are allowed to visit any city more than once (including start and finish).
Return the count of all possible routes from start to finish.
Since the answer may be too large, return it modulo 10^9 + 7.
Example 1:

Input: locations = [2,3,6,8,4], start = 1, finish = 3, fuel = 5
Output: 4
Explanation: The following are all possible routes, each uses 5 units of fuel:
1 -> 3
1 -> 2 -> 3
1 -> 4 -> 3
1 -> 4 -> 2 -> 3

https://www.youtube.com/watch?v=npscijCCEek
 */
// Time: O(N^2 * F) // Space: O(NF)
int cache[101][201];
int mod = 1e9+7;

int dfs_countRoutes(vector<int>& locations, int cur, int goal, int fuel) {
	if(fuel < 0) return 0;
	if(cache[cur][fuel] != -1)
		return cache[cur][fuel];
	int result = 0;
	if(cur == goal)
		result++;
	for(int i = 0; i < locations.size(); i++){
		if(i == cur) continue;
		int cost = abs(locations[cur] - locations[i]);
		int nextTrip = dfs_countRoutes(locations, i, goal, fuel-cost);
		result += nextTrip;
		result %= mod;
	}
	cache[cur][fuel] = result;
	return result;
}

int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
	if(locations.empty()) return 0;
	memset(cache, -1, sizeof(cache));
	return dfs_countRoutes(locations, start, finish, fuel);
}
/*
int main() {
	vector<int> locations;
	locations.push_back(2);locations.push_back(3);locations.push_back(6);locations.push_back(8);locations.push_back(4);
	cout << countRoutes(locations, 1, 3, 5) << endl;

	return 0;
}
*/
