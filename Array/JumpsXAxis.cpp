#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_set>
#include <queue>

using namespace std;
/*
 * https://leetcode.com/problems/minimum-jumps-to-reach-home/
 * A certain bug's home is on the x-axis at position x. Help them get there from position 0.
The bug jumps according to the following rules:
It can jump exactly a positions forward (to the right).
It can jump exactly b positions backward (to the left).
It cannot jump backward twice in a row.
It cannot jump to any forbidden positions.
The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers.
Given an array of integers forbidden, where forbidden[i] means that the bug cannot jump to the position forbidden[i], and integers a, b, and x, return the minimum number of jumps needed for the bug to reach its home. If there is no possible sequence of jumps that lands the bug on position x, return -1.
Example 1:
Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
Output: 3
Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.
https://leetcode.com/problems/minimum-jumps-to-reach-home/discuss/943895/C%2B%2B-BFS-Solution
 */
int minimumJumpsXAxis(vector<int>& forbidden, int a, int b, int x) {
	unordered_set<int> forbidIndex;
	for(int& f : forbidden)
		forbidIndex.insert(f);

	vector<pair<bool, bool>> visited(6000, {false, false});
	visited[0].first = true;
	queue<pair<int, bool>> q;
	q.push({0, false});
	int stepCount = 0;

	while(q.size() > 0) {
		int size = q.size();
		while(size--) {
			int currentIndex = q.front().first;
			int prevBackward = q.front().second;
			q.pop();
			if(currentIndex == x)
				return stepCount;
			else {
				int nextIndex = currentIndex + a;
				if(nextIndex < 6000 && forbidIndex.count(nextIndex)==0 && !visited[nextIndex].first) {
					q.push({nextIndex, false});
					visited[nextIndex].first = true;
				}
				if(!prevBackward) {
					nextIndex = currentIndex - b;
					if(nextIndex > 0 && forbidIndex.count(nextIndex) == 0 && !visited[nextIndex].second) {
						q.push({nextIndex, true});
						visited[nextIndex].second = true;
					}
				}
			}
		}
		stepCount++;
	}
	return -1;
}
/*
int main() {
	vector<int> forbidden;
	forbidden.push_back(14);forbidden.push_back(4);forbidden.push_back(18);forbidden.push_back(1);forbidden.push_back(15);
	cout << minimumJumpsXAxis(forbidden, 3, 15, 9) << endl;

	return 0;
}*/
