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
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/design-circular-deque/
 * Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.

 * ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

https://leetcode.com/problems/design-circular-deque/discuss/1141921/C%2B%2B-Simplest-Solution-Short-and-Clear
 */

class CircularDeqeue {
private:
	vector<int> q;
	int head, tail, size, capacity;
public:
	CircularDeqeue(int k) : head(0), tail(0), size(0), capacity(k), q(vector<int>(k, 0)) {}

	// Adds an item at the front of Deque. Return true if the operation is successful.
	bool insertFront(int value) {
		if(isFull()) return false;
		head = head == 0 ? capacity - 1 : head - 1;
		q[head] = value;
		size++;
		return true;
	}

	// Adds an item at the rear of Deque. Return true if the operation is successful.
	bool insertLast(int value) {
		if(isFull()) return false;
		q[tail] = value;
		tail++;
		tail = tail % capacity;
		size++;
		return true;
	}

	// Deletes an item from the front of Deque. Return true if the operation is successful.
	bool deleteFront() {
		if(isEmpty()) return false;
		head = (head + 1) % capacity;
		size--;
		return true;
	}

	// Deletes an item from the rear of Deque. Return true if the operation is successful.
	bool deleteLast() {
		if(isEmpty()) return false;
		tail = tail == 0 ? capacity - 1 : tail - 1;
		size--;
		return true;
	}

	 // Get the front item from the deque.
	int getFront() {
		return isEmpty() ? -1 : q[head];
	}

	// Get the last item from the deque.
	int getRear() {
		return isEmpty() ? -1 : tail == 0 ? q[capacity - 1] : q[tail - 1];
	}

	// Checks whether the circular deque is empty or not.
	bool isEmpty() {
		return size == 0;
	}
	// Checks whether the circular deque is full or not.
	bool isFull() {
		return size == capacity;
	}
};
/*
int main() {
	CircularDeqeue *myCircularDeque = new CircularDeqeue(3);
	myCircularDeque->insertLast(1);  // return True
	myCircularDeque->insertLast(2);  // return True
	myCircularDeque->insertFront(3); // return True
	myCircularDeque->insertFront(4); // return False, the queue is full.
	myCircularDeque->getRear();      // return 2
	myCircularDeque->isFull();       // return True
	myCircularDeque->deleteLast();   // return True
	myCircularDeque->insertFront(4); // return True
	cout << myCircularDeque->getFront() << endl;     // return 4

	delete myCircularDeque;

	return 0;
}*/

