#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <stack>

using namespace std;
/*
 * Before this program do leetcode 84 *https://leetcode.com/problems/largest-rectangle-in-histogram/ (largestAreaHistogram)
 *  https://leetcode.com/problems/maximal-rectangle/
 * Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 https://leetcode.com/problems/maximal-rectangle/discuss/29059/Sharing-my-straightforward-C%2B%2B-solution-with-O(n2)-time-with-explanation
 */
int largestRectangleMatrix(vector<int>& height) {
	height.push_back(0);
	stack<int> stk;
	int max_a = 0, i = 0;

	while(i < height.size()) {
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
//TC : O(N2)
int maxAreaRectableMatrix(vector<vector<char>>& matrix) {
	if(matrix.empty()) return 0;
	int n = matrix.size(), m = matrix[0].size();
	int max_area = 0;
	vector<int> height(m, 0);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == '0')
				height[j] = 0;
			else
				height[j]++;
		}
		max_area = max(max_area, largestRectangleMatrix(height));
	}
	return max_area;

}
/*
int main() {
	vector<vector<char>> matrix;
	vector<char> m1; m1.push_back('1');m1.push_back('0');m1.push_back('1');m1.push_back('0');m1.push_back('0');
	vector<char> m2; m2.push_back('1');m2.push_back('0');m2.push_back('1');m2.push_back('1');m2.push_back('1');
	vector<char> m3; m3.push_back('1');m3.push_back('1');m3.push_back('1');m3.push_back('1');m3.push_back('1');
	vector<char> m4; m4.push_back('1');m4.push_back('0');m4.push_back('0');m4.push_back('1');m4.push_back('0');
	matrix.push_back(m1); matrix.push_back(m2); matrix.push_back(m3); matrix.push_back(m4);
	cout << maxAreaRectableMatrix(matrix) << endl;
	return 0;
}
*/
