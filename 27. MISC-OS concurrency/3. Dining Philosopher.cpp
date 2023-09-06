// 1226. The Dining Philosophers
// Medium

// Five silent philosophers sit at a round table with bowls of spaghetti. Forks are placed between each pair of adjacent philosophers.

// Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right forks. Each fork can be held by only one philosopher and so a philosopher can use the fork only if it is not being used by another philosopher. After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others. A philosopher can take the fork on their right or the one on their left as they become available, but cannot start eating before getting both forks.

// Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed.

// Design a discipline of behaviour (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think.



// The problem statement and the image above are taken from wikipedia.org

 

// The philosophers' ids are numbered from 0 to 4 in a clockwise order. Implement the function void wantsToEat(philosopher, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork) where:

// philosopher is the id of the philosopher who wants to eat.
// pickLeftFork and pickRightFork are functions you can call to pick the corresponding forks of that philosopher.
// eat is a function you can call to let the philosopher eat once he has picked both forks.
// putLeftFork and putRightFork are functions you can call to put down the corresponding forks of that philosopher.
// The philosophers are assumed to be thinking as long as they are not asking to eat (the function is not being called with their number).
// Five threads, each representing a philosopher, will simultaneously use one object of your class to simulate the process. The function may be called for the same philosopher more than once, even before the last call ends.

 

// Example 1:

// Input: n = 1
// Output: [[4,2,1],[4,1,1],[0,1,1],[2,2,1],[2,1,1],[2,0,3],[2,1,2],[2,2,2],[4,0,3],[4,1,2],[0,2,1],[4,2,2],[3,2,1],[3,1,1],[0,0,3],[0,1,2],[0,2,2],[1,2,1],[1,1,1],[3,0,3],[3,1,2],[3,2,2],[1,0,3],[1,1,2],[1,2,2]]
// Explanation:
// n is the number of times each philosopher will call the function.
// The output array describes the calls you made to the functions controlling the forks and the eat function, its format is:
// output[i] = [a, b, c] (three integers)
// - a is the id of a philosopher.
// - b specifies the fork: {1 : left, 2 : right}.
// - c specifies the operation: {1 : pick, 2 : put, 3 : eat}.
 

// Constraints:

// 1 <= n <= 60


#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore {
private:
    int count;
    mutex mtx;
    condition_variable cv;

public:
    Semaphore(int n = 0) : count(n) { }

    // Set the initial count of the semaphore.
    void Set(int n) { count = n; }

    // Signal (increment) the semaphore count and notify one waiting thread.
    void Signal() {
        unique_lock<mutex> lck(mtx);
        ++count;
        cv.notify_one(); // Notify one waiting thread that the semaphore count has increased.
    }

    // Wait for the semaphore count to become greater than 0.
    void Wait() {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [&]() { return count > 0; }); // Wait until count is greater than 0.
        --count; // Decrement the count once the wait is over.
    }
};

class DiningPhilosophers {
private:
    mutex mtx[5]; // Mutexes representing forks, one for each philosopher.
    Semaphore sem; // Semaphore to limit the number of philosophers eating simultaneously.

public:
    DiningPhilosophers() { sem.Set(4); } // Initialize the semaphore with 4 spots available.

    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5; // Calculate the index of the philosopher's right neighbor.

        sem.Wait(); // Wait for a semaphore spot to become available (max 4 philosophers eating).

        unique_lock<mutex> lckLeft(mtx[left]); // Lock the left fork.
        unique_lock<mutex> lckRight(mtx[right]); // Lock the right fork.

        // Philosophers pick up their forks, eat, and put the forks down.
        pickLeftFork();
        pickRightFork();
        eat();
        putRightFork();
        putLeftFork();

        lckLeft.unlock(); // Unlock the left fork mutex.
        lckRight.unlock(); // Unlock the right fork mutex.

        sem.Signal(); // Signal that a philosopher has finished eating and released a spot.
    }
};
