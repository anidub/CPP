#include <iostream>
/*https://leetcode.com/problems/design-bounded-blocking-queue/
 *
 * Implement a thread-safe bounded blocking queue that has the following methods:

BoundedBlockingQueue(int capacity) The constructor initializes the queue with a maximum capacity.
void enqueue(int element) Adds an element to the front of the queue. If the queue is full, the calling thread is blocked until the queue is no longer full.
int dequeue() Returns the element at the rear of the queue and removes it. If the queue is empty, the calling thread is blocked until the queue is no longer empty.
int size() Returns the number of elements currently in the queue.
Your implementation will be tested using multiple threads at the same time. Each thread will either be a producer thread that only makes calls to the enqueue method or a consumer thread that only makes calls to the dequeue method. The size method will be called after every test case.

Please do not use built-in implementations of bounded blocking queue as this will not be accepted in an interview.
Input:
1
1
["BoundedBlockingQueue","enqueue","dequeue","dequeue","enqueue","enqueue","enqueue","enqueue","dequeue"]
[[2],[1],[],[],[0],[2],[3],[4],[]]

Output:
[1,0,2,2]

Explanation:
Number of producer threads = 1
Number of consumer threads = 1

BoundedBlockingQueue queue = new BoundedBlockingQueue(2);   // initialize the queue with capacity = 2.

queue.enqueue(1);   // The producer thread enqueues 1 to the queue.
queue.dequeue();    // The consumer thread calls dequeue and returns 1 from the queue.
queue.dequeue();    // Since the queue is empty, the consumer thread is blocked.
queue.enqueue(0);   // The producer thread enqueues 0 to the queue. The consumer thread is unblocked and returns 0 from the queue.
queue.enqueue(2);   // The producer thread enqueues 2 to the queue.
queue.enqueue(3);   // The producer thread enqueues 3 to the queue.
queue.enqueue(4);   // The producer thread is blocked because the queue's capacity (2) is reached.
queue.dequeue();    // The consumer thread returns 2 from the queue. The producer thread is unblocked and enqueues 4 to the queue.
queue.size();       // 2 elements remaining in the queue. size() is always called at the end of each test case.

https://leetcode.com/problems/design-bounded-blocking-queue/discuss/1892862/Concise-C%2B%2B-Semaphore-Solution-for-Classic-Producer-Consumer-Problem :USED
https://leetcode.com/problems/design-bounded-blocking-queue/discuss/1719876/C%2B%2Bor-mutex-and-condition-variable
 */
/*
#include<semaphore.h>

class BoundedBlockingQueue{
private:
	int capacity;
	sem_t add_sem;
	sem_t remove_sem;
	queue<int> q;
	mutex mtx;

public:
	BoundedBlockingQueue(int capacity) {
		this->capacity = capacity;
		sem_init(&add_sem, 0, capacity);
		sem_init(&remove_sem, 0, 0);
	}

	~BoundedBlockingQueue() {
		sem_destroy(&add_sem);
		sem_destory(&remove_sem);
	}

	void enqueue(int element) {
		sem_wait(&add_sem);

		mtx.lock();
		q.push(element);
		mtx.unlock();

		sem_post(&remove_sem);
	}

	int dequeue() {
		sem_wait(&remove_sem);

		mtx.lock();
		int element = q.front(); q.pop();
		mtx.unlock();

		sem_post(&add_sem);
		return element;
	}

	int size() {
		return q.size();
	}

};*/
