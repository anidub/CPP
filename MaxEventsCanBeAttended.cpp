#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <sstream>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
 * Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. Notice that you can only attend one event at any time d.

Return the maximum number of events you can attend.
Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/510253/C%2B%2B-Greedy : used
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/510263/JavaC%2B%2BPython-Priority-Queue
 */
//Time: O(nlogn); Space O(N)
int maxEventsCanBAttended(vector<vector<int>>& events) {
	if(events.empty()) return 0;
	sort(events.begin(), events.end());
	priority_queue<int, vector<int>, greater<int>> ends;
	int day = 1, result = 0;
	int i = 0; int n = events.size();

	while(!ends.empty() || i < n) {
		while(i < n && events[i][0] <= day)
			ends.push(events[i++][1]);

		while(!ends.empty() && ends.top() < day)
			ends.pop();

		if(!ends.empty()) {
			result++;
			ends.pop();
		}
		day++;

	}
	return result;

}
/*
int main() {
	vector<vector<int>> events; //[[1,2],[2,3],[3,4]]
	vector<int> v1; v1.push_back(1);v1.push_back(2);
	vector<int> v2; v2.push_back(2);v2.push_back(3);
	vector<int> v3; v3.push_back(3);v3.push_back(4);
	events.push_back(v1);events.push_back(v2);events.push_back(v3);
	cout << maxEventsCanBAttended(events) << endl;

	return 0;
}*/
