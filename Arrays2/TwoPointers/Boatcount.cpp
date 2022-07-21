#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/boats-to-save-people/
 * You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
https://leetcode.com/problems/boats-to-save-people/discuss/1877945/JavaC%2B%2B-A-very-Easy-EXPLANATION-oror-TRUST-ME-lessgreater
 */
//TC: O(NLOGN), SC: O(1)
int numRescueBoats(vector<int>& people, int limit) {
	if(people.empty()) return 0;
	sort(people.begin(), people.end());

	int left = 0, right = people.size() - 1;
	int count = 0;

	while(left <= right) {
		int sum = people[left] + people[right];
		if(sum <= limit) {
			count++;
			left++;
			right--;
		} else {  // if sum is over the limit, heaviest will go alone.
			count++;
			right--;
		}
	}
	return count;
}
/*
int main() {
	vector<int> people = {3,5,3,4};
	cout << numRescueBoats(people, 5) << endl;
	return 0;
}*/
