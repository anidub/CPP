#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
 * You are given an array tasks where tasks[i] = [actuali, minimumi]:

actuali is the actual amount of energy you spend to finish the ith task.
minimumi is the minimum amount of energy you require to begin the ith task.
For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.
You can finish the tasks in any order you like.

Return the minimum initial amount of energy you will need to finish all the tasks.
Example 1:
Input: tasks = [[1,2],[2,4],[4,8]]
Output: 8
Explanation:
Starting with 8 energy, we finish the tasks in the following order:
    - 3rd task. Now energy = 8 - 4 = 4.
    - 2nd task. Now energy = 4 - 2 = 2.
    - 1st task. Now energy = 2 - 1 = 1.
Notice that even though we have leftover energy, starting with 7 energy does not work because we cannot do the 3rd task.
https://www.youtube.com/watch?v=CgaYzm3s1SU
 */
//Time O(sort) Space O(sort)
int minEnergyFinishTasks(vector<vector<int>>& tasks) {
	if(tasks.empty()) return 0;
	sort(begin(tasks), end(tasks), [](vector<int>& t1, vector<int>& t2)
			{return t1[1] - t1[0] > t2[1] - t2[0];});
	int total = 0;
	for(auto& t : tasks) {
		total += t[0];
	}
	int result = total;
	for(auto& t : tasks) {
		if(t[1] > total)
			total += t[1] - total;
		total = total - t[0];
	}
	return result + total;
}
/*
int main() {
	vector<vector<int>> tasks;
	vector<int> t1; t1.push_back(1);t1.push_back(2);
	vector<int> t2; t2.push_back(2);t2.push_back(4);
	vector<int> t3; t3.push_back(4);t3.push_back(8);
	tasks.push_back(t1);tasks.push_back(t2);tasks.push_back(t3);
	cout << minEnergyFinishTasks(tasks) << endl;
	return 0;
}*/
