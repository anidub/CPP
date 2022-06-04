#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
 * Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
 * Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/discuss/686891/C%2B%2B-map-%2B-priority_queue

https://www.educative.io/courses/grokking-the-coding-interview/gx6oKY8PGYY
 */

class FindMinimumMaximumUniqueElements{
public:
	//Time: O(nlogn), space: O(n).
	int findMinimumUniqueElementsAfterKremoval(const vector<int> &arr, int k) {
		if(arr.empty() || (int)arr.size() <= k) return 0;

		unordered_map<int, int> count; //element -> freq
		for(int n : arr)
			count[n]++;

		priority_queue<int, vector<int>, greater<int>> min_heap;

		for(auto &freq : count) {
			min_heap.push(freq.second);
		}

		while(k > 0) {
			k = k - min_heap.top();
			if(k >= 0)
				min_heap.pop();
		}
		return min_heap.size();
	}

	struct NumCompare {
		bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
			return a.second > b.second;
		}
	};

	//TC:O(N * LOGK + KLOGN), SC:O(N)
	int findMaximumUniqueElementsAfterKremoval(const vector<int> &arr, int k) {
		if(arr.empty() || arr.size() <= k) return 0;
		unordered_map<int, int> numFrequency;
		int distinctElements = 0;

		for(int n: arr)
			numFrequency[n]++;

		priority_queue<pair<int, int>, vector<pair<int, int>>, NumCompare> min_heap;

		for(auto &entry : numFrequency) {
			if(entry.second == 1)
				distinctElements++;
			else
				min_heap.push(entry);
		}

		while(k > 0 && !min_heap.empty()) {
			auto entry = min_heap.top(); min_heap.pop();
			k -= entry.second - 1;

			if(k >= 0)
				distinctElements++;
		}

		if(k > 0)
			distinctElements -= k;

		return distinctElements;
	}
};

/*
int main(int argc, char *argv[]) {
	FindMinimumMaximumUniqueElements fmme;
  int result =
		  fmme.findMinimumUniqueElementsAfterKremoval(vector<int>{7, 3, 5, 8, 5, 3, 3}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = fmme.findMinimumUniqueElementsAfterKremoval(vector<int>{3, 5, 12, 11, 12}, 3);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = fmme.findMinimumUniqueElementsAfterKremoval(
      vector<int>{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result =
  		  fmme.findMaximumUniqueElementsAfterKremoval(vector<int>{7, 3, 5, 8, 5, 3, 3}, 2);
    cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

    result = fmme.findMaximumUniqueElementsAfterKremoval(vector<int>{3, 5, 12, 11, 12}, 3);
    cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

    result = fmme.findMaximumUniqueElementsAfterKremoval(
        vector<int>{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2);
    cout << "Maximum distinct numbers after removing K numbers: " << result << endl;
}
*/
