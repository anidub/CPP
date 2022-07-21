#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
 * Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.
Input: nums = [2,-1,2], k = 3
Output: 3

https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726/C%2B%2BJavaPython-O(N)-Using-Deque : used
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143768/C%2B%2B-solution-by-using-priority_queue
 */
//Time O(N) Space O(N)
int shortestSubarraySumK(vector<int>& A, int k) {
	if(A.empty()) return 0;
	vector<long> longArr; // converting original arr to long to avoid overflow
	deque<long> dq;
	int res = A.size() + 1;

	for(int &i : A) {
		long k = (long) i;
		longArr.push_back(k);
	}

	for(int i = 0; i < longArr.size(); i++) {
		if(i > 0)
			longArr[i] += longArr[i - 1];
		if(longArr[i] >= k)
			res = min(res, i + 1);

		while(dq.size() > 0 && longArr[i] - longArr[dq.front()] >= k) {
			int c = i - dq.front();
			res = min(res, c);
			dq.pop_front();
		}

		while(dq.size() > 0 && longArr[i] <= longArr[dq.back()])
			dq.pop_back();

		dq.push_back(i);
	}
	return res <= A.size() ? res : -1;
}

/*
int main(){
    vector<int> A = {2,-1,2};
	cout << shortestSubarraySumK(A, 3) << endl;
    return 0;
}*/
