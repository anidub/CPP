#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/get-maximum-in-generated-array/
 *A dieter consumes calories[i] calories on the i-th day. For every consecutive sequence of k days, they look at T, the total calories consumed during that sequence of k days:

If T < lower, they performed poorly on their diet and lose 1 point; If T > upper, they performed well on their diet and gain 1 point; Otherwise, they performed normally and there is no change in points. Return the total number of points the dieter has after all calories.length days.

Note that: The total points could be negative.

Example 1:

Input: calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
Output: 0
Explaination: calories[0], calories[1] < lower and calories[3], calories[4] > upper, total points = 0.
Example 2:

Input: calories = [3,2], k = 2, lower = 0, upper = 1
Output: 1
Explaination: calories[0] + calories[1] > upper, total points = 1.
Example 3:

Input: calories = [6,5,0,0], k = 2, lower = 1, upper = 5
Output: 0
Explaination: calories[0] + calories[1] > upper, lower <= calories[1] + calories[2] <= upper, calories[2] + calories[3] < lower, total points = 0.
https://github.com/fsq/leetcode/blob/master/1176.%20Diet%20Plan%20Performance.cpp
https://github.com/newdee/Leetcode/blob/master/1176.diet_plan_performance.md
prefix sum
 */
int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
	if(calories.size() == 0) return 0;
	int startSum = 0;
	int points = 0;
	for(int i = 0; i < k; i++){
		startSum += calories[i];
	}

	if(startSum < lower){
		points++;
	} else if(startSum > upper) {
		points--;
	}

	for(int i = k; i < calories.size(); i++) {
		startSum = startSum - calories[i-k] + calories[i];
		if(startSum < lower)
			points++;
		else if(startSum > upper)
			points--;
	}
	return points;
}

int dietPlan(vector<int>& calories, int k, int lower, int upper) {
	if(calories.size() == 0) return 0;
	int sum = 0;int points = 0;
	for(int i = 0; i < calories.size(); i++) {
		sum += calories[i];
		if(i >= k)
			sum -= calories[i-k];
		if(i >= k-1){
			if(sum < lower)
				points--;
			else if(sum > upper)
				points++;
		}
	}
	return points;
}
/*
int main() {
	vector<int> calories;
	calories.push_back(6);calories.push_back(5);calories.push_back(0);calories.push_back(0);
	cout << dietPlanPerformance(calories, 2, 1 ,5) << endl;
	cout << dietPlan(calories, 2, 1 ,5) << endl;
	return 0;
}
*/
