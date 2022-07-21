#include <iostream>
/*
 * https://leetcode.com/problems/print-zero-even-odd/
 * You have a function printNumber that can be called with an integer parameter and prints it to the console.

For example, calling printNumber(7) prints 7 to the console.
You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A: calls zero() that should only output 0's.
Thread B: calls even() that should only output even numbers.
Thread C: calls odd() that should only output odd numbers.
Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

Implement the ZeroEvenOdd class:

ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
void zero(printNumber) Calls printNumber to output one zero.
void even(printNumber) Calls printNumber to output one even number.
void odd(printNumber) Calls printNumber to output one odd number.

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.

https://leetcode.com/problems/print-zero-even-odd/discuss/1033629/C%2B%2B-Simple-3-Semaphore-easy-to-understand
 */
/*#include <semaphore.h>

class PrintZeroEvenOdd {
private:
	int n;
	sem_t zero_sem;
	sem_t even_sem;
	set_t odd_sem;

public:
	PrintZeroEvenOdd(int n) {
		this->n = n;
		sem_init(&zero_sem, 0, 1);
		sem_init(&even_sem, 0, 0);
		sem_init(&odd_sem, 0, 0);
	}

	~PrintZeroEvenOdd() {
		sem_destroy(&zero_sem);
		sem_destroy(&even_sem);
		sem_destroy(&odd_sem);
	}

	void zero(function<void()> printNumber) {
		for(int i = 1; i <= n; i++){
			sem_wait(&zero_sem);

			printNumber(0);

			if(i % 2 == 0)
				sem_post(&even_sem);
			else
				sem_post(&odd_sem);
		}
	}

	void even(function<void()> printNumber) {
		for(int i = 2; i <= n; i += 2) {
			sem_wait(&even_sem);

			printNumber(i);

			sem_post(&zero_sem);
		}
	}

	void odd(function<void()> printNumber) {
		for(int i = 1; i <= n; i += 2) {
			sem_wait(&odd_sem);

			printNumber(i);

			sem_post(&zero_sem);
		}
	}
};
*/
