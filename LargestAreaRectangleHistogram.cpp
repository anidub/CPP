#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <stack>

using namespace std;
/*https://leetcode.com/problems/largest-rectangle-in-histogram/
 * Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/29025/C%2B%2B-solution-clean-code
 */
//TC : O(N), SC: O(N)
int largestAreaHistogram(vector<int>& height) {
	if(height.empty()) return 0;

	height.push_back(0);
	int n = height.size();
	stack<int> stk;
	int i = 0, max_a = 0;

	while(i < n) {
		if(stk.empty() || height[i] >= height[stk.top()])
			stk.push(i++);
		else {
			int h = stk.top();
			stk.pop();
			max_a = max(max_a, height[h] * (stk.empty() ? i : i - stk.top() - 1));
		}
	}
	return max_a;
}
/*
int main() {
	vector<int> height;
	height.push_back(2);height.push_back(1);height.push_back(5);
	height.push_back(6);height.push_back(2);height.push_back(3);
	cout << largestAreaHistogram(height) << endl;
	return 0;
}*/
