#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <utility>

using namespace std;

/*
 * https://leetcode.com/problems/count-number-of-teams/
 * There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
You have to form a team of 3 soldiers amongst them under the following rules:
Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
Example 1:
Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).
https://leetcode.com/problems/count-number-of-teams/discuss/791892/C%2B%2B-oror-O(n3)-oror-104-ms-oror-O(n2)-oror-4-ms-oror-Easy-to-understand
https://leetcode.com/problems/count-number-of-teams/discuss/554795/C%2B%2BJava-O(n-*-n)-and-O(n-log-n)
https://www.youtube.com/watch?v=txbZx907vwE
 */

int numTeams(vector<int>& r) {
	if(r.size() == 0) return 0;
	int result = 0;
	int n = r.size();

	for(int i = 0; i < n-2; i++) {
		for(int j = i+1; j < n-1; j++) {
			for(int k = j+1; k < n; k++) {
				if( (r[i] > r[j] && r[j] > r[k]) || (r[i] < r[j] && r[j] < r[k]) )
					result++;
			}
		}
	}
	return result;
}

int numTeamsOptimal(vector<int>& r) {
	if(r.size() == 0) return 0;
	int result = 0;
	int n = r.size();

	for(int i = 1; i < n-1; i++) {
		int leftSmall = 0, rightLarge = 0;
		int leftLarge = 0, rightSmall = 0;

		for(int j = 0; j < i; j++) {
			if(r[j] < r[i])
				leftSmall++;
			else
				leftLarge++;
		}

		for(int j = i+1; j < n; j++) {
			if(r[j] < r[i])
				rightSmall++;
			else
				rightLarge++;
		}
		result += leftSmall * rightLarge + leftLarge * rightSmall;
	}
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(2);nums.push_back(5);nums.push_back(3);nums.push_back(4);nums.push_back(1);
	cout << numTeams(nums) << endl;
	cout << numTeamsOptimal(nums) << endl;
	return 0;
}*/
