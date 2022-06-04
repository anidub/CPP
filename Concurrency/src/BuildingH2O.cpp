#include <iostream>
/*https://leetcode.com/problems/building-h2o/
 * There are two kinds of threads: oxygen and hydrogen. Your goal is to group these threads to form water molecules.

There is a barrier where each thread has to wait until a complete molecule can be formed. Hydrogen and oxygen threads will be
 given releaseHydrogen and releaseOxygen methods respectively, which will allow them to pass the barrier. These threads should pass
  the barrier in groups of three, and they must immediately bond with each other to form a water molecule. You must guarantee that
  all the threads from one molecule bond before any other threads from the next molecule do.

In other words:

If an oxygen thread arrives at the barrier when no hydrogen threads are present, it must wait for two hydrogen threads.
If a hydrogen thread arrives at the barrier when no other threads are present, it must wait for an oxygen thread and another hydrogen thread.
We do not have to worry about matching the threads up explicitly; the threads do not necessarily know which other
threads they are paired up with. The key is that threads pass the barriers in complete sets; thus, if we examine the sequence of
 threads that bind and divide them into groups of three, each group should contain one oxygen and two hydrogen threads.

Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.
Input: water = "HOH"
Output: "HHO"
Explanation: "HOH" and "OHH" are also valid answers.
 *
 * https://leetcode.com/problems/building-h2o/discuss/941812/C%2B%2B-Easy-and-Simple-Solution-Using-Semaphores%2BMutex
 */
/*
#include<semaphore.h>

class BuildingH2O {
private:
	int h = 0;
	sem_t h_sem;
	sem_t o_sem;
	pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

public:
	BuildingH2O() {
		sem_init(&h_sem, 0, 1);
		sem_init(&o_sem, 0, 0;
	}

	void hydrogen(function<void()> releaseHydrogen) {
		sem_wait(&h_sem);

		 // Lock this - '++' is a critical code
		pthread_mutex_lock(&mtx);
		h++;
		pthread_mutex_unlock(&mtx);

		releaseHydrogen();
		if(h % 2 == 0)
			sem_post(&o_sem);
		else
			sem_post(&h_sem);
	}

	void oxygen(function<void()> relaseOxygen) {
		sem_wait(&o_sem);
		releaseOxygen();
		sem_post(&h_sem);
	}
};*/
