#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/gx2OqlvEnWG
 * Design a class to calculate the median of a number stream. The class should have the following two methods:

insertNum(int num): stores the number in the class
findMedian(): returns the median of all numbers inserted in the class
 */
class MedianOfStream {
priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;

public:
	//TC:O(LOGN), SC:O(1)
	void insertNum(int num) {
		if(maxheap.empty() || num <= maxheap.top()) {
			maxheap.push(num);
		} else {
			minheap.push(num);
		}

		if(maxheap.size() > minheap.size() + 1) {
			minheap.push(maxheap.top());
			maxheap.pop();
		} else if(maxheap.size() < minheap.size()) {
			maxheap.push(minheap.top());
			minheap.pop();
		}
	}

	//TC:O(1)
	double getMedian() {
		if(maxheap.size() == minheap.size()) {
			return (maxheap.top() + minheap.top()) / 2.0;
		} else
			return maxheap.top();
	}
};

/*
int main() {
	MedianOfStream ms;
	ms.insertNum(3);
	ms.insertNum(1);
	cout << "The median is: " << ms.getMedian() << endl;
	ms.insertNum(5);
	cout << "The median is: " << ms.getMedian() << endl;
	ms.insertNum(4);
	cout << "The median is: " << ms.getMedian() << endl;
}
*/
