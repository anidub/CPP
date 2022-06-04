#include <iostream>
/*
 * https://leetcode.com/problems/fizz-buzz-multithreaded/
 * You have the four functions:

printFizz that prints the word "Fizz" to the console,
printBuzz that prints the word "Buzz" to the console,
printFizzBuzz that prints the word "FizzBuzz" to the console, and
printNumber that prints a given integer to the console.
You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:

Thread A: calls fizz() that should output the word "Fizz".
Thread B: calls buzz() that should output the word "Buzz".
Thread C: calls fizzbuzz() that should output the word "FizzBuzz".
Thread D: calls number() that should only output the integers.
Modify the given class to output the series [1, 2, "Fizz", 4, "Buzz", ...] where the ith token (1-indexed) of the series is:

"FizzBuzz" if i is divisible by 3 and 5,
"Fizz" if i is divisible by 3 and not 5,
"Buzz" if i is divisible by 5 and not 3, or
i if i is not divisible by 3 or 5.
Implement the FizzBuzz class:

FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
void fizz(printFizz) Calls printFizz to output "Fizz".
void buzz(printBuzz) Calls printBuzz to output "Buzz".
void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "FizzBuzz".
void number(printNumber) Calls printnumber to output the numbers.

https://leetcode.com/problems/fizz-buzz-multithreaded/discuss/941826/C%2B%2B-Very-Simple-Solution-Using-3-Semaphores :comments
 */
/*
#include <semaphore.h>

class FizzBuzz {
private:
	int n;
	sem_t fizz_sem;
	sem_t buzz_sem;
	sem_t fizzbuzz_sem;
	sem_t num_sem;

public:
	FizzBuzz(int n) {
		this->n = n;
		sem_init(&fizz_sem, 0, 0);
		sem_init(&buzz_sem, 0, 0);
		sem_init(&fizzbuzz_sem, 0, 0);
		sem_init(&num_sem, 0, 0);
	}

	~FizzBuzz() {
		sem_destroy(&fizz_sem);
		sem_destroy(&buzz_sem);
		sem_destroy(&fizzbuzz_sem);
		sem_destroy(&num_sem);
	}

	void Fizz(function<void()> printFizz) {
		for(int i = 3; i <= n; i += 3) {
			if(i % 5) {
				sem_wait(&fizz_sem);
				printFizz();
				sem_post(&num_sem);
			}
		}
	}

	void Buzz(function<void()> printBuzz) {
		for(int i = 5; i <= n; i += 5) {
			if(i % 3) {
				sem_wait(&buzz_sem);
				printBuzz();
				sem_post(&num_sem);
			}
		}
	}

	void FizzBuzz(function<void()> printFizzBuzz) {
		for(int i = 15; i <= n; i += 15) {
			sem_wait(&fizzbuzz_sem);
			printFizzBuzz();
			sem_post(&num_sem);
		}
	}

	void number(function<void()> printNumber) {
		for(int i = 1; i <= n; i++) {
			if(i % 3 == 0) {
				if(i % 5 == 0) {
					sem_post(&fizzbuzz_sem);
				} else
					sem_post(&fizz_sem);
			} else if(i % 5 == 0) {
				sem_post(&buzz_sem);
			} else {
				printNumber(i);
				sem_post(&num_sem);
			}
			sem_wait(&num_sem);
		}
	}
};*/
