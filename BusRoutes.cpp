#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*Also graph problem
 * https://leetcode.com/problems/bus-routes/
 *You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
https://leetcode.com/problems/bus-routes/discuss/122771/C%2B%2BJavaPython-BFS-Solution
 */
// Time Complexity is O(N) where N is total nodes in the routes 2D vector which has an upper bound of having 1e5*500 elements. in comments
int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
	if(routes.empty()) return 0;
	unordered_map<int, vector<int>> routes_to_bus;
	for(int i = 0; i < routes.size(); i++) {
		for(int j : routes[i])
			routes_to_bus[j].push_back(i);
	}

	queue<pair<int, int>> bfs;
	bfs.push({S, 0});
	unordered_set<int> seen = {S};

	while(!bfs.empty()) {
		int stop = bfs.front().first, totalBuses = bfs.front().second;
		bfs.pop();
		if(stop == T)
			return totalBuses;

		for(int i : routes_to_bus[stop]){
			for(int j : routes[i]) {
				if(seen.find(j) == seen.end()) {
					seen.insert(j);
					bfs.push({j, totalBuses+1});
				}
			}
			routes[i].clear();
		}
	}
	return -1;
}
/*
int main() {
	vector<vector<int>> routes;
	vector<int> r1; r1.push_back(1);r1.push_back(2);r1.push_back(7);
	vector<int> r2; r2.push_back(3);r2.push_back(6);r2.push_back(7);
	routes.push_back(r1);routes.push_back(r2);
	cout << numBusesToDestination(routes, 1, 6) << endl;

	return 0;
}*/
