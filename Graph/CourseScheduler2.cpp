#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/course-schedule-ii/
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
https://leetcode.com/problems/course-schedule-ii/discuss/59316/C%2B%2B-BFS-and-DFS : comments
 */
//both work
//TC : O(v + e) v : no of vertices e = no of edges
//SC: O(v + e
vector<int> findOrderCourse(int numCourses, vector<vector<int>>& prerequisites) {
	/*if(numCourses == 0) return {};
	vector<int> res;
	vector<vector<int>> graph(numCourses, vector<int>());
	vector<int> indegree(numCourses, 0);

	for(auto pre : prerequisites) {
		graph[pre.second].push_back(pre.first);
		indegree[pre.first]++;
	}
	queue<int> q;
	for(int i = 0; i < indegree.size(); i++) {
		if(indegree[i] == 0)
			q.push(i);
	}

	while(!q.empty()) {
		int u = q.front(); q.pop();
		res.push_back(u);

		for(auto v : graph[u]) {
			indegree[v]--;
			if(indegree[v] == 0)
				q.push(v);
		}
	}
	if(res.size() == numCourses) return res;
	return vector<int> ();*/
    vector<int> res;
    vector<int> indegree(numCourses,0);
    vector<vector<int>> adj(numCourses,vector<int>());

    for(auto i : prerequisites){
        int u = i[1], v = i[0];
        adj[u].push_back(v);
        indegree[v]++; // [0(u),1(v)] ==> 0--->1 , increase the indegree of v
    }

    queue<int> que;
    for(int i=0;i<indegree.size();i++)
        if(indegree[i]==0)
            que.push(i);

    while(!que.empty()) {
        int u = que.front();que.pop();
        res.push_back(u);
        for(auto v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0)
                que.push(v);
        }
    }
    if(res.size() == numCourses)
        return res;
    else
        return vector<int>();
}

/*
int main() {
	vector<vector<int>> prereq = {{1,0}, {2,0}, {3,1}, {3,2}};
	vector<int> res = findOrderCourse(4, prereq);
	for(auto it : res)
		cout << it << endl;

	return 0;
}*/
