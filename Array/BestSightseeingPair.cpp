#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/best-sightseeing-pair/
 * You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
Return the maximum score of a pair of sightseeing spots.
Example 1:
Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
https://leetcode.com/problems/best-sightseeing-pair/discuss/322177/C%2B%2B-O(n)-solution
A[i] + A[j] + i - j = (A[i] + i ) + (A[j] - j)
When we iterate the array A, (A[j] - j )is known.
For each index j, to make (A[i] + i) + (A[j] - j) maximum, we need to find the index i such that A[i] + i is maximum. We can record the value that gives us the max A[i] + i .
 */
int maxSoreSightseeingPair(vector<int>& A) {
	int maxScore = 0;
	int maxAiPlusi = A[0] + 0;

	for(int j = 1; j < A.size(); j++) {
		maxScore = max(maxScore, maxAiPlusi + A[j] - j);
		maxAiPlusi = max(maxAiPlusi, A[j] + j);
	}
	return maxScore;
}
/*
int main() {
	vector<int> A;
	A.push_back(8);A.push_back(1);A.push_back(5);A.push_back(2);A.push_back(6);

	cout << maxSoreSightseeingPair(A);
	return 0;
}*/
