#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/daily-temperatures/
 * Given an array of integers temperatures represents the daily temperatures,
 *  return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
 *   If there is no future day for which this is possible, keep answer[i] == 0 instead.
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
 https://leetcode.com/problems/daily-temperatures/discuss/1574808/C%2B%2BPython-3-Simple-Solutions-w-Explanation-Examples-and-Images-or-2-Monotonic-Stack-Approaches
 */
//Time Complexity : O(N) as we perform a max of O(2N), Space Complexity : O(1)
vector<int> dailyTemperatures(vector<int> &temperatures) {
	if(temperatures.empty()) return {};
	int n = temperatures.size();
	vector<int> ans(n);

	for(int cur = n - 2; cur >= 0; cur--) {
		int next = cur + 1;
		while(next < n && temperatures[next] <= temperatures[cur]) {
			next += ans[next] ? ans[next] : n;
		}
		if(next < n) ans[cur] = next - cur;
	}
	return ans;
}
/*
int main() {
	vector<int> temp = {73, 74, 75, 71, 69, 72,  76, 73};
	dailyTemperatures(temp);

	return 0;
}*/
