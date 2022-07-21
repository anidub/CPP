#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/find-median-from-data-stream/
 * The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 */

class MedianFinder {
private:
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	//TC:O(LOGN), SC:O(N)
public:
	void addNum(int num) {
		if(max_heap.empty() || num < max_heap.top())
			max_heap.push(num);
		else
			min_heap.push(num);

		if(max_heap.size() > min_heap.size() + 1) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		} else if(min_heap.size() > max_heap.size() + 1) {
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
	}

	double findMedian() {
		if(max_heap.size() == min_heap.size()) return max_heap.empty() ? 0 : (max_heap.top() + min_heap.top()) / 2.0;
		else return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
	}
};
/*
int main() {
	MedianFinder mf;
	mf.addNum(1); mf.addNum(2);
	cout << mf.findMedian() << endl;
	mf.addNum(3);
	cout << mf.findMedian() << endl;
}
*/
