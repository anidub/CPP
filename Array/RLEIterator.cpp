#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/rle-iterator/
 * Write an iterator that iterates through a run-length encoded sequence.

The iterator is initialized by RLEIterator(int[] A), where A is a run-length encoding of some sequence.  More specifically, for all even i, A[i] tells us the number of times that the non-negative integer value A[i+1] is repeated in the sequence.

The iterator supports one function: next(int n), which exhausts the next n elements (n >= 1) and returns the last element exhausted in this way.  If there is no element left to exhaust, next returns -1 instead.

For example, we start with A = [3,8,0,9,2,5], which is a run-length encoding of the sequence [8,8,8,5,5].  This is because the sequence can be read as "three eights, zero nines, two fives".
Example 1:

Input: ["RLEIterator","next","next","next","next"], [[[3,8,0,9,2,5]],[2],[1],[1],[2]]
Output: [null,8,8,5,-1]
Explanation:
RLEIterator is initialized with RLEIterator([3,8,0,9,2,5]).
This maps to the sequence [8,8,8,5,5].
RLEIterator.next is then called 4 times:
.next(2) exhausts 2 terms of the sequence, returning 8.  The remaining sequence is now [8, 5, 5].

.next(1) exhausts 1 term of the sequence, returning 8.  The remaining sequence is now [5, 5].

.next(1) exhausts 1 term of the sequence, returning 5.  The remaining sequence is now [5].

.next(2) exhausts 2 terms, returning -1.  This is because the first term exhausted was 5,
but the second term did not exist.  Since the last term exhausted does not exist, we return -1.
https://leetcode.com/problems/rle-iterator/discuss/169584/C%2B%2B-solution-using-std%3A%3Aqueue
 */
struct Element {
	int value{0};
	int count{0};
	Element(int value, int count) : value{value}, count{count} {}
};

class RLEIterator {
public:
	queue<Element> myQueue;
	RLEIterator(vector<int>& A) {
		for(int index = 1; index < A.size(); index += 2) {
			if(A[index-1] > 0)
				myQueue.push(Element(A[index], A[index-1]));
		}
	}

	int next(int distance) {
		int lastValue = 0;
		while(!myQueue.empty() && myQueue.front().count <= distance) {
			lastValue = myQueue.front().value;
			distance -= myQueue.front().count;
			myQueue.pop();
		}

		if(distance == 0)
			return lastValue;
		else if(myQueue.empty() && distance > 0)
			return -1;
		else
			myQueue.front().count -= distance;

		return myQueue.front().value;
	}
};
/*
int main() {
	return 0;
}*/
