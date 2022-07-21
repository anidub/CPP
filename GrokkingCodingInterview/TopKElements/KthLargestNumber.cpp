#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/B819G5DZBxX
 *Design a class to efficiently find the Kth largest element in a stream of numbers.

The class should have the following two things:

The constructor of the class should accept an integer array containing initial numbers from the stream and an integer ‘K’.
The class should expose a function add(int num) which will store the given number and return the Kth largest number.
Input: [3, 1, 5, 12, 2, 11], K = 4
1. Calling add(6) should return '5'.
2. Calling add(13) should return '6'.
2. Calling add(4) should still return '6'.
 */
class KthLargestNumberInStream {
public:
	struct NumCompare {
		bool operator() (const int &a, const int &b) {
			return a > b;//ascending order
		}
	};

	priority_queue<int, vector<int>, NumCompare> min_heap;
	const int k;

	KthLargestNumberInStream(const vector<int> &nums, int k) : k(k) {
		for(int i = 0; i < nums.size(); i++) {
			add(nums[i]);
		}
	}

	//TC:O(LOGK), SC:O(K)
	virtual int add(int num) {
		min_heap.push(num);

		if((int)min_heap.size() > this->k)
			min_heap.pop();

		return min_heap.top();// return the 'Kth largest number
	}
};
/*
int main(int argc, char *argv[]) {

  KthLargestNumberInStream kthLargestNumber({3, 1, 5, 12, 2, 11}, 4);
  cout << "4th largest number is: " << kthLargestNumber.add(6) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(13) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(4) << endl;
}
*/
