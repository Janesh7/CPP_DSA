# concurrency

Certainly! Concurrency in C++ involves managing and coordinating multiple threads to perform tasks simultaneously. Below, I'll provide an overview of various data types, functions, and concepts related to concurrency in C++.

**1. `std::thread` Data Type:**
   - Usage: `std::thread` is used to create and manage threads in C++.
   - Explanation: It represents an individual thread of execution. You can create threads by instantiating objects of this class and passing a callable function (such as a function pointer or a lambda expression) to be executed concurrently.

   ```cpp
   // Creating a thread and starting it
   std::thread myThread(myFunction);
   ```

**2. Mutex (Mutual Exclusion) and `std::mutex` Data Type:**
   - Usage: Mutexes are used to provide exclusive access to shared resources, preventing data races.
   - Explanation: `std::mutex` is a C++ standard library class that provides basic mutex functionality. It is used to lock and unlock critical sections of code so that only one thread can access the protected resource at a time.

   ```cpp
   std::mutex myMutex;
   myMutex.lock();   // Acquire the lock
   // Critical section (protected code)
   myMutex.unlock(); // Release the lock
   ```

**3. `std::unique_lock` Data Type:**
   - Usage: `std::unique_lock` is a more flexible alternative to `std::lock_guard` for managing locks.
   - Explanation: It allows for conditional locking and unlocking of mutexes. You can lock and unlock a `std::unique_lock` multiple times and use it in conjunction with condition variables.

   ```cpp
   std::unique_lock<std::mutex> myLock(myMutex);
   myLock.lock();     // Acquire the lock
   // Critical section
   myLock.unlock();   // Release the lock
   ```

**4. Condition Variables and `std::condition_variable` Data Type:**
   - Usage: Condition variables are used for thread synchronization, allowing threads to wait for a specific condition to be met before proceeding.
   - Explanation: `std::condition_variable` is a C++ standard library class that provides a mechanism for threads to block until another thread signals them.

   ```cpp
   std::condition_variable myCondVar;
   myCondVar.wait(myLock);  // Wait until signaled
   myCondVar.notify_all();  // Signal all waiting threads
   ```

**5. `std::atomic` Data Type:**
   - Usage: `std::atomic` types ensure atomic (non-interruptible) operations on shared data.
   - Explanation: It's used to avoid data races when multiple threads access and modify the same variable. Operations on `std::atomic` variables are guaranteed to be atomic, eliminating the need for locks in many cases.

   ```cpp
   std::atomic<int> myAtomicInt;
   myAtomicInt.store(42, std::memory_order_relaxed);  // Store value atomically
   int value = myAtomicInt.load(std::memory_order_relaxed); // Load value atomically
   ```

**6. `std::async` Function:**
   - Usage: `std::async` is used to execute a function asynchronously and retrieve the result.
   - Explanation: It returns a `std::future` object that can be used to retrieve the result of the function when it completes. This is useful for parallelizing tasks.

   ```cpp
   std::future<int> result = std::async(std::launch::async, myFunction);
   int value = result.get(); // Get the result when ready
   ```

**7. `std::promise` and `std::future` Data Types:**
   - Usage: `std::promise` is used to set a value or exception to be retrieved by a `std::future`.
   - Explanation: `std::promise` allows one thread to set a value or exception that another thread can retrieve using a `std::future`.

   ```cpp
   std::promise<int> myPromise;
   std::future<int> myFuture = myPromise.get_future();
   myPromise.set_value(42); // Set the value
   int value = myFuture.get(); // Get the value
   ```

**8. `std::packaged_task` Data Type:**
   - Usage: `std::packaged_task` is used to package a function and its future result.
   - Explanation: It's a way to create a task that can be executed asynchronously, and its result can be retrieved through a `std::future`.

   ```cpp
   std::packaged_task<int()> myTask(myFunction);
   std::future<int> result = myTask.get_future();
   myTask(); // Execute the task
   int value = result.get(); // Get the result
   ```



# Q1 - Print in order


Explanation of Concurrency Concepts and C++ Functions/Data Types Used:

1. **mutex**: A mutex (short for "mutual exclusion") is used for ensuring exclusive access to shared resources. In this code, `mtx` is a mutex used to protect critical sections of code from simultaneous access by multiple threads.

2. **condition_variable**: A condition variable is used for thread synchronization. It allows threads to wait for a certain condition to be met before proceeding. In this code, `cv` is a condition variable used to signal when `count` changes.

3. **unique_lock**: `unique_lock` is a type of lock that provides more flexibility than `lock_guard`. It can be locked and unlocked multiple times and allows you to conditionally wait on a condition variable.

4. **function<void()>**: This is a function pointer or function wrapper. In this code, it's used as a parameter to pass three different functions (`printFirst`, `printSecond`, and `printThird`) that will be called at specific points in the program.


- **first()**: This function is intended to be run by the first thread. It takes a function `printFirst` as a parameter, which is a placeholder for the actual code that prints "first." It locks the mutex, calls `printFirst()`, updates `count` to 2, and signals waiting threads using `cv.notify_all()`.

- **second()**: This function is intended to be run by the second thread. It waits in a loop until `count` becomes 2, indicating that the `first()` function has completed. It then locks the mutex, calls `printSecond()`, updates `count` to 3, and signals waiting threads using `cv.notify_all()`.

- **third()**: This function is intended to be run by the third thread. It waits in a loop until `count` becomes 3, indicating that the `second()` function has completed. It then locks the mutex, calls `printThird()`, and completes.

Overall, this code ensures that the three functions (`first()`, `second()`, and `third()`) are executed in a specific order, even when running in separate threads. It demonstrates the use of mutexes and condition variables for thread synchronization in C++.


# Q2- FizzBuzz

**Explanation:**
- This code defines a class `FizzBuzz` that implements a multithreaded version of the FizzBuzz problem.
- The class constructor takes an integer `n` as input, representing the maximum number to print up to.
- The class has four methods (`fizz`, `buzz`, `fizzbuzz`, and `number`), each responsible for printing specific outputs based on certain conditions.
- A mutex (`m`) is used to ensure exclusive access to shared variables and to control the flow of execution among threads.
- A condition variable (`cv`) is used for thread synchronization and signaling.

The four methods (`fizz`, `buzz`, `fizzbuzz`, and `number`) follow a similar structure:
1. They enter a critical section protected by the mutex (`unique_lock`).
2. Within the critical section, they use a `while` loop to check specific conditions and, if necessary, wait for a signal (`cv.wait(lock)`) before proceeding.
3. When the conditions are met, the respective logic (e.g., printing "Fizz") is executed, and the current number (`i`) is updated.
4. A signal is sent to notify other waiting threads (`cv.notify_all()`).

The `number` method serves as the default case and prints the current number if it doesn't meet the conditions for Fizz, Buzz, or FizzBuzz.

This code allows multiple threads to work concurrently to print Fizz, Buzz, FizzBuzz, and numbers from 1 to `n` based on their divisibility criteria.


# Q3 - Dining Philosopher problem

This is a typical textbook question for operation system courses although it appears to be poorly defined in first glance, it was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise.
You will not see this question in an interview but understanding it is the fundamental of cracking other multi-threading questions.

**Solution 0**: Let philosophers eat one by one
LeetCode accepts this solution but it is generally WRONG. Why?

Using raw mutex is very unprofessional, we don’t know how pickLeftFork() pickRightFork() eat() putLeftFork() putRightFork() are implemented, if any of them throws exception, our mutex will never be unlocked! Always wrap mutex with lock_guard or unique_lock

This approach destroys advantage of multithreading, only one thread can be executed at a time.

```cpp
class DiningPhilosophers {
private:
    mutex mtx; // 5 philosophers share 1 single mutex
public:
    DiningPhilosophers() { }
    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        mtx.lock();
        pickLeftFork(); pickRightFork(); eat(); putLeftFork(); putRightFork();
        mtx.unlock();
    }
};
```
**Solution 1:** Lock the table then pick up both forks together
Very similar to Solution 0, but we release locks immediately after picking up both forks, then eat() method can take as long as it requires without blocking other threads.
However isn't a nice approach either, it has great performance impact as table size grows, imagin if we have 50 threads try to eat(), every single one need to lock()/unlock() the table for picking up both forks while other 49 threads will have to wait().

```cpp
class DiningPhilosophers {
private:
    mutex mtxFork[5];
    mutex mtxTable;
    
public:
    DiningPhilosophers() { }
    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
		
        unique_lock<mutex> lckTable(mtxTable);
        unique_lock<mutex> lckForkLeft(mtxFork[left]);
        unique_lock<mutex> lckForkRight(mtxFork[right]);
        lckTable.unlock(); // after locking both forks, we can safely unlock table
        
        pickLeftFork(); pickRightFork(); eat(); putRightFork(); putLeftFork();
        // locks will be automatically released due to unique_lock RAII design
    }
};
```
**Solution 2:** Change forks picking order
Let even philosophers pick up left forks before right forks.
Let odd philosophers pick up right forks before left forks.
Before diving into final answer, lets see an easy to understand solution with raw mutex

```cpp
class DiningPhilosophers {
private:
    mutex mtx[5];
    
public:
    DiningPhilosophers() { }
    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        if(philosopher % 2 == 0){
            mtx[right].lock(); // lock right before left
            mtx[left].lock();
            pickLeftFork(); pickRightFork();
        }
		else{
            mtx[left].lock(); // lock left before right
            mtx[right].lock();
            pickLeftFork(); pickRightFork();
        }
        
        eat(); putRightFork(); putLeftFork();
        mtx[left].unlock();
        mtx[right].unlock();
    }
};
```
Then lets wrap up raw mutex with unique_lock.
Be aware that unique_lock needs to be put outside of if statement, otherwise its scoop will be limited in if statement only

```cpp
class DiningPhilosophers {
private:
    mutex mtx[5];
    
public:
    DiningPhilosophers() { }
    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        unique_lock<mutex> lck1(mtx[left], defer_lock); // defer_lock: init lck1 without locking mtx
        unique_lock<mutex> lck2(mtx[right], defer_lock);
        
        if(philosopher % 2 == 0){
            lck1.lock(); // do NOT use std::lock(lck1, lck2)
            lck2.lock();
            pickLeftFork(); pickRightFork();
        }
		else{
            lck2.lock();
            lck1.lock();
            pickLeftFork(); pickRightFork();
        }
        eat(); putRightFork(); putLeftFork();
        // lck1 & lck2 are auto released after this line
    }
};
```

**Solution 3:** Limit 4 philosophers to eat at same time
Use Semaphore to limit max of 4 philosophers can eat at same time, at least one philosopher will get both forks.

```cpp
class Semaphore {
private:
	int count;
    mutex mtx;
    condition_variable cv;
	
public:
    Semaphore(int n = 0) : count(n) { }
    void Set(int n) { count = n; }
    void Signal() {
        unique_lock<mutex> lck(mtx);
        ++count;
        cv.notify_one();
    }
    void Wait() {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [&](){ return count > 0; }); // standard format of wait() lambda expression
        --count;
    }
};

class DiningPhilosophers {
private:
    mutex mtx[5];
    Semaphore sem;
    
public:
    DiningPhilosophers() { sem.Set(4); }
    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        sem.Wait(); // if there are 4 philosophers eating, thread will wait here

        unique_lock<mutex> lckLeft(mtx[left]);
        unique_lock<mutex> lckRight(mtx[right]);
        
        pickLeftFork(); pickRightFork(); eat(); putRightFork(); putLeftFork();
        
        lckLeft.unlock();
        lckRight.unlock();

        sem.Signal(); // finish eating, release 1 spot for other philosophers
    }
};
```
Q> why 4 philosopher is allowed while at max only 2 can eat?

This solution means that at most 4 philosophers can enter the Eat state.
With at most 4 philosophers can entering the Eat state, we can ensure that at least one of them can acquire both the left and right fork, successfully eat and release forks.
Setting 4 philosophers is to avoid the cases that 5 philosophers pick up their left fork (or right fork) at the same time and cause deadlock.

Q> why bother writing our own Semaphore class? Why don't we use #include "semaphore.h" like other solutions?

Because semaphore.h is only available for Linux, while CreateSemaphore() is only available for windows, in real life writing following code breaks portability and readability.

```
#ifdef UNIX
	// code for Linux
#else
	// code for Windows
#endif
```

Is there a way to solve above problem without writing our own Semaphore class?
Yes, we can use c++ 20 <semaphore> header, sadly LeetCode seems don't have c++ 20 support so following code won't compile :(

```cpp
#include <thread>
#include <chrono>
#include <semaphore> // ERROR: compiler unable to find this header

class DiningPhilosophers {
private:
    mutex mtx[5];
    counting_semaphore<4> sem(4);
    
public:
    DiningPhilosophers() { }
    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        sem.acquire(); // if there are 4 philosophers eating, thread will wait here

        unique_lock<mutex> lckLeft(mtx[left]);
        unique_lock<mutex> lckRight(mtx[right]);
        
        pickLeftFork(); pickRightFork(); eat(); putRightFork(); putLeftFork();
        
        lckLeft.unlock();
        lckRight.unlock();

        sem.release(); // finish eating, release 1 spot for other philosophers
    }
};
```

Last Solution for fun: ON LINER
```cpp
class DiningPhilosophers {
private:
    mutex mtx[5];
public:
    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        scoped_lock lck(mtx[philosopher], mtx[(philosopher + 1) % 5]);
        pickLeftFork(); pickRightFork(); eat(); putLeftFork(); putRightFork();
    }
};
```
# Q4 Foobar

**Explanation:**

1. **FooBar Class:**
   - The `FooBar` class models the problem of printing "foo" and "bar" alternately 'n' times.
   - It uses a `mutex` (`m`) for synchronization and a `condition_variable` (`cv`) for signaling.
   - The `turn` boolean flag is used to keep track of whose turn it is initially.

2. **Constructor (`FooBar(int n)`):**
   - Initializes the `FooBar` object with the total number of times to print "foo" and "bar" (`n`).
   - Sets the initial turn to `true` (representing "foo") since "foo" starts first.

3. **`foo` Method:**
   - This method prints "foo" 'n' times.
   - It uses a `unique_lock` to lock the mutex.
   - Inside a loop, it checks whether it's "foo's" turn and if it has already printed 'n' times.
   - If it's not "foo's" turn or it has printed 'n' times, it releases the lock and waits on the condition variable (`cv`).
   - When it's "foo's" turn, it calls `printFoo()`, updates the turn to "bar," and notifies all waiting threads to potentially switch to "bar's" turn.

4. **`bar` Method:**
   - This method prints "bar" 'n' times.
   - Similar to `foo`, it uses a `unique_lock`, checks for "bar's" turn and the print count, and waits if needed.
   - When it's "bar's" turn, it calls `printBar()`, updates the turn to "foo," and notifies all waiting threads to potentially switch to "foo's" turn.



# Q5 Odd even zero

**Explanation:**

1. **ZeroEvenOdd Class:**
   - The `ZeroEvenOdd` class models the problem of printing numbers alternatively: "zero," even numbers, and odd numbers.
   - It uses a `mutex` (`m`) for synchronization and a `condition_variable` (`cv`) for signaling.
   - The `count` variable keeps track of the current state: 0 for "zero," 1 for odd, and 2 for even.

2. **Constructor (`ZeroEvenOdd(int n)`):**
   - Initializes the `ZeroEvenOdd` object with the total number up to which numbers should be printed (`n`).

3. **`zero` Method:**
   - This method prints "zero" 'n' times.
   - It uses a `unique_lock` to lock the mutex.
   - Inside a loop, it checks whether it's "zero's" turn (count is 0).
   - If it's not "zero's" turn, it releases the lock and waits on the condition variable (`cv`).
   - When it's "zero's" turn, it calls `printNumber(0)`, updates the state to even or odd, and notifies all waiting threads to potentially switch to an even or odd state.

4. **`even` and `odd` Methods:**
   - These methods print even and odd numbers 'n' times, respectively, following a similar pattern to `zero`.
   - They wait for their respective turns (count is 2 for even and 1 for odd), print the number, set the state back to 0 (zero's turn), and notify all waiting threads.


# Q6 H2O


**Explanation:**

1. **H2O Class:**
   - The `H2O` class models the problem of synchronizing the release of hydrogen (H) and oxygen (O) atoms to form water molecules.
   - It uses a `mutex` (`m`) for synchronization and a `condition_variable` (`cv`) for signaling.
   - The `turn` variable keeps track of the current state, with 0 meaning no atoms released, 1 meaning one hydrogen atom released, and 2 meaning both hydrogen atoms released (ready for oxygen).

2. **Constructor (`H2O()`):**
   - Initializes the `H2O` object with the state set to 0 (no atoms released initially).

3. **`hydrogen` Method:**
   - This method represents the release of a hydrogen atom.
   - It uses a `unique_lock` to lock the mutex.
   - Inside a loop, it checks whether it's the hydrogen's turn (turn is 2 for water molecule).
   - If it's not the hydrogen's turn, it releases the lock and waits on the condition variable (`cv`).
   - When it's the hydrogen's turn, it calls `releaseHydrogen()`, increments the turn (indicating one hydrogen atom is released), and notifies all waiting threads (in case oxygen is waiting).

4. **`oxygen` Method:**
   - This method represents the release of an oxygen atom.
   - It follows a similar pattern to `hydrogen` but waits for both hydrogen atoms to be released (turn is less than 2) before releasing oxygen. Once released, it resets the state to 0 (no atoms released) and notifies all waiting threads (in case hydrogen is waiting).

