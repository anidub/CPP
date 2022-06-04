#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/gx6oKY8PGYY
 * Given an array of numbers and a number ‘K’, we need to remove ‘K’ numbers from the array such that we are left with maximum distinct numbers.
 * Input: [7, 3, 5, 8, 5, 3, 3], and K=2
Output: 3
Explanation: We can remove two occurrences of 3 to be left with 3 distinct numbers [7, 3, 8], we have to skip 5
because it is not distinct and appeared twice.

Another solution could be to remove one instance of '5' and '3' each to be left with three distinct numbers [7, 5, 8],
 in this case, we have to skip 3 because it appeared twice.
 */
class MaximumDistinctElements {
	struct numCompare {
		bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
			return a.second > b.second;
		}
	};
 public:

	//TC:O(NLOGK + KLOGN) SC:O(N)
  int findMaximumDistinctElements(const vector<int> &nums, int k) {
    int distinctElementsCount = 0;
    if (nums.size() <= k) {
      return distinctElementsCount;
    }
    unordered_map<int, int> numFrequency;
    for(int n : nums)
    	numFrequency[n]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, numCompare> min_heap;

    // insert all numbers with frequency greater than '1' into the min-heap
    for(auto entry : numFrequency) {
    	if(entry.second == 1)
    		distinctElementsCount++;
    	else
    		min_heap.push(entry);
    }

    // following a greedy approach, try removing the least frequent numbers first from the min-heap
    while(k > 0 && !min_heap.empty()) {
    	auto entry = min_heap.top();
    	min_heap.pop();
    	 // to make an element distinct, we need to remove all of its occurrences except one
    	k -= entry.second - 1;
    	if(k >= 0)
    		distinctElementsCount++;
    }

    // if k > 0, this means we have to remove some distinct numbers
    if(k > 0)
    	distinctElementsCount -= k;

    return distinctElementsCount;
  }
};

/*
int main(int argc, char *argv[]) {
	MaximumDistinctElements mde;
  int result =
		  mde.findMaximumDistinctElements(vector<int>{7, 3, 5, 8, 5, 3, 3}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = mde.findMaximumDistinctElements(vector<int>{3, 5, 12, 11, 12}, 3);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = mde.findMaximumDistinctElements(
      vector<int>{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;
}*/

