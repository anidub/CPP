#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <queue>

using namespace std;

typedef vector<int, int> P;
/*
 * https://leetcode.com/problems/maximum-number-of-eaten-apples/
 * There is a special kind of apple tree that grows apples every day for n days. On the ith day, the tree grows apples[i] apples that will rot after days[i] days, that is on day i + days[i] the apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any apples, which are denoted by apples[i] == 0 and days[i] == 0.
You decided to eat at most one apple a day (to keep the doctors away). Note that you can keep eating after the first n days.
Given two integer arrays days and apples of length n, return the maximum number of apples you can eat.

Example 1:
Input: apples = [1,2,3,5,2], days = [3,2,1,4,2]
Output: 7
Explanation: You can eat 7 apples:
- On the first day, you eat an apple that grew on the first day.
- On the second day, you eat an apple that grew on the second day.
- On the third day, you eat an apple that grew on the second day. After this day, the apples that grew on the third day rot.
- On the fourth to the seventh days, you eat apples that grew on the fourth day.
 *
 *
 *
 *
 https://leetcode.com/problems/maximum-number-of-eaten-apples/discuss/988328/C%2B%2B-Clean-and-Clear-Easy-to-understand-MinHeap


 WORKS!!/ ON(logN) time
int eatenApples(vector<int> apples, vector<int> days) {
	if(apples.empty()) return 0;

	priority_queue<P, vector<P>, greater<P>> queue;
	int result = 0, i = 0, n = apples.size();

	while(i < n || queue.size()) {
		//add apples
		if(i < n && apples[i] > 0)
			queue.push({i + days[i] - 1, apples[i]});

		//remove expired apples
		while(queue.size() && queue.top().first < i)
				queue.pop();

		if(queue.size()){
			auto p = queue.top();
			queue.pop();
			if(p.second > 1)
				queue.push({p.first, p.second - 1});
			result++;
		}
		i++;
	}
	return result;
}*/
/*
int main() {
	vector<int> apples; apples.push_back(1);apples.push_back(2);apples.push_back(3);
	apples.push_back(5);apples.push_back(2);

	vector<int> days; days.push_back(3);days.push_back(2);days.push_back(1);
	days.push_back(4);days.push_back(2);

	cout << eatenApples(apples, days) << endl;
	return 0;
}*/
