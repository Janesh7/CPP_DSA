// 1114. Print in Order
// Easy
// 1.4K
// 194
// Companies
// Suppose we have a class:

// public class Foo {
//   public void first() { print("first"); }
//   public void second() { print("second"); }
//   public void third() { print("third"); }
// }
// The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

// Note:

// We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: "firstsecondthird"
// Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
// Example 2:

// Input: nums = [1,3,2]
// Output: "firstsecondthird"
// Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
 

// Constraints:

// nums is a permutation of [1, 2, 3].


Sure, let's break down the provided code and explain the concurrency-related concepts, functions, and data types used. I'll also add comments to clarify each part of the code.

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class Foo {
public:
    int count = 0;
    mutex mtx;                      // Mutex for synchronization
    condition_variable cv;          // Condition variable for signaling

    Foo() {
        count = 1;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(mtx);    // Locks the mutex in a scoped manner
        // printFirst() outputs "first". Do not change or remove this line.

        printFirst();                   // Call the provided printFirst function
        count = 2;                      // Set the count to 2 to signal completion of the first function
        cv.notify_all();                // Notify waiting threads that 'count' has changed
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);    // Locks the mutex in a scoped manner
        // printSecond() outputs "second". Do not change or remove this line.
        
        while (count != 2)
            cv.wait(lck);               // Wait until 'count' becomes 2
        printSecond();                  // Call the provided printSecond function
        count = 3;                      // Set the count to 3 to signal completion of the second function
        cv.notify_all();                // Notify waiting threads that 'count' has changed
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);    // Locks the mutex in a scoped manner
        // printThird() outputs "third". Do not change or remove this line.

        while (count != 3)
            cv.wait(lck);               // Wait until 'count' becomes 3
        printThird();                   // Call the provided printThird function
    }
};
```

// 1. `mutex`: A mutex (`mtx`) is a synchronization primitive used to protect shared data from concurrent access. In this code, it's used to protect the `count` variable and ensure that multiple threads can access it safely.

// 2. `condition_variable`: A condition variable (`cv`) is a synchronization primitive that allows threads to wait for a certain condition to be met before proceeding. In this code, it's used to signal and wait for the completion of each step.

// 3. `unique_lock`: `unique_lock` is a type of lock that provides more flexibility than `lock_guard`. It allows locking and unlocking a mutex at different points in the code.

// 4. `count`: This integer variable keeps track of the current step in the sequence of execution. It is initially set to 1 in the constructor.

// 5. `first()`, `second()`, and `third()`: These are member functions of the `Foo` class. They represent three different steps that need to be executed in a specific order.

// 6. `printFirst()`, `printSecond()`, and `printThird()`: These are functions that output the respective strings "first," "second," and "third." They are placeholders for the actual logic you want to execute in each step.

// 7. `notify_all()`: This method notifies all waiting threads that the condition specified by the condition variable (`cv`) has been met, allowing them to proceed.

// 8. `wait()`: This method causes the current thread to wait until the condition specified by the condition variable (`cv`) is met. It also releases the lock on the associated mutex (`mtx`) while waiting and reacquires it when the condition is met.


// Now, let's explain the methods:

// - **first()**: This function is intended to be run by the first thread. It takes a function `printFirst` as a parameter, which is a placeholder for the actual code that prints "first." It locks the mutex, calls `printFirst()`, updates `count` to 2, and signals waiting threads using `cv.notify_all()`.

// - **second()**: This function is intended to be run by the second thread. It waits in a loop until `count` becomes 2, indicating that the `first()` function has completed. It then locks the mutex, calls `printSecond()`, updates `count` to 3, and signals waiting threads using `cv.notify_all()`.

// - **third()**: This function is intended to be run by the third thread. It waits in a loop until `count` becomes 3, indicating that the `second()` function has completed. It then locks the mutex, calls `printThird()`, and completes.

// Overall, this code ensures that the three functions (`first()`, `second()`, and `third()`) are executed in a specific order, even when running in separate threads. It demonstrates the use of mutexes and condition variables for thread synchronization in C++.