#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <utility>
#include <iterator>

using namespace std;
/*https://leetcode.com/problems/design-circular-queue/
 * Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4

https://leetcode.com/problems/design-circular-queue/discuss/1141870/C%2B%2B-Super-Simple-Short-and-Clear-Solution
https://leetcode.com/problems/design-circular-queue/discuss/1141876/JS-Python-Java-C%2B%2B-or-Simple-Array-Solution-w-Explanation
 */
class MyCircularQueue {
	int head, tail, size, capacity;
	vector<int> q;

public:
	MyCircularQueue(int k) : head(0), tail (0), size(0), capacity(k), q(vector<int>(k, 0)) {}

	bool enQueue(int value) {
		if(isFull()) return false;
		q[tail] = value;
		tail++;
		tail = tail % capacity;
		size++;
		return true;
	}

	bool deQueue() {
		if(isEmpty()) return false;
		head = (head + 1) % capacity;
		size--;
		return true;
	}

	int front() {
		return isEmpty() ? -1 : q[head];
	}

	int rear() {
		return isEmpty() ? -1 : tail == 0 ? q[capacity - 1] : q[tail - 1];
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}

};
/*
int main() {
	MyCircularQueue myCircularQueue(3);
	myCircularQueue.enQueue(1); // return True
	myCircularQueue.enQueue(2); // return True
	myCircularQueue.enQueue(3); // return True
	myCircularQueue.enQueue(4); // return False
	myCircularQueue.rear();     // return 3
	myCircularQueue.isFull();   // return True
	myCircularQueue.deQueue();  // return True
	myCircularQueue.enQueue(4); // return True
	cout << myCircularQueue.rear() << endl;;     // return 4
}*/
