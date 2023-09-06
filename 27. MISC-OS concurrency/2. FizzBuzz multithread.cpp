// 1195. Fizz Buzz Multithreaded
// Medium

// You have the four functions:

// printFizz that prints the word "fizz" to the console,
// printBuzz that prints the word "buzz" to the console,
// printFizzBuzz that prints the word "fizzbuzz" to the console, and
// printNumber that prints a given integer to the console.
// You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:

// Thread A: calls fizz() that should output the word "fizz".
// Thread B: calls buzz() that should output the word "buzz".
// Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
// Thread D: calls number() that should only output the integers.
// Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...] where the ith token (1-indexed) of the series is:

// "fizzbuzz" if i is divisible by 3 and 5,
// "fizz" if i is divisible by 3 and not 5,
// "buzz" if i is divisible by 5 and not 3, or
// i if i is not divisible by 3 or 5.
// Implement the FizzBuzz class:

// FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
// void fizz(printFizz) Calls printFizz to output "fizz".
// void buzz(printBuzz) Calls printBuzz to output "buzz".
// void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
// void number(printNumber) Calls printnumber to output the numbers.
 

// Example 1:

// Input: n = 15
// Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
// Example 2:

// Input: n = 5
// Output: [1,2,"fizz",4,"buzz"]
 

// Constraints:

// 1 <= n <= 50




#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class FizzBuzz {
private:
    int n;              // The maximum number to print up to.
    int i;              // The current number to be processed.
    mutex m;            // Mutex for synchronization.
    condition_variable cv;  // Condition variable for signaling.

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;    // Initialize 'i' to 1, the starting number.
    }

    // This method is responsible for printing "Fizz" when the current number is divisible by 3.
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lock(m);  // Acquire the lock.

        while (i <= n) {
            // Wait until 'i' is less than or equal to 'n' and 'i' is not divisible by 3 or is divisible by 5.
            while ((i <= n) && ((i % 3 == 0) && (i % 5 != 0)) == 0) {
                cv.wait(lock);  // Wait for a signal to proceed.
            }

            if (i <= n) {
                printFizz();  // Execute the Fizz logic (e.g., print "Fizz").
                ++i;          // Move to the next number.
            }

            cv.notify_all();  // Notify all threads that a number has been processed.
        }
    }

    // This method is responsible for printing "Buzz" when the current number is divisible by 5.
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lock(m);

        while (i <= n) {
            while ((i <= n) && ((i % 5 == 0) && (i % 3 != 0)) == 0) {
                cv.wait(lock);
            }

            if (i <= n) {
                printBuzz();  // Execute the Buzz logic (e.g., print "Buzz").
                ++i;
            }

            cv.notify_all();
        }
    }

    // This method is responsible for printing "FizzBuzz" when the current number is divisible by both 3 and 5.
    void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lock(m);

        while (i <= n) {
            while ((i <= n) && ((i % 3 == 0) && (i % 5 == 0)) == 0) {
                cv.wait(lock);
            }

            if (i <= n) {
                printFizzBuzz();  // Execute the FizzBuzz logic (e.g., print "FizzBuzz").
                ++i;
            }

            cv.notify_all();
        }
    }

    // This method is responsible for printing a number when it doesn't meet any of the Fizz, Buzz, or FizzBuzz conditions.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);

        while (i <= n) {
            while ((i <= n) && ((i % 3 != 0) && (i % 5 != 0)) == 0) {
                cv.wait(lock);
            }

            if (i <= n) {
                printNumber(i);  // Execute the logic to print the current number.
                ++i;
            }

            cv.notify_all();
        }
    }
};

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