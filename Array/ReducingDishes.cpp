#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <stack>

using namespace std;
/*
 * https://leetcode.com/problems/reducing-dishes/
 * A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level  i.e.  time[i]*satisfaction[i]
Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.
Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.
 https://www.youtube.com/watch?v=mB24wDI0Bp0
 */
int maxSatisfaction(vector<int>& satisfaction) {
	if(satisfaction.empty()) return 0;
	sort(satisfaction.begin(), satisfaction.end());
	int n = satisfaction.size();
	int total = 0;
	int start = n-1;

	for(int i = n-1; i >= 0; i--) {
		total += satisfaction[i];
		if(total < 0)
			break;
		start--;
	}

	start++;
	total = 0;
	int k = 1;

	for(int i = start; i < n; i++) {
		total += (k++) * satisfaction[i];
	}
	return total;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(-1);nums.push_back(-8);nums.push_back(0);nums.push_back(5);nums.push_back(-9);
	cout << maxSatisfaction(nums) << endl;

	return 0;
}*/
