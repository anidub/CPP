#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/myAqDMyRXn3
 * Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.
 * Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
Output: 4
Explanation: The 5th smallest number among all the arrays is 4, this can be verified from
the merged list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]


Similar Problems#
Problem 1: Given ‘M’ sorted arrays, find the median number among all arrays.

Solution: This problem is similar to our parent problem with K=Median.
So if there are ‘N’ total numbers in all the arrays we need to find the K’th minimum number where K = N/2
 */
class KthSmallestInMSortedArrays {
public:
	struct ValueCompare {
		bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
			return x.first > y.first;
		}
	};

	//TC: O(K * LogM), SC:O(M) where M is total number of input arrays
	int findKthSmallest(const vector<vector<int>> &lists, int k) {
		if(lists.empty()) return -1;
		int result = -1;

		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, ValueCompare> min_heap;

		for(int i = 0; i < lists.size(); i++) {
			min_heap.push({lists[i][0], {i, 0}});// value, {array idx, num idx}
		}

		int numCount = 0;
		while(!min_heap.empty()) {
			auto entry = min_heap.top(); min_heap.pop();
			result = entry.first;
			numCount++;
			if(numCount == k) break;

			entry.second.second++;

			if(lists[entry.second.first].size() > entry.second.second) {
				entry.first = lists[entry.second.first][entry.second.second];
				min_heap.push(entry);
			}
		}
		return result;
	}
};

/*
int main(int argc, char *argv[]) {
	KthSmallestInMSortedArrays ksmsa;
  vector<vector<int>> lists = {{2, 6, 8}, {3, 6, 7}, {1, 3, 4}};
  int result = ksmsa.findKthSmallest(lists, 5);
  cout << "Kth smallest number is: " << result;
}
*/
