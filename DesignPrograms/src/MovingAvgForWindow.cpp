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
/*https://leetcode.com/problems/moving-average-from-data-stream/
 * Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.

Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3

https://leetcode.com/problems/moving-average-from-data-stream/discuss/81587/C%2B%2B-easy-solution-using-queue : comments

 */

//TC : O(1), SC: O(N) N : window size
class MovingAverageForWindow {
private :
	queue<int> q;
	int size,sum = 0;

public:
	MovingAverageForWindow(int size) {
		this->size = size;
	}

	double next(int val) {
		sum += val;
		q.push(val);
		if(q.size() > size) {
			sum -= q.front();
			q.pop();
		}
		return 1.0 * sum / q.size();
	}
};
/*
int main() {
	MovingAverageForWindow *obj = new MovingAverageForWindow(3);
	cout << obj->next(1) << endl; // return 1.0 = 1 / 1
	cout <<obj->next(10) << endl; // return 5.5 = (1 + 10) / 2
	cout <<obj->next(3) << endl; // return 4.66667 = (1 + 10 + 3) / 3
	cout <<obj->next(5) << endl; // return 6.0 = (10 + 3 + 5) / 3
}*/
