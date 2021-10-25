#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/longest-well-performing-interval/
 * We are given hours, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.
Example 1:
Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
https://leetcode.com/problems/longest-well-performing-interval/discuss/334565/JavaC%2B%2BPython-O(N)-Solution-Life-needs-996-and-669
 */
//O(N)
int longestPerformingInterval(vector<int>& hours) {
	if(hours.empty()) return 0;
	int result = 0, n = hours.size(), score = 0;
	unordered_map<int, int> seen;

	for(int i = 0; i < n; i++) {
		score += hours[i] > 8 ? 1 : -1;
		if(score > 0)
			result = i + 1;
		else {
			if(seen.find(score) == seen.end())
				seen[score] = i;
			if(seen.find(score - 1) != seen.end())
				result = max(result, i - seen[score-1]);
		}
	}
	return result;
}
/*
int main() {
	vector<int> hours;
	hours.push_back(9);hours.push_back(9);hours.push_back(6);
	hours.push_back(0);hours.push_back(6);hours.push_back(6);hours.push_back(9);
	cout << longestPerformingInterval(hours) << endl;

	return 0;
}*/
