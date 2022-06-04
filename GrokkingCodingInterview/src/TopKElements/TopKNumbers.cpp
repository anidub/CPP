#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/RM535yM9DW0
 * Given an unsorted array of numbers, find the ‘K’ largest numbers in it.
 * Input: [3, 1, 5, 12, 2, 11], K = 3
Output: [5, 12, 11]
 */
class KLargestNumbers {
public:
	//TC: O(NLOGN), SC:O (K)
	vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
		if(nums.empty()) return {};
		vector<int> res;
		priority_queue<int, vector<int>, greater<int>> min_heap;

		for(int n : nums) {
			min_heap.push(n);
			if(min_heap.size() > k)
				min_heap.pop();
		}

		while(!min_heap.empty()) {
			res.push_back(min_heap.top());
			min_heap.pop();
		}
		return res;
	}
};
/*
int main(int argc, char* argv[]) {
	KLargestNumbers kln;
  vector<int> result = kln.findKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = kln.findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
*/
