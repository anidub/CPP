#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/JPGWDNRx3w2
 * Given ‘M’ sorted arrays, find the smallest range that includes at least one number from each of the ‘M’ lists.
 * Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
Output: [4, 7]
Explanation: The range [4, 7] includes 5 from L1, 4 from L2 and 7 from L3.


https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
 */
//typedef pair<int, pair<int, int>> pi;
typedef pair<int, pair<int, int>> pi;

class SmallestRange {
public:
	//TC: O(N * LOGM), SC:O(M)
	vector<int> findSmallestRange(const vector<vector<int>> &lists) {
		if(lists.empty()) return {};

		priority_queue<pi, vector<pi>, greater<pi>> min_heap;
		int mx = INT_MIN, mn = INT_MAX;

		for(int i = 0; i < lists.size(); i++) {
			min_heap.push({lists[i][0], {i, 0}}); // value, {array idx, value position}
			mx = max(mx, lists[i][0]);
			mn = min(mn, lists[i][0]);
		}

		int a = mn, b = mx;

		while(!min_heap.empty()) {
			auto cur = min_heap.top(); min_heap.pop();

			if(cur.second.second + 1 < lists[cur.second.first].size()) {
				int r = cur.second.first, c = cur.second.second + 1;

				min_heap.push({lists[r][c], {r, c}});
				mx = max(mx, lists[r][c]);
				mn = min_heap.top().first; //since min heap will always have smallest element at top
				if(b - a > mx - mn) {
					b = mx;
					a = mn;
				}
			} else {
				break;
			}
		}
		return {a, b};
	}
};

/*
int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{1, 5, 8}, {4, 12}, {7, 8, 10}};
  SmallestRange sr;
  auto result = sr.findSmallestRange(lists);
  cout << "Smallest range is: [" << result[0] << ", " << result[1] << "]";
}*/

