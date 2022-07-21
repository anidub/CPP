#include <iostream>
#include <vector>
#include <mutex>
/*https://leetcode.com/problems/the-dining-philosophers/
 *
 * https://www.youtube.com/watch?v=91_RHE_U3t4 : question explained in first 4 mins
 * https://leetcode.com/problems/the-dining-philosophers/discuss/446842/c%2B%2B-mutex-only-(textbook-solution) : used
 * https://leetcode.com/problems/the-dining-philosophers/discuss/551030/C%2B%2B11-Clean-Solution-With-std%3A%3Acondition_variable-and-std%3A%3Amutex
 */
/*
class DiningPhilosopher{
int n;
vector<std::mutex> fork_locks;

public:
	DiningPhilosopher(int n) {
		this->n = n;
		vector<std::mutex> fork_locks(n);
	}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

    	int left_id = philosopher % n;
    	int right_id = (philosopher + 1) % n;

        if(philosopher % n == 1) {
            fork_locks[right_id].lock();
            fork_locks[left_id].lock();
            pickRightFork();
            pickLeftFork();
            eat();
            putLeftFork();
            putRightFork();
            fork_locks[right_id].unlock();
            fork_locks[left_id].unlock();
        } else {
            fork_locks[left_id].lock();
            fork_locks[right_id].lock();
            pickLeftFork();
            pickRightFork();
            eat();
            putLeftFork();
            putRightFork();
            fork_locks[left_id].unlock();
            fork_locks[right_id].unlock();
        }
    }

};
