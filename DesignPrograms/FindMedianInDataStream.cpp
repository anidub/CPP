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
private:
    priority_queue<int> max_heap; // max_heap for the first half to store smaller half of numbers : max element at root node
    priority_queue<int, vector<int>, greater<int>> min_heap; // min_heap for the second half to store larger half of numbers : min element at root node

public:
    // Adds a number into the data structure.
    //TC:O(LOGN), SC:O(N)
    void addNum(int num) {
        if(max_heap.empty() || (max_heap.top() > num)) max_heap.push(num);  // if it belongs to the smaller half
        else min_heap.push(num);

        // rebalance the two halfs to make sure the length difference is no larger than 1
        if(max_heap.size() > (min_heap.size() + 1)) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if(min_heap.size()  > max_heap.size() + 1 ) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(max_heap.size() == min_heap.size()) return max_heap.empty() ? 0 : (max_heap.top() + min_heap.top()) / 2.0;
        else return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
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
