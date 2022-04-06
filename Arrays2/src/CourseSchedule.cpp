#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/course-schedule/
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

https://leetcode.com/problems/course-schedule/discuss/58509/C%2B%2B-BFSDFS
 */
//TC: O(E + V) where E : number of dependencies and V is number of courses, SC :  O(E + V)
bool canFinishCourse(int n, vector<vector<int>>& pre) {
	vector<vector<int>> adj(n, vector<int>());
	vector<int> degree(n, 0); // stores pre req

	for(auto &p : pre) {
		adj[p[1]].push_back(p[0]);
		degree[p[0]]++;
	}

	queue<int> q; // stores courses with no pre req
	for(int i = 0; i < n; i++)
		if(degree[i] == 0) q.push(i);

	while(!q.empty()) {
		int curr = q.front(); q.pop(); n--;
		for(auto nxt : adj[curr]) {
			degree[nxt]--;
			if(degree[nxt] == 0) q.push(nxt);
		}
	}
	return n == 0;
}
/*
int main() {
	vector<vector<int>> preq = {{1,0}};
	cout << canFinishCourse(2, preq) << endl;

	return 0;
}*/
