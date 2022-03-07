#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <stack>
#include <utility>
#include <list>
#include <iterator>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/find-median-from-data-stream/
 *The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

https://www.youtube.com/watch?v=1LkOrc-Le-Y
https://www.geeksforgeeks.org/difference-between-min-heap-and-max-heap/
https://leetcode.com/problems/find-median-from-data-stream/discuss/74163/My-C%2B%2B-priority_queue-based-solution-(140-ms)
https://leetcode.com/problems/find-median-from-data-stream/discuss/275207/Solutions-to-follow-ups
follow up :
1. If all integer numbers from the stream are between 0 and 100, how would you optimize it?

We can maintain an integer array of length 100 to store the count of each number along with a total count. Then, we can iterate over the array to find the middle value to get our median.

Time and space complexity would be O(100) = O(1).

 If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
 In this case, we need an integer array of length 100 and a hashmap for these numbers that are not in [0,100].
 */
class MedianFinder {
 priority_queue<int> firstQ;
 priority_queue<int, vector<int>, greater<int>> secQ;
public:
	MedianFinder() {

	}
	//TC O(logN), SC : O(N)
	void addNum(int num) {
		if(firstQ.empty() || firstQ.top() > num) firstQ.push(num);
		else secQ.push(num);

		if(firstQ.size() + 1 < secQ.size()) {
			firstQ.push(secQ.top());
			secQ.pop();
		} else  if(firstQ.size() > secQ.size() + 1) {
			secQ.push(firstQ.top());
			firstQ.pop();
		}
	}

	//O(1)
	double findMedian() {
		if(firstQ.size() == secQ.size()) return firstQ.empty() ? 0 : (firstQ.top() + secQ.top()) / 2.0;
		else return firstQ.size() > secQ.size() ? firstQ.top() : secQ.top();
	}
};
/*
int main() {
	MedianFinder *medianFinder = new MedianFinder();
	medianFinder->addNum(1);    // arr = [1]
	medianFinder->addNum(2);    // arr = [1, 2]
	cout << medianFinder->findMedian() << endl; // return 1.5 (i.e., (1 + 2) / 2)
	medianFinder->addNum(3);    // arr[1, 2, 3]
	cout << medianFinder->findMedian() << endl; // return 2.0

	delete medianFinder;
	return 0;
}*/
