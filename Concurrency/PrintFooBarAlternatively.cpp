#include <iostream>
/*https://leetcode.com/problems/print-foobar-alternately/
 * Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads:

thread A will call foo(), while
thread B will call bar().
Modify the given program to output "foobar" n times.
Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.

https://leetcode.com/problems/print-foobar-alternately/discuss/941742/C%2B%2B-Super-Simple-Solution-Using-2-Semaphores : USED

https://leetcode.com/problems/print-foobar-alternately/discuss/949493/C%2B%2B-solution-using-mutex-%2B-CV-(w-explanation)
 */
/*#include<semaphore.h>

class FooBar {
private:
	int n;
	sem_t foo_sem;
	sem_t bar_sem;

public:
	FooBar(int n) {
		this->n = n;
		sem_init(&foo_sem, 0, 1);
		sem_init(&bar_sem, 0, 0);
	}

	~FooBar() {
		sem_destroy(&foo_sem);
		sem_destroy(&bar_sem);
	}

	void foo(function<void()> printFoo) {
		for(int i = 0; i < n; i++) {
			 // lock foo semaphore
			sem_wait(&foo_sem);// decrements foo_sem by 1

			printFoo; // printFoo() outputs "foo". Do not change or remove this line.

			 // unlock bar semaphore
			sem_post(&bar_sem); //tells bar_sem to increment value by 1
		}
	}

	void bar(function<void()> printBar) {
		for(int i = 0; i <  n; i++) {
			 // lock bar semaphore
			sem_wait(&bar_sem);// decrements bar_sem by 1

			printBar();// printBar() outputs "bar". Do not change or remove this line.

			 // unlock foo semaphore
			sem_post(&foo_sem);//tells foo_sem to increment value by 1
		}
	}
};
*/
