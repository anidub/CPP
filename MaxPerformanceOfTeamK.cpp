#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/maximum-performance-of-a-team/
 * You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.
Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.
Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.
Example 1:
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation:
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.

 https://leetcode.com/problems/maximum-performance-of-a-team/discuss/539687/JavaC%2B%2BPython-Priority-Queue
 */
/*Time O(NlogN) for sorting
Time O(NlogK) for priority queue
Space O(N)*/
int maxPerformanceOfTeamK(vector<int>& efficiency, vector<int>& speed, int n, int k) {
	vector<pair<int,int>> effSpeed(n);
	for(int i = 0; i < n; i++)
		effSpeed[i] = {efficiency[i], speed[i]};

	sort(rbegin(effSpeed), rend(effSpeed));//sort the perf in descending order
	long sumS = 0, res = 0;
	priority_queue<int, vector<int>, greater<int>> pq;//priority queue to get the smallest sum
	for(auto& [e, s] : effSpeed) {
		pq.emplace(s);//push the current speed to the pq
	    sumS += s;
	    if(pq.size() > k) {
	    	sumS -= pq.top();  //remove the smallest speed
	        pq.pop();
	    }
	    res = max(res, sumS * e);//since eff is the currents small efficiency
	}
	return res % (int)(1e9+7);
}

/*
int main() {
	vector<int> speed; speed.push_back(2);speed.push_back(10);speed.push_back(3);speed.push_back(1);speed.push_back(5);speed.push_back(8);
	vector<int> efficiency; efficiency.push_back(5);efficiency.push_back(4);efficiency.push_back(3);efficiency.push_back(9);
	efficiency.push_back(7);efficiency.push_back(2);
	cout << maxPerformanceOfTeamK(efficiency, speed, 6, 2) << endl;

	return 0;
}*/
