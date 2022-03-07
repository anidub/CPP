#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/ipo/
 * Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.
The answer is guaranteed to fit in a 32-bit signed integer.
Example 1:
Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
https://leetcode.com/problems/ipo/discuss/226981/32ms-C%2B%2B-beats-100
 */

//TC : O(NLOGN)
#define pi pair<int, int>
int findMaxCapitalIPO(int k, int W, vector<int>& p, vector<int>& c) {
	int n = p.size();
	vector<pair<int, int>> projects;
	for(int i = 0; i < n; i++)
		projects.push_back({p[i], c[i]});

	sort(projects.begin(), projects.end(), [&](pi a, pi b) {return a.second < b.second;});

	priority_queue<int> pq;
	int i = 0;

	while(k) {
		while(i < n && projects[i].second <= W)
			pq.push(projects[i++].first);
		if(!pq.empty()) {
			W += pq.top();
			pq.pop();
		}
		k--;
	}
	return W;
}
/*
int main() {
	vector<int> profits; profits.push_back(1);profits.push_back(2);profits.push_back(3);
	vector<int> capital; capital.push_back(0);capital.push_back(1);capital.push_back(1);
	cout << findMaxCapitalIPO(2, 0, profits, capital) << endl;
	return 0;
}*/
