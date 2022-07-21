#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/course-schedule/
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
 * You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

https://www.educative.io/courses/grokking-the-coding-interview/gxJrM9goEMr
 */
class CourseSchedule {
public:
	 bool canFinish(int n, vector<vector<int>>& pre) {
		 if(n <= 0) return false;
		 vector<int> sortedOrder;

		 unordered_map<int, int> inDegree;
		 unordered_map<int, vector<int>> graph;

		 for(int i = 0; i < n; i++) {
			 inDegree[i] = 0;
			 graph[i] = vector<int>();
		 }

		 for(int i = 0; i < pre.size(); i++) {
			 int parent = pre[i][0], child = pre[i][1];
			 inDegree[child]++;
			 graph[parent].push_back(child);
		 }

		 queue<int> queue;
		 for(auto entry : inDegree) {
			 if(entry.second == 0)
				 queue.push(entry.first);
		 }

		 while(!queue.empty()) {
			 int cur = queue.front(); queue.pop();
			 sortedOrder.push_back(cur);
			 vector<int> children = graph[cur];
			 for(auto child : children) {
				 inDegree[child]--;
				 if(inDegree[child] == 0)
					 queue.push(child);
			 }
		 }
		 return sortedOrder.size() == n;

	 }
};

