#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/* https://leetcode.com/problems/the-k-strongest-values-in-an-array/
 * Given an array of integers arr and an integer k.
A value arr[i] is said to be stronger than a value arr[j] if |arr[i] - m| > |arr[j] - m| where m is the median of the array.
If |arr[i] - m| == |arr[j] - m|, then arr[i] is said to be stronger than arr[j] if arr[i] > arr[j].
Return a list of the strongest k values in the array. return the answer in any arbitrary order.
Median is the middle value in an ordered integer list. More formally, if the length of the list is n, the median is the element in position ((n - 1) / 2) in the sorted list (0-indexed).
 *
 *Input: arr = [1,2,3,4,5], k = 2
Output: [5,1]
Explanation: Median is 3, the elements of the array sorted by the strongest are [5,1,4,2,3]. The strongest 2 elements are [5, 1]. [1, 5] is also accepted answer.
Please note that although |5 - 3| == |1 - 3| but 5 is stronger than 1 because 5 > 1.

 *https://leetcode.com/problems/the-k-strongest-values-in-an-array/discuss/674384/C%2B%2BJavaPython-Two-Pointers-%2B-3-Bonuses
 *
 *https://leetcode.com/problems/the-k-strongest-values-in-an-array/discuss/780156/Too-Simple-with-C%2B%2B-2pointers
 */
vector<int> getStrongest(vector<int>& arr, int k) {
	if(arr.empty()) return {};
	vector<int> result;

	sort(arr.begin(), arr.end());
	int med = arr[(arr.size() - 1)/2];

	int i = 0, j = arr.size() - 1;

	for(int x = 0; x < k; x++) {
		if(abs(arr[i] - med) > abs(arr[j] - med))
			result.push_back(arr[i++]);
		else
			result.push_back(arr[j--]);
	}
	return result;
}
/*
 * O(n + k log n)
Similar to the first bonus, but using a max heap. Why this is O(n + k log n):
nth_element is quick select, which is O(n);
priority_queue initialized with array is heapify, which is also O(n);
Pulling from priority queue is O(log n), and we do it k times.
 */
vector<int> getStrongestOptimal(vector<int>& arr, int k) {
	if(arr.empty()) return {};
	vector<int> result;

	nth_element(begin(arr), begin(arr) + (arr.size() - 1)/2, end(arr));
	int m = arr[(arr.size()-1)/2];

	auto cmp = [&](int a, int b) {
		return abs(a - m) == abs(b - m) ? a < b : abs(a-m) < abs(b-m);
	};

	priority_queue<int, vector<int>, decltype(cmp)> pq (begin(arr), end(arr), cmp);

	while(result.size() < k) {
		result.push_back(pq.top());
		pq.pop();
	}
	return result;
}
/*
int main() {
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);nums.push_back(4);nums.push_back(5);
	getStrongestOptimal(nums, 2);
	return 0;
}*/

