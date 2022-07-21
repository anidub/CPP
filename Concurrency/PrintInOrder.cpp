#include <iostream>
/*https://leetcode.com/problems/print-in-order/
 * Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(),
and thread C will call third().
Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

Note:

We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply
the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.
Input: nums = [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(),
 thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output

 https://leetcode.com/problems/print-in-order/solution/
 */
/*#include<semaphore.h>

using namespace std;

class Foo {
protected:
	sem_t firstJobDone;
	sem_t secondJobDone;

public:
	Foo() {
		sem_init(&firstJobDone, 0, 0);
		sem_init(&secondJobDone, 0, 0);
	}

	void first(function<void()> printFirst) {
		printFirst();
		sem_post(&firstJobDone);
	}

	void second(function<void>() printSecond) {
		sem_wait(&firstJobDone);
		printSecond();
		sem_post(&secondJobDone);
	}

	void third(function<void()> printThird) {
		sem_wait(&secondJobDone);
		printThird();
	}
};*/
