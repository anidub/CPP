#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/k-th-smallest-prime-fraction/
 *You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].
Example 1:
Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.
https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115531/C%2B%2B-9lines-priority-queue
 */

//Time: O(nlogn)
vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
	if(A.empty()) return {};
	priority_queue<pair<double, pair<int, int>>> pq;

	for(int i = 0; i < A.size(); i++)
		pq.push({-1.0*A[i]/A.back(), {i, A.size()-1}});

	while(--K > 0) {
		pair<int, int> cur = pq.top().second;
		pq.pop();
		cur.second--;
		pq.push({-1.0*A[cur.first]/A[cur.second], {cur.first, cur.second}});
	}
	return {A[pq.top().second.first], A[pq.top().second.second]};
}
/*
int main() {
	vector<int> A;
	A.push_back(1);A.push_back(2);A.push_back(3);A.push_back(5);
	kthSmallestPrimeFraction(A, 3);
	return 0;
}
*/
