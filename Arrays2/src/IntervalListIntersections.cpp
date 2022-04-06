#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;
/*https://leetcode.com/problems/interval-list-intersections/
 * You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].
Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

https://leetcode.com/problems/interval-list-intersections/discuss/646988/C%2B%2B-or-Easy-or-6-lines-or-Two-pointer-or-100
 */
//TC: O(M + N), SC  : O(1)
vector<vector<int>> intervalListIntersections(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
	if(firstList.empty()) return { };
	if(secondList.empty()) return {}; // check with interviewer on what they want in this case if cases

	if(firstList.empty() && secondList.empty()) return {};

	vector<vector<int>> result;
	int i = 0, j = 0;

	while(i < firstList.size() && j < secondList.size()) {
		int start = max(firstList[i][0], secondList[j][0]);
		int end = min(firstList[i][1], secondList[j][1]);

		if(start <= end) result.push_back({start, end});

		if(firstList[i][1] < secondList[j][1]) i++;
		else j++;
	}
	return result;
}

/*
int main() {
	vector<vector<int>> A = {{0,2},{5,10},{13,23},{24,25}};
	vector<vector<int>> B = {{1,5},{8,12},{15,24},{25,26}};
	intervalListIntersections(A, B);

	return 0;
}*/
