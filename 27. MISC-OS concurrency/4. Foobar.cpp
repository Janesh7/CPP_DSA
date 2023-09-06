// 1115. Print FooBar Alternately
// Medium

// Suppose you are given the following code:

// class FooBar {
//   public void foo() {
//     for (int i = 0; i < n; i++) {
//       print("foo");
//     }
//   }

//   public void bar() {
//     for (int i = 0; i < n; i++) {
//       print("bar");
//     }
//   }
// }
// The same instance of FooBar will be passed to two different threads:

// thread A will call foo(), while
// thread B will call bar().
// Modify the given program to output "foobar" n times.

 

// Example 1:

// Input: n = 1
// Output: "foobar"
// Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
// "foobar" is being output 1 time.
// Example 2:

// Input: n = 2
// Output: "foobarfoobar"
// Explanation: "foobar" is being output 2 times.
 

// Constraints:

// 1 <= n <= 1000


#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class FooBar {
private:
    int n; // Total number of times to print "foo" and "bar".
    mutex m; // Mutex for synchronization.
    condition_variable cv; // Condition variable for signaling.
    bool turn; // A boolean flag to indicate whose turn it is.

public:
    FooBar(int n) {
        this->n = n;
        turn = true; // Initialize the turn to 'true' for "foo" to start first.
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m); // Acquire a unique lock on the mutex.

            // While it's not "foo's" turn or we've already printed 'n' times, wait.
            while (!turn && i < n) {
                cv.wait(lock); // Release the lock and wait until signaled.
            }

            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();

            turn = false; // It's now "bar's" turn.
            cv.notify_all(); // Notify all waiting threads.
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m); // Acquire a unique lock on the mutex.

            // While it's not "bar's" turn or we've already printed 'n' times, wait.
            while (turn && i < n) {
                cv.wait(lock); // Release the lock and wait until signaled.
            }

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();

            turn = true; // It's now "foo's" turn.
            cv.notify_all(); // Notify all waiting threads.
        }
    }
};
